
const Card = (props) => {
  return (
    <div className='Card'>
        <img src={props.src} alt={props.name} />
        <h1>{props.name}</h1>
    </div>
  )
}

export default Card