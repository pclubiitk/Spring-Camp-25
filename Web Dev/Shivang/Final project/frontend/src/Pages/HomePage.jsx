import React, { use, useEffect, useState } from 'react'
import { AppBar, Backdrop, Box, Button, Drawer, IconButton, List, ListItem, ListItemButton, ListItemText, Toolbar, Typography } from '@mui/material'
import MenuIcon from '@mui/icons-material/Menu';
import KeyboardDoubleArrowLeftIcon from '@mui/icons-material/KeyboardDoubleArrowLeft';
import { useUserContext } from '../hooks/useUserContext';
import { Navigate, useNavigate } from 'react-router-dom';
import NewSession from '../subPages/NewSession';
import { useSessionContext } from '../hooks/useSessionContext';
import { useQueryContext } from '../hooks/useQueryContext';
import { useCurrentPageContext } from '../hooks/useCurrentPageContext';
import History from '../subPages/History';
import CustomBox from '../Components/CustomBox';
import Brightness7Icon from '@mui/icons-material/Brightness7';
import BedtimeIcon from '@mui/icons-material/Bedtime';
import { useThemeContext } from '../hooks/useThemeContext';

const HomePage = (props) => {
  const {globalThemeContext,dispatchThemeContext}=useThemeContext()

  //Getting Global User
  const {globalUserContext,dispatchUserContext}=useUserContext()

  //Getting Current Page
  const {globalCurrentPageContext,dispatchCurrentPageContext}=useCurrentPageContext()

  //Navigator
  const navigator=useNavigate()

  //functions to execute with option clicks
  const origin=import.meta.env.VITE_API_URL;

  //making new Sessions
  const {globalSessionContext,dispatchSessionContext}=useSessionContext()


  const {globalQueryContext,dispatchQueryContext}=useQueryContext()
  const clickingNewSession=async function(){
    const response=await fetch(origin+"/createSession",{
      method:"POST",
      credentials: "include",
      body:JSON.stringify({username:globalUserContext.username})
    })
    const json= await response.json()
    if(!response.ok){
      console.log("got an error :",json.error)
      return
    }
    dispatchSessionContext({type:"SET_SESSION",username:globalUserContext.username,sessionid:json.id})
    dispatchQueryContext({type:"NAYA_SESSION"})
    sessionStorage.setItem("sessionid",json.id)
    props.setHadNotCreatedSession(false)
    dispatchCurrentPageContext({type:"NEWSESSION"})

  }



  //history page content
  const [dataToPass,setDataToPass]=useState(null)
  const clickingHistory=async function(){
    const response=await fetch(origin+"/getAllTalksOfAUser",{
      method:"POST",
      credentials:"include",
      body:JSON.stringify({username:globalUserContext.username})
    })
    const json=await response.json()
    if(!response.ok){
      console.log("Can't get the history")
      return
    }
    setDataToPass(json.sessions)
    dispatchCurrentPageContext({type:"HISTORY"})
    setIsOpen(false)
  }


  //Logout functionalities
  const clickingLogout=async function(){
    const response=await fetch(origin+"/logout",{
      method:"POST",
      credentials:"include",
    })
    if(!response.ok){
      console.log("cann't remove the user")
      return
    }
    await dispatchUserContext({type:"Logout"})
    await dispatchQueryContext({type:"NAYA_SESSION"})
    sessionStorage.clear("sessionid")
    sessionStorage.clear("username")
    console.log("removed the user successfully")
    dispatchCurrentPageContext({type:"NEWSESSION"})
  }

  const clickingLogin=function(){
    navigator("/login")
  }

  const clickingSignup=function(){
    navigator("/signup")
  }

  //isSidebar Open
  const [isOpen,setIsOpen]=useState(false);

  const options=globalUserContext?["New Session","History","Log out"]:["Login","Signup"]
  const clickHandlers=globalUserContext?[clickingNewSession,clickingHistory,clickingLogout]:[clickingLogin,clickingSignup]

  const listItem=options.map((text,index)=>{
    return (
      <ListItem key={text}>
        <ListItemButton onClick={clickHandlers[index]}>
          <ListItemText>{text}</ListItemText>
        </ListItemButton>
      </ListItem>
    )
  })

  const openingMenu=function(){
    setIsOpen(true)
  }
  const ClosingMenu=function(){
    setIsOpen(false)
  }



  //this alone wont work as react effects and states 
  // only runs after rendering 
  useEffect(()=>{
    //console.log(sessionStorage.getItem("username") ,sessionStorage.getItem("sessionid"),"bada gadha")
    if(sessionStorage.getItem("username")==null && sessionStorage.getItem("sessionid")==null){
      //console.log("gadha")
      navigator("/login")
    }
  },[])

  //chats logic
  const [chats,setChats]=useState([])

  //console.log(sessionStorage.getItem("username") ,sessionStorage.getItem("sessionid"),"bada gadha2")

if(sessionStorage.getItem("sessionid")==null && globalUserContext!=null && globalCurrentPageContext=="newsession"){
  return (
    <>
    <Backdrop
      sx={(theme) => ({ color: '#fff',display:"block",  zIndex:theme.zIndex.drawer - 1 })}
      open={props.hadNotCreatedSession}
    >
    
      <Box className={globalThemeContext=="dark"?"errorBoxDarkStatic":"errorBoxLightStatic"} sx={(theme) => ({ position:"absolute",top:"50%",left:"50%",translate:"-50% -50%",display:"block",  zIndex: theme.zIndex.drawer })}>Please create a new session {globalUserContext.username||[]}</Box>
    
    

      <CustomBox sx={{minHeight:"100vh",display:"flex",flexDirection:"column",alignItems:"center"}}>

        <AppBar position='sticky'>
          <Toolbar sx={{justifyContent:"space-between"}}>
            {globalUserContext?(
              <>
                <IconButton onClick={openingMenu} size="large" edge="start"  >
                  <MenuIcon sx={{color:"white" , fontSize:40}}/>
                </IconButton>
                <Typography variant='h4'>Simple GPT</Typography>
                <Typography variant='h5'>
                  <IconButton onClick={()=>{
                    if(globalThemeContext=="dark"){
                      dispatchThemeContext({type:"LIGHT"})
                    }else if(globalThemeContext=="light"){
                      dispatchThemeContext({type:"DARK"})
                    }
                  }} size="large" edge="start"  >
                    {globalThemeContext=="dark"?
                    <Brightness7Icon sx={{color:"white" , fontSize:40}}/>:
                    <BedtimeIcon sx={{color:"white" , fontSize:40}}/>
                    }
                  </IconButton>
                  Hello {globalUserContext.username}👋</Typography>
              </>
            ):(
              <>
                <IconButton onClick={openingMenu} size="large" edge="start"  >
                  <MenuIcon sx={{color:"white" , fontSize:40}}/>
                </IconButton>
                <Typography variant='h4'>Simple GPT</Typography>
                <Box sx={{display:"flex",columnGap:"1rem"}}>
                <IconButton onClick={()=>{
                    if(globalThemeContext=="dark"){
                      dispatchThemeContext({type:"LIGHT"})
                    }else if(globalThemeContext=="light"){
                      dispatchThemeContext({type:"DARK"})
                    }
                  }} size="large" edge="start"  >
                    {globalThemeContext=="dark"?
                    <Brightness7Icon sx={{color:"white",backgroundColor:"#0096ff" , fontSize:40}}/>:
                    <BedtimeIcon sx={{color:"white",backgroundColor:"#0096ff" , fontSize:40}}/>
                    }
                  </IconButton>
                  <Button  sx={{color:"white",px:"1rem"}} onClick={clickingLogin}>Login</Button>
                  <Button  sx={{color:"white",px:"1rem"}} onClick={clickingSignup}>Signup</Button>
                </Box>
              </>
            )}
            
          </Toolbar>  
        </AppBar>

        
        
      </CustomBox>
      

      <Backdrop
        sx={(theme) => ({ color: '#fff', zIndex: theme.zIndex.drawer + 1 })}
        open={isOpen}
      >
        <Drawer anchor='left' sx={{paddingTop:0}} variant={isOpen?"permanent":""} >
          <List sx={{p:5}}>
            <ListItem sx={{alignItems:"flex-end", flexDirection:"row-reverse"}}>
              <IconButton edge="end" onClick={ClosingMenu} >
                <KeyboardDoubleArrowLeftIcon  sx={{ fontSize:40}}/>
              </IconButton>
            </ListItem>
            {listItem}
          </List>
        </Drawer>
      </Backdrop>
    </Backdrop>
  </> 
  
  )
}else if(globalCurrentPageContext=="history"){
  return (
    <>
      <CustomBox sx={{minHeight:"100vh",display:"flex",flexDirection:"column",alignItems:"center"}}>

        <AppBar position='sticky'>
          <Toolbar sx={{justifyContent:"space-between"}}>
            {globalUserContext?(
              <>
                <IconButton onClick={openingMenu} size="large" edge="start"  >
                  <MenuIcon sx={{color:"white" , fontSize:40}}/>
                </IconButton>
                <Typography variant='h4'>Simple GPT</Typography>
                <Typography variant='h5'>
                <IconButton onClick={()=>{
                    if(globalThemeContext=="dark"){
                      dispatchThemeContext({type:"LIGHT"})
                    }else if(globalThemeContext=="light"){
                      dispatchThemeContext({type:"DARK"})
                    }
                  }} size="large" edge="start"  >
                    {globalThemeContext=="dark"?
                    <Brightness7Icon sx={{color:"white" , fontSize:40}}/>:
                    <BedtimeIcon sx={{color:"white" , fontSize:40}}/>
                    }
                    </IconButton> 
                  Hello {globalUserContext.username}👋</Typography>
              </>
            ):(
              <>
                <IconButton onClick={openingMenu} size="large" edge="start"  >
                  <MenuIcon sx={{color:"white" , fontSize:40}}/>
                </IconButton>
                <Typography variant='h4'>Simple GPT</Typography>
                <Box sx={{display:"flex",columnGap:"1rem"}}>
                <IconButton onClick={()=>{
                    if(globalThemeContext=="dark"){
                      dispatchThemeContext({type:"LIGHT"})
                    }else if(globalThemeContext=="light"){
                      dispatchThemeContext({type:"DARK"})
                    }
                  }} size="large" edge="start"  >
                    {globalThemeContext=="dark"?
                    <Brightness7Icon sx={{color:"white" , fontSize:40}}/>:
                    <BedtimeIcon sx={{color:"white" , fontSize:40}}/>
                    }
                  </IconButton>
                  <Button  sx={{color:"white",backgroundColor:"red",px:"1rem"}} onClick={clickingLogin}>Login</Button>
                  <Button  sx={{color:"white",backgroundColor:"red",px:"1rem"}} onClick={clickingSignup}>Signup</Button>
                </Box>
              </>
            )}
            
          </Toolbar>  
        </AppBar>

        
        <History Data={dataToPass}/>
  

        
      </CustomBox>
      

      <Backdrop
        sx={(theme) => ({ color: '#fff', zIndex: theme.zIndex.drawer + 1 })}
        open={isOpen}
      >
        <Drawer anchor='left' sx={{paddingTop:0}} variant={isOpen?"permanent":""} >
          <List sx={{p:5}}>
            <ListItem sx={{alignItems:"flex-end", flexDirection:"row-reverse"}}>
              <IconButton edge="end" onClick={ClosingMenu} >
                <KeyboardDoubleArrowLeftIcon  sx={{ fontSize:40}}/>
              </IconButton>
            </ListItem>
            {listItem}
          </List>
        </Drawer>
      </Backdrop>
  </> 
  )
}else{
  return (
    <>
      <CustomBox sx={{minHeight:"100vh",display:"flex",flexDirection:"column",alignItems:"center"}}>

        <AppBar position='sticky'>
          <Toolbar sx={{justifyContent:"space-between"}}>
            {globalUserContext?(
              <>
                <IconButton onClick={openingMenu} size="large" edge="start"  >
                  <MenuIcon sx={{color:"white" , fontSize:40}}/>
                </IconButton>
                <Typography variant='h4'>Simple GPT</Typography>
                <Typography variant='h5'>
                <IconButton onClick={()=>{
                    if(globalThemeContext=="dark"){
                      dispatchThemeContext({type:"LIGHT"})
                    }else if(globalThemeContext=="light"){
                      dispatchThemeContext({type:"DARK"})
                    }
                  }} size="large" edge="start"  >
                    {globalThemeContext=="dark"?
                    <Brightness7Icon sx={{color:"white" , fontSize:40}}/>:
                    <BedtimeIcon sx={{color:"white" , fontSize:40}}/>
                    }
                  </IconButton>
                  Hello {globalUserContext.username}👋</Typography>
              </>
            ):(
              <>
                <IconButton onClick={openingMenu} size="large" edge="start"  >
                  <MenuIcon sx={{color:"white" , fontSize:40}}/>
                </IconButton>
                <Typography variant='h4'>Simple GPT</Typography>
                <Box sx={{display:"flex",columnGap:"1rem"}}>
                <IconButton onClick={()=>{
                    if(globalThemeContext=="dark"){
                      dispatchThemeContext({type:"LIGHT"})
                    }else if(globalThemeContext=="light"){
                      dispatchThemeContext({type:"DARK"})
                    }
                  }} size="large" edge="start"  >
                    {globalThemeContext=="dark"?
                    <Brightness7Icon sx={{color:"white" , fontSize:40}}/>:
                    <BedtimeIcon sx={{color:"white" , fontSize:40}}/>
                    }
                  </IconButton>
                  <Button  sx={{color:"white",backgroundColor:"red",px:"1rem"}} onClick={clickingLogin}>Login</Button>
                  <Button  sx={{color:"white",backgroundColor:"red",px:"1rem"}} onClick={clickingSignup}>Signup</Button>
                </Box>
              </>
            )}
            
          </Toolbar>  
        </AppBar>

        <NewSession>
        </NewSession>
   
      </CustomBox>
      

      <Backdrop
        sx={(theme) => ({ color: '#fff', zIndex: theme.zIndex.drawer + 1 })}
        open={isOpen}
      >
        <Drawer anchor='left' sx={{paddingTop:0}} variant={isOpen?"permanent":""} >
          <List sx={{p:5}}>
            <ListItem sx={{alignItems:"flex-end", flexDirection:"row-reverse"}}>
              <IconButton edge="end" onClick={ClosingMenu} >
                <KeyboardDoubleArrowLeftIcon  sx={{ fontSize:40}}/>
              </IconButton>
            </ListItem>
            {listItem}
          </List>
        </Drawer>
      </Backdrop>
  </> 
  )
}
}

export default HomePage