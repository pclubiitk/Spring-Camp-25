import { Box, Grid2, Typography } from '@mui/material'
import React, { useState } from 'react'
import Form from '../Components/Form';
import { useUserContext } from '../hooks/useUserContext';
import { useNavigate } from 'react-router-dom';
import { useQueryContext } from '../hooks/useQueryContext';
import { useSessionContext } from '../hooks/useSessionContext';
import { useCurrentPageContext } from '../hooks/useCurrentPageContext';
import { useThemeContext } from '../hooks/useThemeContext';
import CustomBox from '../Components/CustomBox';
const LoginPage = () => {
  //getting various global contexts
  const {globalUserContext,dispatchUserContext}=useUserContext()
  const {globalQueryContext,dispatchQueryContext}=useQueryContext()
  const {globalSessionContext,dispatchSessionContext}=useSessionContext()
  const {globalCurrentPageContext,dispatchCurrentPageContext}=useCurrentPageContext()
  const {globalThemeContext,dispatchThemeContext}=useThemeContext()


  //field states
  const [username,setUsername]=useState("")
  const [password,setPassword]=useState("")
  const [error,setError]=useState("")
  
  //making handler function
  const handlePasswordChanges=function(e){
    setPassword(e.currentTarget.value);
  }
  const handleUsernameChanges=function(e){
    setUsername(e.currentTarget.value);
  }

  const navigator=useNavigate();

  const origin=import.meta.env.VITE_API_URL;
  const handleLogins=async function(e){
    setError("")
    
    const response=await fetch(origin+"/login",{
      method:"POST",
      body:JSON.stringify({username,password}),
      headers:{
        "Content-Type":"application/json"
      },
      credentials:"include" //very important bahut time laga
    });
    const json=await response.json();
    if(!response.ok){
      setError(json.error);
      console.log("error in login",json.error);
      return ;
    }
    //console.log(json)
    await dispatchUserContext({type:"Login",username:json.user.username});
    await dispatchSessionContext({type:"SET_SESSION",username:json.user.username,sessionid:undefined})
    await dispatchQueryContext({type:"NAYA_SESSION"})
    await dispatchCurrentPageContext({type:"NEWSESSION"})
    sessionStorage.clear("sessionToken")
    //console.log(globalUserContext)
    //session storage ka use so that refresh karne 
    // pe baar baar na ude homepage 
    sessionStorage.setItem("username",json.user.username);
    
    
    console.log("new User Set globally");
    navigator("/");
  }

  
  let textCol="black"
  if(globalThemeContext=="dark"){
    textCol="white"
  }
  return (
    <Box sx={{ display: "grid", gridTemplateColumns: "2fr 1fr", height: "100vh"}}>
      {/* Left Side */}
      <Box sx={{ background:`url("/Login page.svg")`,backgroundSize:"cover",backgroundPosition:"center", display: "flex", justifyContent: "center", alignItems: "center" }}>

      </Box>

      {/* Right Side */}
      <CustomBox sx={{ display: "flex",position:"relative", justifyContent: "center", alignItems: "center", boxShadow:"-5px 0 10px "+(globalThemeContext=="dark"? " #e7195a" :" #fe5d00"), borderLeft:"2px solid "+(globalThemeContext=="dark"? " #e7195a" :" #fe5d00"),flexDirection:"column"}}>
        <Typography variant='h4' sx={{marginBottom:"2rem",color:globalThemeContext=="dark"?"white":"black"}}>Welcome Back👋</Typography>
        <Form inputs={["Username","Password"]}
              submit={"Log In"} 
              formLable={"Log In"}
              onSubmit={handleLogins} 
              feilds={[username,password]}
              handleFeildChanges={[handleUsernameChanges,
                                  handlePasswordChanges,
                                ]}
              isLogin={true}>
          
            </Form>
            {error!=""?<div className={globalThemeContext=="dark"?"errorBoxDark":"errorBoxLight"}>
              {error}
            </div>:""}
      </CustomBox>
    </Box>
  );
}




export default LoginPage