import { useState } from 'react';

export function App() {
  const url =' https://pokeapi.co/api/v2/pokemon?limit=100&offset=0';
  const [pokemon, setPokemon] = useState([]);

  useState(() => {
    fetch(url)
      .then(response => response.json()) 
      .then(data => {
        setPokemon(data.results); 
      })
      .catch(error => console.error("Error fetching pokemons name:", error));
  }, []);

  return  (
    <div>
      <h1 >POKEMON</h1>
      {pokemon.map((pokemon, index) => (
        <p className="list_name" key={index}>{pokemon.name}</p> 
      ))}
    </div>
  );
}

