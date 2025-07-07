import { Box, IconButton, TextField, InputAdornment } from '@mui/material'
import React, { useEffect, useState } from 'react'

import SearchBox from '../Components/SearchBox';
import ChatBox from '../Components/ChatBox';
import { useQueryContext } from '../hooks/useQueryContext';
import { useUserContext } from '../hooks/useUserContext';
import { useNavigate } from 'react-router-dom';
import { useSessionContext } from '../hooks/useSessionContext';
import { marked } from "marked";
import hljs from "highlight.js";
import "../../node_modules/highlight.js/styles/dark.css" // Choose a theme
import CustomBox from '../Components/CustomBox';


marked.setOptions({
  highlight: (code, lang) => {
    const language = hljs.getLanguage(lang) ? lang : "plaintext";
    return hljs.highlight(code, { language }).value;
  },
});


const NewSession = () => {

  //gloabal context that contains all the
  //queries of a session where user questions 
  // and ai's answers are stored as list newest first
  const {globalQueryContext,dispatchQueryContext}=useQueryContext()

  //retaining user and session on page refresh
  
  const {globalUserContext,dispatchUserContext}=useUserContext()
  const {globalSessionContext,dispatchSessionContext}=useSessionContext()
  const navigator=useNavigate()


 

  //Searched string
  const [searchedString,setSearchedString]=useState("");
  //handeling changes inside textarea function
  const changingInput=function(e){
    setSearchedString(e.currentTarget.value)
   
  }
  //handleing Searches
  const origin=import.meta.env.VITE_API_URL;
  const onSearch=async function(e){

      dispatchQueryContext({type:"ADD_CLIENT_MESSAGE",payload:{"role":"user","content":searchedString}})

    const response=await fetch(origin+"/createPrompt",{
      method:"POST",
      credentials:"include",
      body: JSON.stringify([...globalQueryContext,{"role":"user","content":searchedString}])
    })
    const json=await response.json()
    if(!response.ok){
      console.log("got an error :",json.error)
      return
    }
    //console.log("dash",json)
    dispatchQueryContext({type:"ADD_SERVER_MESSAGE",payload:{"role":"assistant","content":json.llmResponse}})

    setSearchedString("")
    //made to get back session talks on page 
    //refresh
    // sessionStorage.setItem("session talks",globalQueryContext)
  }

  

  // console.log(globalQueryContext,dispatchQueryContext)
  
  const chats=globalQueryContext.map((query,index)=>{
    return <ChatBox key={index} isClient={ query.role!="user" } markdown={marked(query.content)} />
  })


  return (

    <CustomBox sx={{ flexGrow: 1, width: "80%", display: "flex",flexDirection:"column", justifyContent: "end", marginBottom:"2rem" }}>
        <CustomBox sx={{flexGrow:1,display:"flex",flexDirection:"column",justifyContent:"end",p:"1rem"}}>
          {chats}
        </CustomBox>
        <SearchBox input={searchedString} handleChange={changingInput} onSearch={onSearch} ></SearchBox>
    </CustomBox>



    // <Box sx={{flexGrow:1,width:"100%", display:"flex",justifyContent:"center"}}>
    //     <TextField sx={{borderRadius:"1rem",top:"80%",width:"80%"}}>
    //       <SearchIcon/>
    //       <IconButton size='large' edge='end'>
    //         <SearchIcon sx={{color:"black", fontSize:30}}/>
    //       </IconButton>
    //     </TextField>
    // </Box>
  )
}

export default NewSession