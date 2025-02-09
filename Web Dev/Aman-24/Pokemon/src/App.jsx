import { useState } from "react";
import { useEffect } from "react";
function App(){

  const [pokemons,setPokemons]=useState([]);
    useEffect(() => {
      fetch('https://pokeapi.co/api/v2/pokemon/')
        .then(response => response.json())
        .then(json => {
          setPokemons(json.results)
          console.log(json.results)
        })
    }, []);
    const list=pokemons.map((data)=>{
      return <div key={data.name}>
        {data.name}
      </div>
    })
    return (
      <div>
        {list}
      </div>
    );
}
export default App