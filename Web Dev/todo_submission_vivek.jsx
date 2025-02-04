import React, { useState, useEffect } from "react";
function Todo() {
  const [tasks, setTasks] = useState([]);
  const [newTask, setNewTask] = useState("");
  useEffect(() => {
    fetch("https://dummyjson.com/todos")
      .then((response) => response.json())
      .then((data) => {
        setTasks(data.todos);
      })
  }, []); 
  function add() {
    fetch("https://dummyjson.com/todos/add", {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({
        todo: newTask,
        completed: false,
        userId: 5,
      }),
    })
      .then((res) => res.json())
      .then((newTask) => {
        setTasks((prevTasks) => [...prevTasks, newTask]);
      })
  }
  function delet(id) {
    fetch(`https://dummyjson.com/todos/1`, {
      method: "DELETE",
    })
      .then((res) => res.json())
      .then(() => {
        setTasks((prevTasks) => prevTasks.filter((task) => task.id !== id));
      })
  }
  return (
    <div>
      <h1>To Do List</h1>
      <ol type="1">
        {tasks.map((task) => (
          <li key={task.id}>
            {task.todo}{<input type="checkbox" id="complete"></input>} {<button class="button1" onClick={() => delet(task.id)}>Delete</button>}
          </li>
        ))}
      </ol>
      <input
        type="text" class="input" value={newTask} onChange={(e) => setNewTask(e.target.value)} placeholder="Write task to add"/>
      <button onClick={add} class="button2">Add Task</button>
    </div>
  );
}
export default Todo;
