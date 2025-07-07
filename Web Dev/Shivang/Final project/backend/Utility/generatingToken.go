package utility

import (
	"fmt"
	"time"

	"github.com/golang-jwt/jwt/v5"
)

func GenerateAuthToken(username,secretKey string,expirationTime time.Time)(string,error){
	claims:=jwt.MapClaims{
		"username":username,
		"exp":expirationTime.Unix(),
		"iat":time.Now().Unix(),
	}
	token:=jwt.NewWithClaims(jwt.SigningMethodHS256,claims)

	tokenString,err:=token.SignedString([]byte(secretKey))
	if err!=nil{
		return "",err
	}
	return tokenString,nil
}

func GenerateSessionToken(sessionId uint,secretKey string,expirationTime time.Time)(string,error){
	claims:=jwt.MapClaims{
		"sessionid":sessionId,
		"exp":expirationTime.Unix(),
		"iat":time.Now().Unix(),
	}
	token:=jwt.NewWithClaims(jwt.SigningMethodHS256,claims)

	tokenString,err:=token.SignedString([]byte(secretKey))
	if err!=nil{
		return "",err
	}
	return tokenString,nil
}

func DecodingToken(tokenString,secretKey string) (jwt.MapClaims,error){
	token,err:=jwt.Parse(tokenString,func(token *jwt.Token)(interface{},error){
		if _,ok:=token.Method.(*jwt.SigningMethodHMAC); !ok{
			return nil,fmt.Errorf("unexpected signing method")
		}
		return []byte(secretKey),nil
	})

	if err!=nil{
		fmt.Println("Error parsing the token",err)
		return jwt.MapClaims{},err
	}

	//Extracting claims
	if claims,ok:=token.Claims.(jwt.MapClaims); ok && token.Valid{
		return claims,nil
	}
	return jwt.MapClaims{} ,err
}