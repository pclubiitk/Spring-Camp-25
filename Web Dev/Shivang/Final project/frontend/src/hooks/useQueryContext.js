import { useContext } from "react";
import { QueryContext } from "../context/queryContext";


export const useQueryContext=function(){
    const context=useContext(QueryContext);
    if(!context){
        throw Error("useQueryContext must be used inside an QueryContextProvider");
    }
    return context;
}