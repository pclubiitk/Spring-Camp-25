import { createContext, useReducer } from "react";

export const SessionContext=createContext()

const reducerFunction=function(state,action){
    switch (action.type) {
        case "SET_SESSION":
            return {
                username:action.username,
                sessionid:action.sessionid
            };
    }
}


export const SessionContextProvider=function(props){
    const initialState={};

    const [globalSessionContext,dispatchSessionContext]=useReducer(reducerFunction,initialState);

    return (
        <SessionContext.Provider value={{globalSessionContext,dispatchSessionContext}}>
            {props.children}
        </SessionContext.Provider>
    )
}