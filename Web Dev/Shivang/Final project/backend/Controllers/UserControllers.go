package controllers

import (
	models "Simplegpt/Models"
	utility "Simplegpt/Utility"
	"fmt"
	"net/http"
	"time"

	"github.com/gin-gonic/gin"
	"golang.org/x/crypto/bcrypt"
	"gorm.io/gorm"
)


func SignUp(db *gorm.DB,authSecretKey string) func(c *gin.Context) {
	return (func(c *gin.Context){
		var req models.SignupReq
		var err error
		
		//converting json request to loginreq struct
		if err=c.BindJSON(&req); err!=nil{
			c.JSON(http.StatusBadRequest,gin.H{"message":"Invalid request","error":err})
			return 
		}


		//checking if the user is already present
		var ifExists models.User

		if db.Where("username = ? OR useremail = ?", req.Username, req.Useremail).First(&ifExists).RowsAffected > 0 {
			fmt.Println("User with provided username or email is already present")
			c.JSON(http.StatusBadRequest, gin.H{"message": "User with provided username or email is already present","error":"User with provided username or email is already present"})
			return
		}

		//Hashing the password
		hashedPassword,errHashing:= bcrypt.GenerateFromPassword([]byte(req.Password),bcrypt.DefaultCost)
		if errHashing!=nil{
			fmt.Println("error in hashing the password")
			c.JSON(http.StatusBadRequest,gin.H{"message":"error in hashing the password","error":errHashing})
			return
		}
		req.Password=string(hashedPassword)


		//generating Authtoken
		authTokenString,err:=utility.GenerateAuthToken(req.Username,authSecretKey,time.Now().Add(time.Hour*24))
		if err!=nil{
			fmt.Println("error in generating auth token")
			c.JSON(http.StatusBadRequest,gin.H{"message":"error in generating auth token","error":err})
			return
		}


		// Creating new user
		newUser:=models.User{Username:req.Username,Password: req.Password,Useremail: req.Useremail}
		isCreated:=db.Create(&newUser)
		if isCreated.Error!=nil{
			fmt.Println("Error inserting user",isCreated.Error)
			c.JSON(500,gin.H{"message":"Error inserting user","error":isCreated.Error})
			return 
		}else {
			//for local use we dont use secure cookies 
			// as they are sent only over https port
			c.SetCookie("authToken",authTokenString,24*3600,"/","localhost",false,false)
			//for production use this
			// c.SetCookie("authToken",authTokenString,24*3600,"/","",true,true)
			c.JSON(http.StatusCreated,gin.H{"message":"new user created","user":newUser})
		}
	})
}


func LogIn(db *gorm.DB,authSecretKey string) func(c *gin.Context) {
	return (func(c *gin.Context){
		var req models.LoginReq
		var err error
		

		//converting json request to loginreq struct
		if err=c.BindJSON(&req); err!=nil{
			c.JSON(http.StatusBadRequest,gin.H{"message":"Invalid request","error":err})
			return 
		}

		//fmt.Println(req,"dash")

		//finding user in our database
		var userDemanded models.User
		result:=db.Where(&models.User{Username:req.Username}).First(&userDemanded)
		if (result.Error!=nil){
			fmt.Println("User with provided username is not present on our database please sign up")
			c.JSON(http.StatusBadRequest,gin.H{"message":"User with provided username is not present on our database please sign up","error":"User with provided username is not present on our database please sign up"})
			return 
		}
		//fmt.Println(req,userDemanded.Password)
		//verifying the hashed password 
		if utility.IsAuthentic(userDemanded.Password,req.Password){
			//generating Authtoken
			authTokenString,err:=utility.GenerateAuthToken(req.Username,authSecretKey,time.Now().Add(time.Hour*24))
			if err!=nil{
				fmt.Println("error in generating auth token")
				c.JSON(http.StatusBadRequest,gin.H{"message":"error in generating auth token","error":err})
				return
			}
			c.SetCookie("authToken",authTokenString,24*3600,"/","localhost",false,true)
			fmt.Println("User Logged in")
			c.JSON(http.StatusOK,gin.H{"message":"User Logged in","user":userDemanded})
		}else{
			fmt.Println("Password don't match to the one stored in database")
			c.JSON(http.StatusBadRequest,gin.H{"message":"Password dont match to the one stored in database","error":"Password dont match to the one stored in database"})
		}
	})
}


func Logout(c *gin.Context){
	c.SetCookie("authToken", "", -1, "/", "localhost", false, true);
	c.SetCookie("sessionToken", "", -1, "/", "localhost", false, true);
	c.JSON(200, gin.H{
		"message": "Cookie removed successfully",
	})
	fmt.Println("User logged out")
}