package main

import (
	controllers "Simplegpt/Controllers"
	database "Simplegpt/Database"
	models "Simplegpt/Models"
	"log"
	"os"
	"time"

	"github.com/gin-contrib/cors"
	"github.com/gin-gonic/gin"
	"github.com/joho/godotenv"
)

func main() {
	err:=godotenv.Load()
	if err!=nil{
		log.Fatal("Error loading .env file")
	}
	userName:=os.Getenv("USER_NAME")
	userPassword:=os.Getenv("USER_PASSWORD")
	dbName:=os.Getenv("DB_NAME")
	sslMode:=os.Getenv("SSL_MODE")
	authSecretKey:=os.Getenv("AUTH_SECRET_KEY")
	sessionSecretKey:=os.Getenv("SESSION_SECRET_KEY")
	listeningPort:=os.Getenv("PORT")
	simpleGptApi:=os.Getenv("SIMPLEGPTAPI")
	
	r := gin.Default()

	// CORS middleware configuration
	r.Use(cors.New(cors.Config{
		AllowOrigins:     []string{"http://localhost:5173"}, // Frontend URL
		AllowMethods:     []string{"GET", "POST", "PUT", "DELETE", "OPTIONS"},
		AllowHeaders:     []string{"Origin", "Content-Type", "Authorization"},
		ExposeHeaders:    []string{"Content-Length","Set-Cookie"},
		AllowCredentials: true, // Allow cookies & authentication headers
		MaxAge:           12 * time.Hour,
	}))


	db := database.ConnectToDB(userName,userPassword,dbName,sslMode)

	db.AutoMigrate(&models.User{},&models.Session{})
	r.POST("/login",controllers.LogIn(db,authSecretKey))
	r.POST("/signup",controllers.SignUp(db,authSecretKey))
	r.POST("/logout",controllers.Logout)
	r.POST("/createSession",controllers.CreateSession(db,authSecretKey,sessionSecretKey))
	r.POST("/createPrompt",controllers.GettingQueriesAnswer(db,sessionSecretKey,simpleGptApi))
	r.POST("/downloadTheTalks",controllers.GetTalksOfASessionForDownloadPurpose(db,sessionSecretKey))
	r.POST("/getAllTalksOfAUser",controllers.GetSessionsOfAUser(db,authSecretKey,sessionSecretKey))
	r.POST("/setSession",controllers.SessionSetter(db,sessionSecretKey))
	r.POST("/getAllTalksOfASession",controllers.GetAllTalksOfASession(db,sessionSecretKey))
	r.Run(listeningPort)
	
}
