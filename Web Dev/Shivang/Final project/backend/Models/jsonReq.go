package models


type SignupReq struct{
	Username   string `json:"username"`
	Password   string `json:"password"`
	Useremail  string `json:"useremail" `
}


type LoginReq struct{
	Username   string `json:"username"`
	Password   string `json:"password"`
}

type PromptReq struct{
	Question   string `json:"question"`
	Answer     string `json:"answer"`
}

type GettingSessionReq struct{
	ID uint `json:"id"`
}
