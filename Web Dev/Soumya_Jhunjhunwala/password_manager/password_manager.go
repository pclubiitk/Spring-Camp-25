package main

import (
	"bufio"
	"crypto/aes"
	"crypto/cipher"
	"crypto/rand"
	"crypto/sha256"
	"encoding/json"
	"errors"
	"fmt"
	"os"
	"strings"

	"golang.org/x/crypto/pbkdf2"
)

type record struct {
	Name     string `json:"name"`
	Username string `json:"username"`
	Password string `json:"password"`
}

type vault struct {
	Records []record `json:"records"`
}

type encryptedVault struct {
	Salt       []byte `json:"salt"`
	Iterations int    `json:"iterations"`
	Nonce      []byte `json:"nonce"`
	Ciphertext []byte `json:"ciphertext"`
}

func CreateVault(vaultName, masterPassword string) error {
	if _, err := os.Stat(vaultName + ".vault"); err == nil {
		return errors.New("vault already exists")
	}

	salt := make([]byte, 32)
	if _, err := rand.Read(salt); err != nil {
		return err
	}

	iterations := 100000
	key := pbkdf2.Key([]byte(masterPassword), salt, iterations, 32, sha256.New)

	vault := vault{Records: []record{}}
	vaultJSON, err := json.Marshal(vault)
	if err != nil {
		return err
	}

	nonce := make([]byte, 12)
	if _, err := rand.Read(nonce); err != nil {
		return err
	}

	block, err := aes.NewCipher(key)
	if err != nil {
		return err
	}

	aesgcm, err := cipher.NewGCM(block)
	if err != nil {
		return err
	}

	ciphertext := aesgcm.Seal(nil, nonce, vaultJSON, nil)

	encryptedVault := encryptedVault{
		Salt:       salt,
		Iterations: iterations,
		Nonce:      nonce,
		Ciphertext: ciphertext,
	}

	encryptedVaultJSON, err := json.Marshal(encryptedVault)
	if err != nil {
		return err
	}

	return os.WriteFile(vaultName+".vault", encryptedVaultJSON, 0600)
}

func LoadVault(vaultName, masterPassword string) (*vault, []byte, error) {
	data, err := os.ReadFile(vaultName + ".vault")
	if err != nil {
		return nil, nil, err
	}

	var encryptedVault encryptedVault
	if err := json.Unmarshal(data, &encryptedVault); err != nil {
		return nil, nil, err
	}

	key := pbkdf2.Key([]byte(masterPassword), encryptedVault.Salt, encryptedVault.Iterations, 32, sha256.New)

	block, err := aes.NewCipher(key)
	if err != nil {
		return nil, nil, err
	}

	aesgcm, err := cipher.NewGCM(block)
	if err != nil {
		return nil, nil, err
	}

	plaintext, err := aesgcm.Open(nil, encryptedVault.Nonce, encryptedVault.Ciphertext, nil)
	if err != nil {
		return nil, nil, err
	}

	var vault vault
	if err := json.Unmarshal(plaintext, &vault); err != nil {
		return nil, nil, err
	}

	return &vault, key, nil
}

func SaveVault(vaultName string, vault *vault, key []byte) error {
	vaultJSON, err := json.Marshal(vault)
	if err != nil {
		return err
	}

	nonce := make([]byte, 12)
	if _, err := rand.Read(nonce); err != nil {
		return err
	}

	block, err := aes.NewCipher(key)
	if err != nil {
		return err
	}

	aesgcm, err := cipher.NewGCM(block)
	if err != nil {
		return err
	}

	ciphertext := aesgcm.Seal(nil, nonce, vaultJSON, nil)

	data, err := os.ReadFile(vaultName + ".vault")
	if err != nil {
		return err
	}

	var encryptedVault encryptedVault
	if err := json.Unmarshal(data, &encryptedVault); err != nil {
		return err
	}

	encryptedVault.Nonce = nonce
	encryptedVault.Ciphertext = ciphertext

	encryptedVaultJSON, err := json.Marshal(encryptedVault)
	if err != nil {
		return err
	}

	return os.WriteFile(vaultName+".vault", encryptedVaultJSON, 0600)
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	var currentVault *vault
	var currentVaultName string
	var currentVaultKey []byte

	fmt.Println("Welcome to CC Password Manager")

	for {
		fmt.Println("\nOptions:")
		fmt.Println("1. Create new vault")
		fmt.Println("2. Sign in to vault")
		fmt.Println("3. Add password record")
		fmt.Println("4. Retrieve password record")
		fmt.Println("q. Quit")
		fmt.Print("Enter choice: ")

		input, _ := reader.ReadString('\n')
		choice := strings.TrimSpace(input)

		switch choice {
		case "1":
			fmt.Print("Enter vault name: ")
			name, _ := reader.ReadString('\n')
			name = strings.TrimSpace(name)

			fmt.Print("Enter master password: ")
			password, _ := reader.ReadString('\n')
			password = strings.TrimSpace(password)

			fmt.Print("Confirm master password: ")
			confirm, _ := reader.ReadString('\n')
			confirm = strings.TrimSpace(confirm)

			if password != confirm {
				fmt.Println("Error: Passwords do not match")
				continue
			}

			if err := CreateVault(name, password); err != nil {
				fmt.Println("Error creating vault:", err)
			} else {
				fmt.Println("Vault created successfully")
			}

		case "2":
			fmt.Print("Enter vault name: ")
			name, _ := reader.ReadString('\n')
			name = strings.TrimSpace(name)

			fmt.Print("Enter master password: ")
			password, _ := reader.ReadString('\n')
			password = strings.TrimSpace(password)

			vault, key, err := LoadVault(name, password)
			if err != nil {
				fmt.Println("Error signing in:", err)
			} else {
				currentVault = vault
				currentVaultName = name
				currentVaultKey = key
				fmt.Println("Successfully signed in")
			}

		case "3":
			if currentVault == nil {
				fmt.Println("Error: Not signed in to any vault");
				break;
			}

			fmt.Print("Enter record name: ")
			name, _ := reader.ReadString('\n')
			name = strings.TrimSpace(name)

			fmt.Print("Enter username: ")
			username, _ := reader.ReadString('\n')
			username = strings.TrimSpace(username)

			fmt.Print("Enter password: ")
			password, _ := reader.ReadString('\n')
			password = strings.TrimSpace(password)

			currentVault.Records = append(currentVault.Records, record{
				Name:     name,
				Username: username,
				Password: password,
			})

			if err := SaveVault(currentVaultName, currentVault, currentVaultKey); err != nil {
				fmt.Println("Error saving record:", err)
			} else {
				fmt.Println("Record added successfully")
			}

		case "4":
			if currentVault == nil {
				fmt.Println("Error: Not signed in to any vault")
				break
			}

			fmt.Print("Enter record name: ")
			name, _ := reader.ReadString('\n')
			name = strings.TrimSpace(name)

			for _, record := range currentVault.Records {
				if record.Name == name {
					fmt.Printf("\nRecord found:\nUsername: %s\nPassword: %s\n", record.Username, record.Password)
					break
				}
			}

		case "q", "quit":
			fmt.Println("Exiting...")
			return

		default:
			fmt.Println("Invalid choice")
		}
	}
}