package utils

import (
	"encoding/json"
	"fmt"
	"os"
	"passwordManager/EncryptionDecryption"
)

type myData struct {
	Password string `json:"password"`
	Platform string `json:"platform"`
	Username string `json:"username"`
}

func CreateVault(vaultName string) {
	filePath := "./Vaults/" + vaultName + ".json"
	
	// Create file
	file, err := os.Create(filePath)
	if err != nil {
		fmt.Println("Error creating file:", err)
		return
	}
	defer file.Close()

	// Write empty JSON array
	var emptyArray []myData
	jsonData, _ := json.MarshalIndent(emptyArray, "", "    ")
	file.Write(jsonData)

	fmt.Println("New vault created:", vaultName)
}

func OpenVault(vaultName, username, MY_SECRET_KEY string) {
	filePath := "./Vaults/" + vaultName + ".json"

	// Check if vault exists
	_, errStat := os.Stat(filePath)
	if os.IsNotExist(errStat) {
		fmt.Println("Vault does not exist, please create it first")
		return
	}

	// Read file
	data, errRead := os.ReadFile(filePath)
	if errRead != nil {
		fmt.Println("Error reading file:", errRead)
		return
	}

	// Unmarshal JSON
	var dataArray []myData
	errUnmarshal := json.Unmarshal(data, &dataArray)
	if errUnmarshal != nil {
		fmt.Println("Error unmarshaling JSON:", errUnmarshal)
		return
	}

	// Filter data
	var arrayToShow []myData
	for _, item := range dataArray {
		if item.Username == username {
			passwordToShow, errDecrypt := EncryptionDecryption.Decrypt(item.Password, MY_SECRET_KEY)
			if errDecrypt != nil {
				fmt.Println("Decryption error:", errDecrypt)
				break
			}
			arrayToShow = append(arrayToShow, myData{
				Password: passwordToShow,
				Platform: item.Platform,
				Username: item.Username,
			})
		}
	}
	bytesBro,errr:=json.Marshal(arrayToShow)
	if errr!=nil{
		fmt.Println(errr)
	}
	fmt.Println("Vault data:", string(bytesBro))
}

func AddPasswordToVault(vaultName, password, platform, username, MY_SECRET_KEY string) {
	filePath := "./Vaults/" + vaultName + ".json"

	// Check if vault exists
	_, errStat := os.Stat(filePath)
	if os.IsNotExist(errStat) {
		fmt.Println("Vault does not exist, please create it first")
		return
	}

	// Read file
	oldData, errRead := os.ReadFile(filePath)
	if errRead != nil {
		fmt.Println("Error reading file:", errRead)
		return
	}

	// Unmarshal JSON
	var dataArray []myData
	errUnmarshal := json.Unmarshal(oldData, &dataArray)
	if errUnmarshal != nil {
		fmt.Println("Error unmarshaling JSON:", errUnmarshal)
		return
	}

	// Encrypt password
	passwordToStore, errEncrypt := EncryptionDecryption.Encrypt(password, MY_SECRET_KEY)
	if errEncrypt != nil {
		fmt.Println("Error encrypting password:", errEncrypt)
		return
	}

	// Add new entry
	newData := myData{
		Password: passwordToStore,
		Platform: platform,
		Username: username,
	}
	dataArray = append(dataArray, newData)

	// Marshal and write to file
	bytesToWrite, errMarshal := json.MarshalIndent(dataArray, "", "    ")
	if errMarshal != nil {
		fmt.Println("Error marshaling JSON:", errMarshal)
		return
	}

	errWrite := os.WriteFile(filePath, bytesToWrite, 0644)
	if errWrite != nil {
		fmt.Println("Error writing to file:", errWrite)
		return
	}

	fmt.Println("Added new data to the vault:", vaultName)
}
