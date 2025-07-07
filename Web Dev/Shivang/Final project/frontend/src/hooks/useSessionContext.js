import { useContext } from "react";
import { SessionContext } from "../context/sessionContext";


export const useSessionContext=function(){
    const context=useContext(SessionContext);
    if(!context){
        throw Error("useSessionContext must be used inside an SessionContextProvider");
    }
    return context;
}