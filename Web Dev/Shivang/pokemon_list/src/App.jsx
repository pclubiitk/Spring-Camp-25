import { useState } from "react"
import InputPokemon from "./components/InputPokemon"
import Card from "./components/card";
function App() {
  const [pokemonList,setPokemonList]=useState([]);
  const [addedIdList,setAddedIdList]=useState([])
  const adderFunction=function (data){
    if(!addedIdList.includes(data.id)){
      setAddedIdList([...addedIdList,data.id]);
      setPokemonList([...pokemonList,data]);
    }
  }
  const cardList=pokemonList.map((data)=>{
    return <Card key={data.id} src={data.sprites.front_default} name={data.name}/>
  })

  return (
    <>
      <InputPokemon adderFunction={adderFunction}/>
      <div className="pokemonContainer">
        {cardList}
      </div>
    </>
  )
}

export default App
