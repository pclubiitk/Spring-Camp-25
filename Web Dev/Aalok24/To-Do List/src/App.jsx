import { useState } from "react";
import "./App.css";

function createInitialTodos() {
  const initialTodos = [];
  return initialTodos;
}

export default function TodoList() {
  const [todos, setTodos] = useState(createInitialTodos);
  const [text, setText] = useState("");

  return (
    <div className="body">
      <div className="header">
        <input value={text} onChange={(e) => setText(e.target.value)} />
        <button
          onClick={() => {
            setText("");
            setTodos([
              {
                id: todos.length,
                text: text,
              },
              ...todos,
            ]);
          }}
        >
          Add
        </button>
      </div>
      <ol>
        {todos.map((item) => (
          <li key={item.id}>{item.text}</li>
        ))}
      </ol>
    </div>
  );
}
