import { useContext } from "react";
import { UserContext } from "../context/userContext";

export const useUserContext=function(){
    const context=useContext(UserContext);
    if(!context){
        throw Error("useUserContext must be used inside an UserContextProvider");
    }
    return context;
}