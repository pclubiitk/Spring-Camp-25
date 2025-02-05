import React from 'react'
import ('./style.css')


function Atask(props) {
  return (
    <div  className="aclss"style={{ backgroundColor: "rgb(120, 144, 136)", width: "30vw",margin:"auto",marginTop:"1rem",marginBottom:"1rem",padding:"0.5rem" ,borderRadius:"1rem",  border:" 2px solid black"}}>
      <p>{props.title}</p><br></br>
      <input type="checkbox" /><br></br>
      <button onClick={props.function} style={{backgroundColor:"rgb(174, 253, 227)",borderRadius: "0.5rem",border:" 2px solid black",widyh:"3rem",height:"1.5rem"}}>DELETE</button>
    </div>
  )
}

export default Atask
