import { Password } from "@mui/icons-material";
import { createContext, useReducer } from "react";

export const UserContext=createContext()

const reducerFunction=function(state,action){
  switch (action.type){
    case "Login":
      return {
        username:action.username,
      }
    case "Logout":
      return null
  }
}

export const UserContextProvider=function(props){
    const initialState=null
    const [globalUserContext,dispatchUserContext]=useReducer(reducerFunction,initialState)
    return (
        <UserContext.Provider value={{globalUserContext,dispatchUserContext}}>
          {props.children}  
        </UserContext.Provider>
    )
}