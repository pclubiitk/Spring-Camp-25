package models

import (
	"encoding/json"

	"gorm.io/gorm"
)
type User struct{
	gorm.Model
	Username   string `json:"username" gorm:"unique;not null"`
	Password   string `json:"password" gorm:"not null"`
	Useremail  string `gorm:"unique;not null" json:"useremail" `
	Sessions   []Session `gorm:"foreignKey:UserId;constraint:OnDelete:CASCADE" json:"session_ids"`
}



// Custom type for JSONB
type JSONB []map[string]string

// Implements Scan for reading JSONB data from PostgreSQL
func (j *JSONB) Scan(value interface{}) error {
	return json.Unmarshal(value.([]byte), j)
}

// Implements Value for storing JSONB data into PostgreSQL
func (j JSONB) Value() (interface{}, error) {
	return json.Marshal(j)
}

// Session Model
type Session struct {
	gorm.Model
	UserId       uint    `json:"user_id"`
	SessionTitle string  `json:"session_title"`
	Context      JSONB `gorm:"type:jsonb" json:"context"` // Stores JSONB in PostgreSQL
}


