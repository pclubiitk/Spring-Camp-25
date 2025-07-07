import { useEffect, useState } from 'react'
import {BrowserRouter,Routes,Route, Navigate, useNavigate, Link} from "react-router-dom"

import SignupPage from './Pages/SignupPage'
import LoginPage from './Pages/LoginPage'
import HomePage from './Pages/HomePage'
import { useQueryContext } from './hooks/useQueryContext'
import { useUserContext } from './hooks/useUserContext'
import { useSessionContext } from './hooks/useSessionContext'
import ExperimentPage from './Pages/ExperimentPage'


import { marked } from "marked";
import hljs from "highlight.js";
import "../node_modules/highlight.js/styles/dark.css" // Choose a theme
import { ThemeProvider } from '@emotion/react'
import * as Theme from './theme'
import { useThemeContext } from './hooks/useThemeContext'



marked.setOptions({
  highlight: (code, lang) => {
    const language = hljs.getLanguage(lang) ? lang : "plaintext";
    return hljs.highlight(code, { language }).value;
  },
});


function App() {
  //error state
  const [hadNotCreatedSession,setHadNotCreatedSession]=useState(true)

  //gloabal context that contains all the
  //queries of a session where user questions 
  // and ai's answers are stored as list newest first
  const {globalQueryContext,dispatchQueryContext}=useQueryContext()

  //retaining user and session on page refresh
  
  const {globalUserContext,dispatchUserContext}=useUserContext()
  const {globalSessionContext,dispatchSessionContext}=useSessionContext()
  const {globalThemeContext,dispatchThemeContext}=useThemeContext()
  //If session is created
  if(sessionStorage.getItem("sessionid") ){
     
      const gettingBackUserAndSessionTalks=async function(){
        //well ab ek baar login kar rakha hu to 
        //auth token to hai hi cookies mai
        //  jo bata raha hai ki banda authentic hai
        //then session storage mai bhi username pada
        //  hai uska istemal karke frontend ke 
        // globalUserContext jo ki refresh karne pe ud
        // jata hai ko set karenge😁 

        const origin=import.meta.env.VITE_API_URL;
        if(sessionStorage.getItem("username")==null){
          // iska matlab bande ne na login kiya na sign up 
          // kyunki agar vo login ya sign up karta to ye 
          // non empty hota but it is empty to hum bus 
          // use login page pe redirect kar denge 
          window.location.href = '/login';
        }
        //this set backs the usercontext and sessioncontext
        //on frontend
        dispatchUserContext({type:"Login",username:sessionStorage.getItem("username")})
        dispatchSessionContext({type:"SET_SESSION","username":sessionStorage.getItem("username"),"sessionid":sessionStorage.getItem("sessionid")})
        
        //repopulating chats state in frontend with help of

        //bakend data

        const response=await fetch(origin +"/getAllTalksOfASession",{
          method:"POST",
          credentials:"include",
          body:JSON.stringify({id:parseInt(sessionStorage.getItem("sessionid"))})
        })
        const json=await response.json()
        //console.log(typeof(json.Context))
        dispatchQueryContext({type:"REFRESH_KA_COUNTER",context:json.Context||[]})
      }

      useEffect(()=>{
        gettingBackUserAndSessionTalks()
        //console.log(globalUserContext)
      },[])  

  }else if(sessionStorage.getItem("username")){
    const gettingBackUser=async function(){

      /////////////////////////////////////////////////////////////
            //well this is waste as session storage will contain
            //username for comming inside this if else block
            
            if(sessionStorage.getItem("username")==null){
              // iska matlab bande ne na login kiya na sign up 
              // kyunki agar vo login ya sign up karta to ye 
              // non empty hota but it is empty to hum bus 
              // use login page pe redirect kar denge 
              window.location.href = '/login';
            }
      /////////////////////////////////////////////////////////////
      
      //this set backs the usercontext
      //on frontend
      dispatchUserContext({type:"Login",username:sessionStorage.getItem("username")})
    } 
    useEffect(()=>{
      gettingBackUser()
      //console.log(globalUserContext,"gorrrr")
    },[]) 

  }else{
    const tenResponses=async function(){

    }
    useEffect(()=>{
      tenResponses()
    },[])
  }
  //this else thing is there only for react soecific purposes
  //as in react the order of hooks in each render should be same
  //if this use effect hook is not present then order will break
  //and react will have inner issues
  

  //console.log(globalSessionContext,globalUserContext,"dash")

  return (
          <ThemeProvider theme={globalThemeContext=="dark"?Theme.darkTheme:Theme.lightTheme}>
            <BrowserRouter>
              <Routes>
                <Route path='/' element={<HomePage 
                hadNotCreatedSession={hadNotCreatedSession}
                setHadNotCreatedSession={setHadNotCreatedSession}/>}/>
                <Route path='/signup' element={<SignupPage/>}/>
                <Route path='/login' element={<LoginPage/>}/>
                <Route path='/exp' element={<ExperimentPage/>}/>
              </Routes>
            </BrowserRouter>
          </ThemeProvider>
  )
}

export default App
