
import { useState } from "react"

const InputPokemon=function (props){
    const [demandedPokemon,setDemandedPokemon]=useState("")
    
    const func=async function (e){
        e.preventDefault()
        console.log(demandedPokemon)
        const pokemonData=await fetch("https://pokeapi.co/api/v2/pokemon/"+demandedPokemon)
        const json=await pokemonData.json()
        props.adderFunction(json)
        console.log(pokemonData,json);
    }

    return (
        <form onSubmit={func} style={{marginBottom:"1rem"}}>
            <label>Pokemon name:
                <input type="text" value={demandedPokemon} onChange={(e)=>{setDemandedPokemon(e.currentTarget.value)}}/>
            </label>
            <button>Add Pokemon</button>
        </form>
    )
}

export default InputPokemon