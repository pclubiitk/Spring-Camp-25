package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"passwordManager/utils"

	"github.com/joho/godotenv"
)

// type data {
// 	Username string `json`
// }



func main(){
	// Load .env file
	err := godotenv.Load()
	if err != nil {
		log.Fatalf("Error loading .env file: %v", err)
	}
	MY_SECRET_KEY:=os.Getenv("MY_SECRET_KEY")

	fmt.Println("What do you want to do?")
	fmt.Println("1 Create new Vault")
	fmt.Println("2 Open a vault")
	fmt.Println("3 Add password to a vault")
	fmt.Println("4 Quit")
	fmt.Println(">  ")
	taskScanner:=bufio.NewScanner(os.Stdin)
	for{
		taskScanner.Scan()
		text:=taskScanner.Text()
		if(text=="4"){
			break
		}else if(text=="3"){
			fmt.Print("Vaultname: ")
			vaultScanner:=bufio.NewScanner(os.Stdin)
			vaultScanner.Scan()
			vaultname:=vaultScanner.Text()
			fmt.Print("Username: ")
			userScanner:=bufio.NewScanner(os.Stdin)
			userScanner.Scan()
			username:=userScanner.Text()
			fmt.Print("Platform Name: ")
			platformScanner:=bufio.NewScanner(os.Stdin)
			platformScanner.Scan()
			platformname:=platformScanner.Text()
			fmt.Print("password: ")
			passwordScanner:=bufio.NewScanner(os.Stdin)
			passwordScanner.Scan()
			password:=passwordScanner.Text()
			utils.AddPasswordToVault(vaultname,password,platformname,username,MY_SECRET_KEY)
		}else if(text=="2"){
			fmt.Print("Vaultname: ")
			vaultScanner:=bufio.NewScanner(os.Stdin)
			vaultScanner.Scan()
			vaultname:=vaultScanner.Text()
			fmt.Print("Username: ")
			userScanner:=bufio.NewScanner(os.Stdin)
			userScanner.Scan()
			username:=userScanner.Text()
			utils.OpenVault(vaultname,username,MY_SECRET_KEY)
		}else if(text=="1"){
			fmt.Print("Vaultname: ")
			vaultScanner:=bufio.NewScanner(os.Stdin)
			vaultScanner.Scan()
			vaultname:=vaultScanner.Text()
			utils.CreateVault(vaultname)
		}else{
			fmt.Println("Invalid Input")
		}
	}
}