package utility

import "golang.org/x/crypto/bcrypt"

func IsAuthentic(hashedPassword, claimedPassword string) bool {
	err := bcrypt.CompareHashAndPassword([]byte(hashedPassword),[]byte(claimedPassword))
	return err==nil
}