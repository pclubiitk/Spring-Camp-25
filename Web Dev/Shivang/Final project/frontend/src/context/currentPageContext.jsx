import { createContext, useReducer } from "react";

export const CurrentPageContext=createContext()

const reducerFunction=function(state,action){
    switch (action.type) {
        case "HISTORY":
            return "history";
        case "NEWSESSION":
            return "newsession";
        case "PURANASESSION":
            return "puranasession";
    }
}


export const CurrentPageContextProvider=function(props){
    const initialState="newsession";

    const [globalCurrentPageContext,dispatchCurrentPageContext]=useReducer(reducerFunction,initialState);

    return (
        <CurrentPageContext.Provider value={{globalCurrentPageContext,dispatchCurrentPageContext}}>
            {props.children}
        </CurrentPageContext.Provider>
    )
}