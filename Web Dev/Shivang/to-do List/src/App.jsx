import { useState } from 'react'
import NewTaskForm from './components/NewTaskForm';
import Task from './components/Task';
import "./index.css"

function App() {
  const [title,setTitle]=useState('');
  const [description,setDescription]=useState('');
  const [tasks, setTasks] = useState([])
  const onSubmit=function(e){
    e.preventDefault()
    setTasks([...tasks,{title,description}]);
    console.log(tasks,elements);
  }
  const elements=tasks.map((task,id)=>{
    return <Task key={id} title={task.title} description={task.description}/>
  })
  return (
    <>
      <NewTaskForm title={title} setTitle={setTitle} description={description} setDescription={setDescription} onSubmit={onSubmit} />
      <div className='tasksContainer'>{elements}</div>
    </>
  )
}

export default App
