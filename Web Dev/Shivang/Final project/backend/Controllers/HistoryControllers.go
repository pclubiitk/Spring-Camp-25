package controllers

import (
	models "Simplegpt/Models"
	utility "Simplegpt/Utility"
	"fmt"
	"net/http"
	"os"
	"strings"
	"time"

	"github.com/gin-gonic/gin"
	"gorm.io/gorm"
)

func GetSessionsOfAUser(db *gorm.DB,authSecretKey,sessionSecretKey string) func(c *gin.Context) {
	return func(c *gin.Context){
		//getting user name 
		toDecode,err:=c.Request.Cookie("authToken")
		if(err!=nil){
			fmt.Println("error getting the authToken",err.Error());
			c.JSON(http.StatusBadRequest,gin.H{"message":"error getting the authToken","error":err.Error()})
			return
		}
		
		//fmt.Println(toDecode.Value,"\n",toDecode.String())
		decodedToken,err:=utility.DecodingToken((toDecode.Value),authSecretKey)
		if(err!=nil){
			fmt.Println("error getting the authToken",err.Error());
			c.JSON(http.StatusBadRequest,gin.H{"message":"error getting the authToken","error":err.Error()})
			return
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		        //getting body for the 
		        // resolutiuon of issue

				//well here we basically try
				//to match the usercontext present in the 
				//frontend with the authToken that is present

		        var varification struct{
		        	Username string `json:"username"`
		        }
		        if err=c.BindJSON(&varification);err!=nil{
		        	fmt.Println("can't get the body of request")
		        	c.JSON(http.StatusInternalServerError,gin.H{"message":"can't get the body of request",
		        	"error":"can't get the body of request"})
		        }
		        if(varification.Username!=decodedToken["username"]){
		        	
		        	authTokenString,err:=utility.GenerateAuthToken(varification.Username,authSecretKey,time.Now().Add(time.Hour*24))
		        	if err!=nil{
		        		fmt.Println("error in generating auth token")
		        		c.JSON(http.StatusBadRequest,gin.H{"message":"error in generating auth token","error":err})
		        		return
		        	}
		        	c.SetCookie("authToken",authTokenString,24*3600,"/","localhost",false,false)
		        }
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		
		var currentUser models.User
		isRetrievedUser:=db.Where("username=?",varification.Username).First(&currentUser)
		if isRetrievedUser.Error!=nil{
			fmt.Println("Cann't retreive the User")
			c.JSON(http.StatusBadRequest,gin.H{
				"message":"Cann't retreive the User",
				"error":"Cann't retreive the User",
			})
			return 
		}

		//getting the session 
		var sessions []models.Session
		areSessionsRetrieved:=db.Where("user_id=?",currentUser.ID).Find(&sessions)
		if areSessionsRetrieved.Error!=nil{
			fmt.Println("Cann't retreive the Sessions")
			c.JSON(http.StatusBadRequest,gin.H{
				"message":"Cann't retreive the Sessions",
				"error":"Cann't retreive the Sessions",
			})
			return 
		}
		
		// var idBox models.GettingSessionReq
		// c.BindJSON(&idBox)

		// expirationTime:=time.Now().Add(time.Hour*24)
		// fmt.Println("\n\n\n",idBox.ID,"\n\n\n")
		// sessionToken,errorS:=utility.GenerateSessionToken(idBox.ID,sessionSecretKey,expirationTime)
		// if errorS!=nil{
		// 	fmt.Println("error in generating session token",errorS)
		// 	c.JSON(http.StatusBadRequest,gin.H{"message":"error in generating session token","error":errorS})
		// 	return 
		// }
		// c.SetCookie("sessionToken",sessionToken,24*3600,"/","localhost",false,true)
		

		c.JSON(http.StatusOK,gin.H{"message":"These are your sessions","sessions":sessions})
	}
}

func GetTalksOfASessionForDownloadPurpose(db *gorm.DB,sessionSecretKey string) func(c *gin.Context) {
	return func(c *gin.Context){
		//getting the string
		var stringToDownload struct{
			FileName      string `json:"fileName"`
			StrToDownload string `json:"strToDownload"`
		}
		err:=c.BindJSON(&stringToDownload)
		if err!=nil{
			fmt.Println("cann't get the file string")
			c.JSON(http.StatusInternalServerError,gin.H{
				"message":"cann't get the file string",
				"err":"cann't get the file string",
			})
		}
		safeFileName := strings.ReplaceAll(stringToDownload.FileName, `"`, "") // Remove quotes
		safeFileName = strings.ReplaceAll(safeFileName, " ", "_") // Replace spaces with underscores
		safeFileName = strings.ReplaceAll(safeFileName, "\n", "") // Replace \n
		//fmt.Println(stringToDownload.StrToDownload)
		//fmt.Println("dashhhhhhh",safeFileName)
		err=os.WriteFile(safeFileName+".md",[]byte(stringToDownload.StrToDownload),0644)
		if(err!=nil){
			fmt.Println("Cann't write the file",err)
			c.JSON(http.StatusInternalServerError,gin.H{
				"message":"Cann't write the file",
				"error":"Cann't write the file",
			})
			return
		}
		
		c.Writer.Header().Set("Content-Type", "text/markdown")
		c.FileAttachment(safeFileName+".md",stringToDownload.FileName)

		//removing the file after sending it
		go func() {
			err := os.Remove(safeFileName+".md")
			if err != nil {
				println("Error deleting file:", err.Error())
			} else {
				println("File deleted successfully.")
			}
		}()

		
		
		// var idBox models.GettingSessionReq
		// c.BindJSON(&idBox)

		

		// //getting the session
		// var session models.Session
		// isSessionRetrieved:=db.Where("id=?",idBox.ID).First(&session)
		// if isSessionRetrieved.Error!=nil{
		// 	fmt.Println("Can't retrive the session from database")
		// 	c.JSON(http.StatusInternalServerError,gin.H{
		// 		"message":"Can't retrive the session from database",
		// 		"error":"Can't retrive the session from database",
		// 	})
		// }

		// //creating the string to send



		// c.JSON(http.StatusOK,gin.H{
		// 	"message":"This is the context for session",
		// 	"Context":session.Context})

	}
}

func GetAllTalksOfASession(db *gorm.DB,sessionSecretKey string) func(c *gin.Context) {
	return func(c *gin.Context){
		var idBox models.GettingSessionReq
		c.BindJSON(&idBox)

		

		//getting the session
		var session models.Session
		isSessionRetrieved:=db.Where("id=?",idBox.ID).First(&session)
		if isSessionRetrieved.Error!=nil{
			fmt.Println("Can't retrive the session from database")
			c.JSON(http.StatusInternalServerError,gin.H{
				"message":"Can't retrive the session from database",
				"error":"Can't retrive the session from database",
			})
		}

		//creating the string to send



		c.JSON(http.StatusOK,gin.H{
			"message":"This is the context for session",
			"Context":session.Context})
	}
}