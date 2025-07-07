import { createContext, useReducer } from "react";

export const QueryContext=createContext()

const reducerFunction=function(state,action){
    switch (action.type) {
        case "ADD_CLIENT_MESSAGE":
            return [...state,action.payload];
        case "ADD_SERVER_MESSAGE":
            return [...state,action.payload];
        case "REFRESH_KA_COUNTER":
            return action.context
        case "SAARI_BAATE":
            return action.context
        case "NAYA_SESSION":
            return []
    }
}


export const QueryContextProvider=function(props){
    const initialState=[];

    const [globalQueryContext,dispatchQueryContext]=useReducer(reducerFunction,initialState);

    return (
        <QueryContext.Provider value={{globalQueryContext,dispatchQueryContext}}>
            {props.children}
        </QueryContext.Provider>
    )
}