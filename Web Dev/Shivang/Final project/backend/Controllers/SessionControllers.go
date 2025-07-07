package controllers

import (
	models "Simplegpt/Models"
	utility "Simplegpt/Utility"
	"fmt"
	"net/http"
	"time"

	"github.com/gin-gonic/gin"
	"gorm.io/gorm"
)

func CreateSession(db *gorm.DB,authSecretKey,sessionSecretKey string) func(c *gin.Context){
	return func (c *gin.Context){
		toDecode,err:=c.Request.Cookie("authToken")
		if(err!=nil){
			fmt.Println("error getting the authToken",err.Error());
			c.JSON(http.StatusBadRequest,gin.H{"message":"error getting the authToken","error":err.Error()})
			return
		}

		decoded,er:=utility.DecodingToken(string(toDecode.Value),authSecretKey)
		if er!=nil{
			fmt.Println(er)
			return 
		}
		//fmt.Println(decoded,decoded["username"])
		

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
		        if(varification.Username!=decoded["username"]){
		        	
		        	authTokenString,err:=utility.GenerateAuthToken(varification.Username,authSecretKey,time.Now().Add(time.Hour*24))
		        	if err!=nil{
		        		fmt.Println("error in generating auth token")
		        		c.JSON(http.StatusBadRequest,gin.H{"message":"error in generating auth token","error":err})
		        		return
		        	}
		        	c.SetCookie("authToken",authTokenString,24*3600,"/","localhost",false,false)
		        }
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		
		var user models.User
		retrivedUser:=db.Where("username = ?",varification.Username).First(&user)
		if retrivedUser.Error!=nil{
			fmt.Println("cann't retreive User",retrivedUser)
			c.JSON(http.StatusInternalServerError,gin.H{"message":"unable to retreive user","error":"unable to retreive user"})
			return 
		}
		newSession:=models.Session{
			UserId: user.ID,
		}
		db.Create(&newSession)
		
		expirationTime:=time.Now().Add(time.Hour*24)
		sessionToken,errorS:=utility.GenerateSessionToken(newSession.ID,sessionSecretKey,expirationTime)
		if errorS!=nil{
			fmt.Println("error in generating session token",errorS)
			c.JSON(http.StatusBadRequest,gin.H{"message":"error in generating session token","error":errorS})
			return 
		}
		c.SetCookie("sessionToken",sessionToken,24*3600,"/","localhost",false,true)
		c.JSON(http.StatusOK,gin.H{"message":"session token set","id":newSession.ID})
	}
}


func GettingSingleSessionAllTalks(db *gorm.DB,sessionSecretKey string) func(c *gin.Context){
	return func (c *gin.Context){
		toDecode,err:=c.Request.Cookie("sessionToken")
		if(err!=nil){
			fmt.Println("error getting the sessionToken",err.Error());
			c.JSON(http.StatusBadRequest,gin.H{"message":"error getting the sessionToken","error":err.Error()})
			return
		}

		decoded,er:=utility.DecodingToken(string(toDecode.Value),sessionSecretKey)
		if er!=nil{
			fmt.Println(er)
			return 
		}

		var sessionDetails models.Session
		retrievedSession:=db.Where("id = ?",decoded["sessionid"]).First(&sessionDetails)
		if retrievedSession.Error!=nil{
			fmt.Println("cann;t retrive the session",retrievedSession.Error)
			c.JSON(http.StatusInternalServerError,gin.H{
				"message":retrievedSession.Error,
				"error":retrievedSession})
			return
		}
		//fmt.Println(reflect.TypeOf(sessionDetails.Context),[]map[string]string(sessionDetails.Context))
		c.JSON(http.StatusOK,gin.H{
			"context":[]map[string]string(sessionDetails.Context),
		})
	}
}

func SessionSetter(db *gorm.DB,sessionSecretKey string) func(c *gin.Context){
	return func(c *gin.Context){
		var idBox models.GettingSessionReq
		c.BindJSON(&idBox)

		expirationTime:=time.Now().Add(time.Hour*24)
		//fmt.Println("\n\n\n",idBox.ID,"\n\n\n")
		sessionToken,errorS:=utility.GenerateSessionToken(idBox.ID,sessionSecretKey,expirationTime)
		if errorS!=nil{
			fmt.Println("error in generating session token",errorS)
			c.JSON(http.StatusBadRequest,gin.H{"message":"error in generating session token","error":errorS})
			return 
		}
		c.SetCookie("sessionToken",sessionToken,24*3600,"/","localhost",false,true)
	}
}
