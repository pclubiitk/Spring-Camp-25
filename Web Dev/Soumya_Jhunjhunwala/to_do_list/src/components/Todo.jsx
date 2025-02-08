function Todo(props) {
    return (
<li className="todo stack-small">
            <div className="c-cb">
              <input id={props.id} type="checkbox" defaultChecked = {props.completed} />
              <label className="todo-label" htmlFor={props.id}>
                {props.name}
              </label>
            </div>
            <div className="btn-group">
              <button type="button" className="btn">
                Edit <span className="visually-hidden">Eat</span>
              </button>
              <button type="button" className="btn btn__danger">
                Delete <span className="visually-hidden">Eat</span>
              </button>
            </div>
</li>
    );
}

export default Todo;