import { useContext } from "react";
import { CurrentPageContext } from "../context/currentPageContext";


export const useCurrentPageContext=function(){
    const context=useContext(CurrentPageContext);
    if(!context){
        throw Error("useCurrentPageContext must be used inside an CurrentPageContextProvider");
    }
    return context;
}