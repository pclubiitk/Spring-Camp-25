import { Card } from '@mui/material'
import { marked } from 'marked'
import React from 'react'
import { useThemeContext } from '../hooks/useThemeContext'

const HistoryCards = (props) => {
  const {globalThemeContext,dispatchThemeContext}=useThemeContext()
  let classToApply="darkHistoryBox"
  if (globalThemeContext=="dark"){
    classToApply="darkHistoryBox"
  }else{
    classToApply="lightHistoryBox"
  }
  return (
    <Card className={classToApply} sx={{display:"flex",flexDirection:"column",
    padding:"1rem"
    ,alignItems:"center",justifyContent:"center"}}  >
       {props.marked}
       {props.children}
    </Card>
  )
}

export default HistoryCards