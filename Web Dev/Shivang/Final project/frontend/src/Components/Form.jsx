import React from 'react'
import Button from '@mui/material/Button';
import Typography from '@mui/material/Typography';
import { colors, TextField } from '@mui/material';
import { Link } from 'react-router-dom';
import { useThemeContext } from '../hooks/useThemeContext';

const Form = (props) => {
    const {globalThemeContext,dispatchThemeContext}=useThemeContext()
    const components=props.inputs.map((inp,i)=>{
        return <TextField name={i} key={inp} value={props.feilds[i]} onChange={props.handleFeildChanges[i]}  required  label={inp} variant="outlined" />
    })
    
    const handleSubmit=async function(e){
        e.preventDefault()
        await props.onSubmit(e)
    }

    const linkStyle={textDecoration:"none",fontSize:"1.5rem" ,color:globalThemeContext=="dark"?"white":"black"}


    
    let classToApply="darkHistory"
    if (globalThemeContext=="dark"){
      classToApply="darkForm"
    }else{
      classToApply="lightForm"
    }

  return (
    <form className={classToApply} onSubmit={handleSubmit} style={{
        display:"flex",
        flexDirection:"column",
        rowGap:"0.5rem",
        boxShadow:"0 0 10px "+(globalThemeContext=="dark"? " #e7195a":" #e76519"),
        border:"2px solid "+(globalThemeContext=="dark"? " #e7195a":" #fe5d00"),
        justifyContent:"center",
        alignItems:"center",
        padding:"1rem",
        borderRadius:"1rem",
        width:"80%",
        color:(globalThemeContext=="dark"? "white":"black"),
        backgroundColor:(globalThemeContext=="dark"? "black":"white"),
    }}>
        <Typography variant='h4'>
            {props.formLable}
        </Typography>
        {components}
        {props.isLogin ?(
            <>
                <Button type='submit' variant='contained' >{props.submit}</Button>
                <div style={{display:"flex", flexDirection:"column",alignItems:"end",width:"100%"}}>
                    <Link style={linkStyle} to="/signup">New User!</Link>
                </div>
            </>   ):(
                <>
                    <Button type='submit' variant='contained' >{props.submit}</Button>
                    <div style={{display:"flex", flexDirection:"column",alignItems:"end",width:"100%"}}>
                        <Link style={linkStyle} to="/login">Already Registered</Link>
                    </div>
                </>
            )
        }
        {props.children}
    </form>
  )
}

export default Form