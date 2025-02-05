package main

import (
	"crypto/aes"
	"crypto/cipher"
	"crypto/rand"
	"encoding/base64"
	"encoding/json"
	"fmt"
	"golang.org/x/crypto/bcrypt"
	"io"
	"io/ioutil"
)

type Vault struct {
	MainPassword string   `json:"mp"`
	Name         string   `json:"name"`
	Passwords    []string `json:"passwords"`
}

type Valuts []Vault

var valuts Valuts
var keys = "thisisasecretkey"

func loadFromFile(filename string) error {
	data, err := ioutil.ReadFile(filename)
	if err != nil {
		return err
	}
	err = json.Unmarshal(data, &valuts)
	if err != nil {
		return err
	}
	return nil
}

// /////////////////////////////////////////////////////////////////////////NEED TO LEARN IT MORE\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
func encryptAES(plainText, key string) (string, error) {
	block, err := aes.NewCipher([]byte(key))
	if err != nil {
		return "", err
	}

	cipherText := make([]byte, aes.BlockSize+len(plainText))
	iv := cipherText[:aes.BlockSize]
	if _, err := io.ReadFull(rand.Reader, iv); err != nil {
		return "", err
	}

	stream := cipher.NewCFBEncrypter(block, iv)
	stream.XORKeyStream(cipherText[aes.BlockSize:], []byte(plainText))

	return base64.StdEncoding.EncodeToString(cipherText), nil
}

func decryptAES(encryptedText, key string) (string, error) {
	block, err := aes.NewCipher([]byte(key))
	if err != nil {
		return "", err
	}

	cipherText, err := base64.StdEncoding.DecodeString(encryptedText)
	if err != nil {
		return "", err
	}

	if len(cipherText) < aes.BlockSize {
		return "", fmt.Errorf("ciphertext too short")
	}

	iv := cipherText[:aes.BlockSize]
	cipherText = cipherText[aes.BlockSize:]

	stream := cipher.NewCFBDecrypter(block, iv)
	stream.XORKeyStream(cipherText, cipherText)

	return string(cipherText), nil
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

func Create_valut() {
	var namee, MainPassword string
	fmt.Print("Enter vault name: ")
	fmt.Scanln(&namee)
	fmt.Print("Enter main password: ")
	fmt.Scanln(&MainPassword)

	hashedBytes, err := bcrypt.GenerateFromPassword([]byte(MainPassword), bcrypt.DefaultCost)
	if err != nil {
		fmt.Println("Error hashing password:", err)
		return
	}

	newVault := Vault{
		MainPassword: string(hashedBytes),
		Name:         namee,
		Passwords:    []string{},
	}

	valuts = append(valuts, newVault)
	err = saveToFile("database.json", valuts)
	if err != nil {
		fmt.Println("Error saving to file:", err)
		return
	}

	fmt.Println("Vault created and saved")
}

func saveToFile(filename string, valuts Valuts) error {
	data, err := json.MarshalIndent(valuts, "", "  ")
	if err != nil {
		return err
	}
	return ioutil.WriteFile(filename, data, 0644)
}

func display_valut() {
	fmt.Println("CHOOSE YOUR VAULT: Choose by index")
	var in int
	var pass string

	for i, v := range valuts {
		fmt.Printf("%d: %s\n", i, v.Name)
	}
	fmt.Scanln(&in)

	fmt.Println("ENTER THE PASSWORD TO GET YOUR SAVED PASSWORDS")
	fmt.Scanln(&pass)

	if err := bcrypt.CompareHashAndPassword([]byte(valuts[in].MainPassword), []byte(pass)); err == nil {
		fmt.Println("Access Granted! Your saved passwords:")
		for j, f := range valuts[in].Passwords {
			decryptedPass, _ := decryptAES(f, keys)
			fmt.Printf("%d: %s\n", j, decryptedPass)
		}
	} else {
		fmt.Println("Incorrect password. Access denied.")
	}
}

func add_pass() {
	fmt.Println("CHOOSE YOUR VAULT: Choose by index")
	var in int
	var pass, newpass string

	for i, v := range valuts {
		fmt.Printf("%d: %s\n", i, v.Name)
	}
	fmt.Scanln(&in)

	fmt.Println("ENTER THE PASSWORD TO GET ACCESS TO VAULT")
	fmt.Scanln(&pass)

	if err := bcrypt.CompareHashAndPassword([]byte(valuts[in].MainPassword), []byte(pass)); err == nil {
		fmt.Println("Access Granted! Enter the new password to add:")
		fmt.Scanln(&newpass)
		encrypass, err := encryptAES(newpass, keys)
		if err != nil {
			fmt.Println("Error encrypting password:", err)
			return
		}
		valuts[in].Passwords = append(valuts[in].Passwords, encrypass)
		err = saveToFile("database.json", valuts)
		if err != nil {
			fmt.Println("Error saving to file:", err)
			return
		}
		fmt.Println("New password added successfully!")
	} else {
		fmt.Println("Incorrect password. Unable to add new password.")
	}
}

func main() {
	err := loadFromFile("database.json")
	if err != nil {
		fmt.Println("Error loading from file:", err)
	}

	fmt.Println("WELCOME TO MURAGESH'S PASSWORD MANAGER")
	fmt.Println("WHAT DO YOU WANT TO DO: choose any one index")
	fmt.Println("1 : ACCESS TO YOUR VAULT")
	fmt.Println("2 : ADDING A NEW PASSWORD")
	fmt.Println("3 : ADDING A NEW VAULT")
	var inde int
	fmt.Scanln(&inde)

	if inde == 1 {
		display_valut()
	} else if inde == 2 {
		add_pass()
	} else if inde == 3 {
		Create_valut()
	} else {
		fmt.Println("Invalid option.SORRY")
	}
}
