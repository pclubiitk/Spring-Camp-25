
const Task = (props) => {
  return (
    <div className="Task">
        <div>
            <strong>Title:</strong>{props.title}
        </div>
        <div>
            <strong>decription:</strong>{props.description}
        </div>
    </div>
  )
}

export default Task