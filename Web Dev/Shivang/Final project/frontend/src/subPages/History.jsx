import { Box, Button } from '@mui/material'
import React, { useState } from 'react'
import HistoryCards from '../Components/HistoryCards'
import { useUserContext } from '../hooks/useUserContext'
import { useQueryContext } from '../hooks/useQueryContext'
import { useSessionContext } from '../hooks/useSessionContext'
import { useNavigate } from 'react-router-dom'
import { useCurrentPageContext } from '../hooks/useCurrentPageContext'

import { marked } from 'marked'
import hljs from "highlight.js";
import "../../node_modules/highlight.js/styles/dark.css" // Choose a theme

marked.setOptions({
  highlight: (code, lang) => {
    const language = hljs.getLanguage(lang) ? lang : "plaintext";
    return hljs.highlight(code, { language }).value;
  },
});


const History = (props) => {
  //console.log(props.Data)
  //getting various global context
  const {globalUserContext,dispatchUserContext}=useUserContext()
  const {globalQueryContext,dispatchQueryContext}=useQueryContext()
  const {globalSessionContext,dispatchSessionContext}=useSessionContext()
  const {globalCurrentPageContext,dispatchCurrentPageContext}=useCurrentPageContext()
  const navigator=useNavigate()

  //Delving Deeper logic
  const origin=import.meta.env.VITE_API_URL;
  const onDelveDeeper=function(id,ID){
    return async function(){
      sessionStorage.setItem("sessionid",ID)
      dispatchSessionContext({type:"SET_SESSION",username:globalUserContext.username,sessionid:String(ID)})
      //console.log(props.Data[id])
      dispatchQueryContext({type:"SAARI_BAATE",context:props.Data[id].context||[]})
      //console.log("mai hu badshah",id)
      dispatchCurrentPageContext({type:"PURANAPAGE"})
      const response= await fetch(origin+"/setSession",{
        method:"POST",
        credentials:"include",
        body:JSON.stringify({id:ID})
      })
      //console.log("got the session id")
      navigator("/")
    }
  }
  //Downloading file logic
  const onDownloadMarkdown=function(id,ID){
    //creating the string to send
    return async function(){
      let str=""
      //console.log("GOD CREATED MATHS",props.Data[id],props.Data[id].context)
      for (let i=0;i<props.Data[id].context?(props.Data[id].context).length:0;i++){
        //console.log("these are the talk objects",props.Data[id].context[i])
        str+="**"+props.Data[id].context[i].role+"**:";
        str+=props.Data[id].context[i].content+"\n\n"
      }
      //console.log(str)
      const markdownConvertedToHtml=await marked(str)
      const response=await fetch(origin+"/downloadTheTalks",{
        method:"POST",
        body:JSON.stringify({"fileName":props.Data[id].session_title,"strToDownload":markdownConvertedToHtml})
      })
      //console.log(response,"downloading markdown test")
      let blob=await response.blob()
      const url = window.URL.createObjectURL(blob);
      const a = document.createElement("a");
      a.href = url;
      let filename="";
      for (let i=0;i<props.Data[id].session_title.length;i++){
        if(props.Data[id].session_title[i]!=" " || props.Data[id].session_title[i]!="\n"){
          filename+=props.Data[id].session_title[i]
        }else if(props.Data[id].session_title[i]!=" "){
          filename+="_"
        }
      }
      a.download =filename +".md"; // Change filename if needed
      document.body.appendChild(a);
      a.click();
    }
  }




  //psql se data sorted hi nahi 
  // aata to sorted banana padta
  const sorted=props.Data.sort((a,b)=>{return a.ID-b.ID})

  const components=sorted.map((dataPoint,index)=>{

    return( <HistoryCards key={dataPoint.ID} marked={dataPoint.session_title} >
      <Box style={{display:"flex", columnGap:"0.2rem"}}>
      <Button variant="contained" p={0.5} sx={{padding: "0.2rem",fontSize: "0.75rem"}} onClick={onDelveDeeper(index,dataPoint.ID)} >Delve Deeper</Button>
      <Button variant="contained" p={0.5} sx={{padding: "0.2rem",fontSize: "0.75rem"}} onClick={onDownloadMarkdown(index,dataPoint.ID)}>Download Markdown</Button>
      </Box>
    </HistoryCards>)
  })
 
  return (
    <Box  display="grid"
          gridTemplateColumns="repeat(3, 1fr)" // Three equal columns
          gap={2} // Spacing between grid items
          p={2} // Padding
    >
      {components.reverse()}

    </Box>
  )
}

export default History