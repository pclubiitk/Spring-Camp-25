import React, { useState, useEffect } from 'react';
import Atask from './Atask';
import './style.css';

function Alltasks() {


    const [alltasks, Setall] = useState([]);//FOR API UNCOMMENT IT
    // const [alltasks, Setall] = useState(() => JSON.parse(localStorage.getItem("tasks")) || []); //FOR LOCAL STORAGE FORM UNCOMMENT IT

    const [todo, setnew] = useState("");
    const [Name, setName] = useState("");

// FOR API START  //FOR API FORM UNCOMMENT BELOW FORM

    async function getAllTasks() {
        try {
            const response = await fetch('https://dummyjson.com/todos');
            const data = await response.json();
            Setall(data.todos);
        } catch {
            console.log("SORRY THERE IS SOME PROBLEM");
        }
    }

    useEffect(() => {
        getAllTasks();
       
    }, []);
   

    const deletea = (id) => {
        const updatedData = alltasks.filter((task) => task.id !== id);
        Setall(updatedData);
    };

    const addNew = () => {
        if(todo.trim() == "")
        {
            alert("TASK CANNOT BE EMPTY")
            return
        }
      
        const newTask = { id: alltasks.length + 1, todo }; 
        Setall((prevTasks) => [...prevTasks, newTask]);
        alert("NICE ,YOU HAVE ADDED A NEW TASK")
        setnew(""); // Clear input after adding
    };

// FOR API END





//FOR LOCAL STORAGE FORM UNCOMMENT BELOW CODE

//    //FOR LOCAL STORAGE START
//     useEffect(() => {
//         const savedTasks = JSON.parse(localStorage.getItem("tasks")) || [];
//         Setall(savedTasks);
//     }, []);

//     useEffect(() => {
//         localStorage.setItem("tasks", JSON.stringify(alltasks));
//     }, [alltasks]);

   
//     const deletea = (id) => {
//         const updatedData = alltasks.filter((task) => task.id !== id);
//         Setall(updatedData);
//     };


//     const addNew = () => {
//         if (todo.trim() === "") return;

//         const newTask = { id: Date.now(), todo };
//         Setall((prevTasks) => [...prevTasks, newTask]);
//         setnew(""); 
//     };

//    //FOR LOCAL STORAGE END












    
    const handle = (event) => {
        setnew(event.target.value);
    };

    return (
        <div div className='all'>
            <div className='addtask'>
                <input 
                    type='text' 
                    placeholder='ADD A NEW TASK' 
                    value={todo} 
                    onChange={handle} 
                />
                <button onClick={addNew}>ADD</button>
            </div>
          
            <h3 style={{marginTop:"2rem",fontWeight:"bold"}}>Success isn’t about doing everything; it’s about doing the right things at the right time. Your day is your canvas—plan it wisely, prioritize what matters, and watch your goals come to life. This task manager is your tool to stay organized, focused, and unstoppable. Let’s turn your to-do list into a journey of accomplishments!" It’s engaging and encourages users to take charge of their plan</h3>
            <div className='list'>

            {alltasks.map((task) => (
                <Atask key={task.id} function={() => deletea(task.id)} title={task.todo} />
            ))}
            </div>
       </div>
    );
}

export default Alltasks;
