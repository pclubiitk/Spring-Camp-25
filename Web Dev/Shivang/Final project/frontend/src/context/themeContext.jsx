import { createContext, useReducer } from "react";

export const ThemeContext=createContext()

const reducerFunction=function(state,action){
    switch (action.type) {
        case "LIGHT":
            return "light";
        case "DARK":
            return "dark";
    }
}


export const ThemeContextProvider=function(props){
    const initialState="dark";

    const [globalThemeContext,dispatchThemeContext]=useReducer(reducerFunction,initialState);

    return (
        <ThemeContext.Provider value={{globalThemeContext,dispatchThemeContext}}>
            {props.children}
        </ThemeContext.Provider>
    )
}