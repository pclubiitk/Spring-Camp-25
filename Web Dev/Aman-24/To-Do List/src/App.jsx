import { useRef } from 'react'
import { useState } from 'react'





function App() {
  const [count, setCount] = useState([])
  
  const inputref = useRef()
  const addtodo=()=>{
    const todo=inputref.current.value
    if(todo.trim()){
      setCount([...count,todo])
      inputref.current.value=''
    }
  }
  const deletetodo=(index)=>{
    const newtodo=[...count]
    newtodo.splice(index,1)
    setCount(newtodo)
  }

  return (
    <>
      <div className="cont">
        <div className="box">
          <div className="box1">
            <h1>iTask - Manage your Todos at one place</h1></div>
          <div><h2 id="heading">Add a Todo</h2></div>
          <div className="input"><input type="text" className='input1' ref={inputref} />
            <button className='btn1' onClick={addtodo}>Save</button>
          </div>
          <div>
            <hr className='hr' /></div>

          <div className="main">
            <h2>Your Todos</h2>
          </div>
          <div className="todos">
              { count.map((count,index)=>(
                <div key={index} className='flex'><ul>
                  <li>{count}</li>
                  </ul>
                  <button className="delete" onClick={()=>deletetodo(index)}></button></div>
              ))}
          </div>
        </div>
      </div>
    </>
  )
}

export default App
