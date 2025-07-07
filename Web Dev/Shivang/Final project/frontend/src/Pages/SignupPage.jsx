import { Box, Grid2, Typography } from '@mui/material'
import React, { useState } from 'react'
import Form from '../Components/Form';
import { useUserContext } from '../hooks/useUserContext';
import { useNavigate } from 'react-router-dom';
import { useThemeContext } from '../hooks/useThemeContext';
import CustomBox from '../Components/CustomBox';

const SignupPage = () => {
  const {globalThemeContext,dispatchThemeContext}=useThemeContext()
  

  //field states
  const [username,setUsername]=useState("")
  const [useremail,setUseremail]=useState("")
  const [password,setPassword]=useState("")
  const [error,setError]=useState("")
  const {dispatchUserContext}=useUserContext()
  //making handler function
  const handlePasswordChanges=function(e){
    setPassword(e.currentTarget.value);
  }
  const handleUseremailChanges=function(e){
    setUseremail(e.currentTarget.value);
  }
  const handleUsernameChanges=function(e){
    setUsername(e.currentTarget.value);
  }


  const navigator=useNavigate()
  const origin=import.meta.env.VITE_API_URL;
  const handleSignups=async function(e){
    const response=await fetch(origin+"/signup",{
      method:"POST",
      body:JSON.stringify({username,password,useremail}),
      headers:{
        "Content-Type":"application/json"
      },
      credentials:"include" //very important bahut time laga
    })

    const json=await response.json();
    if(!response.ok){
      setError(json.error);
      console.log("error in signup",json.error);
      return ;
    }
    await dispatchUserContext({type:"Login",username:json.user.username})

    //session storage ka use so that refresh karne 
    // pe baar baar na ude homepage 
    sessionStorage.setItem("username",json.user.username);

    console.log("new User Created and then Set globally")
    navigator("/")
  }

  let textCol="black"
  if(globalThemeContext=="dark"){
    textCol="white"
  }
  let appCol="red"
  if(globalThemeContext=="dark"){
    appCol="yellow"
  }


  return (
    <Box sx={{ display: "grid", gridTemplateColumns: "2fr 1fr", height: "100vh"}}>
      {/* Left Side */}
      <Box sx={{ background:`url("/Login page.svg")`,backgroundSize:"cover",backgroundPosition:"center", display: "flex", justifyContent: "center", alignItems: "center" }}>

      </Box>

      {/* Right Side */}
      <CustomBox sx={{ display: "flex", justifyContent: "center", alignItems: "center", boxShadow:"-5px 0 10px "+(globalThemeContext=="dark"? " #e7195a" :" #fe5d00"), borderLeft:"2px solid "+(globalThemeContext=="dark"? " #e7195a" :" #fe5d00"),flexDirection:"column"}}>
        <Typography variant='h4' style={{marginBottom:"2rem",color:textCol}}>Welcome to {<span style={{color:appCol,fontWeight:"bold"}}>Simple GPT</span>}👋</Typography>
        <Form inputs={["Username","Password","Useremail"]} 
              submit={"Sign up"} 
              formLable={"Sign Up"} 
              onSubmit={handleSignups}
              feilds={[username,password,useremail]}
              handleFeildChanges={[handleUsernameChanges,
                                  handlePasswordChanges,
                                  handleUseremailChanges
                                ]}
              isLogin={false}
              />
        {error!=""?<div className={globalThemeContext=="dark"?"errorBoxDark":"errorBoxLight"}>
          {error}
        </div>:""}
      </CustomBox>
    </Box>
  );
}

export default SignupPage