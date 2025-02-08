import { useState } from "react"

const NewTaskForm = (props) => {
  return (
    <form style={{marginBottom:"2rem",display:"flex",flexDirection:"column", alignItems:"center", rowGap:"5px"}} onSubmit={props.onSubmit}>

        <label className="inp">Title: <input type="text" value={props.title} onChange={(e)=>{ props.setTitle(e.currentTarget.value)}} /></label>
        <label className="inp">Decription: <input type="text" value={props.description} onChange={(e)=>{ props.setDescription(e.currentTarget.value)}} /></label>

        
        <button>Add Task</button>
    </form>
  )
}

export default NewTaskForm