import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'
import React from 'react'

function App() {
const [taskList, settaskList] = useState([{ task:""}]); //here our state is an array of tasks.we add elements to the array dynamically
//when the button is pressed by concatinating new elements
//console.log(taskList)
const TaskAdd = () => {
settaskList([...taskList, { task: ""}]) //We can concatenate arrays using the Spread syntax(...)
}

const TaskRemove = (index) => {

  const list = [...taskList]; 
  list.splice(index, 1); //At position =index, splice method removes 1 element. This helps in removing the element task from the taskList array corresponding to which the remove button is clicked
  settaskList(list) 
}
const TaskChange=(e,index) =>
{
const{name,value}=e.target
const list = [...taskList];
list[index][name]=value;
settaskList(list);

}
/* Working of map
const numbers = [1, 2, 3, 4, 5];
const doubled = numbers.map((number) => number * 2);
console.log(doubled); 
basically the map method runs a specified function on each element of the input array and we get a new array of outputs.
*/
return (
<form>
<div>
<h1>Add and remove items from your To-Do list!</h1>
{taskList.map((singletask, index) => ( //from the list of tasks, I take a single task and its index in the taskList array
<div key={index} >
<div>
<br></br>
<button type="button" onClick={TaskAdd}>
Add a Task
</button>
<br></br>
<input name="service" type="text" id="mytask" placeholder="Type a task"
value={singletask.service}
onChange = {(e) => TaskChange(e, index)} />
</div>
<div className="second-division">
<button type="button"  onClick={() => TaskRemove(index)} >
Remove Task
</button>
<br></br>
</div>
</div>
))}
</div>
</form>
);
}
export default App;