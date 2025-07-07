package controllers

import (
	models "Simplegpt/Models"
	utility "Simplegpt/Utility"
	"encoding/json"
	"fmt"
	"net/http"

	"github.com/gin-gonic/gin"
	"github.com/go-resty/resty/v2"
	"gorm.io/gorm"
)


type groqResponse struct {
	Choices []struct {
		Message struct {
			Content string `json:"content"`
		} `json:"message"`
	} `json:"choices"`
}



func GettingQueriesAnswer(db *gorm.DB,sessionSecretKey,groqApiKey string) func(c *gin.Context){
	return func (c *gin.Context){
		//getting the session cookie which contains
		//  the session (primary key of session)
		toDecode,err:=c.Request.Cookie("sessionToken")
		if(err!=nil){
			fmt.Println("error getting the sessionToken",err.Error());
			c.JSON(http.StatusBadRequest,gin.H{"message":"error getting the sessionToken","error":err.Error()})
			return
		}
		

		//decoding the token
		decoded,er:=utility.DecodingToken(string(toDecode.Value),sessionSecretKey)
		if er!=nil{
			fmt.Println(er,"dash")
			return 
		}
		//fmt.Println(decoded)

		//storing the session in local variable
		var session models.Session
		isSessionRetrivedError:=db.Where("id = ?",decoded["sessionid"]).First(&session)
		//fmt.Println(isSessionRetrivedError)
		if isSessionRetrivedError.Error!=nil{
			fmt.Println("cann't retreive User")
			c.JSON(http.StatusInternalServerError,gin.H{"message":"unable to retreive user","error":isSessionRetrivedError})
			return 
		}


		//getting answer form grom
			//step 1 getting context
			var payload []map[string]string
			if err:=c.BindJSON(&payload);err!=nil{
				fmt.Println(payload,err)
				fmt.Println("error getting body request")
				c.JSON(http.StatusBadRequest,gin.H{"message":"error getting body request","error":err})
				return
			}
			//step 2 passing this context to groq
			client := resty.New()

			
			// fmt.Println("\n\n\nJOKER HU MAIN \n\n\n")
			//fmt.Println(payload[0]["content"])

			db.Model(&session).Update("session_title",payload[0]["content"])
			resp,err := client.R().
			SetHeader("Authorization", "Bearer "+groqApiKey).
			SetHeader("Content-Type", "application/json").
			SetBody(map[string]interface{}{
				"model": "llama-3.1-8b-instant",
				"messages": payload,
			}).
			Post("https://api.groq.com/openai/v1/chat/completions")
			if(err!=nil){
				fmt.Println("Can't generate response from llm",err)
				c.JSON(http.StatusInternalServerError,gin.H{"message":"Can't generate response from llm","error":"Can't generate response from llm"})
				return
			}
			//step 3 // Parse JSON response
			var groqResponse groqResponse
			err = json.Unmarshal(resp.Body(), &groqResponse)
			if err != nil {
				fmt.Println("Error parsing JSON response:", err)
				fmt.Println("Raw Response:", string(resp.Body())) // Debugging
				return
			}

		//Updating the session's context property
		
		Context:=append(payload,map[string]string{"role":"assistant","content":groqResponse.Choices[0].Message.Content})

					
					// Convert newContext to JSON format
					jsonContext, err := json.Marshal(Context)
					if err != nil {
						panic("Failed to marshal JSONB data")
					}

					// Update the JSONB field
					db.Model(&session).Update("context", jsonContext)

		
		//fmt.Println("Updated Session Context")
		c.JSON(http.StatusOK,gin.H{"message":"Added new Prompt in the database","llmResponse":groqResponse.Choices[0].Message.Content})
	}
}
