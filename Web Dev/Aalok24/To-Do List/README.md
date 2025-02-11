## how it works
- you can enter name in input field.
- Clicking the "Add" button adds the text as a new todo item.
- The newly added todo appears at the top of the list.
- The input field is cleared after adding a todo.

## Code Explanation
  - `useState` is used to manage the `todos` array and the `text` input field.
  - `createInitialTodos()`: Initializes an empty array for todos.
  - `setTodos([...todos])`: Updates the todo list by adding new items at the beginning.
  - `setText("")`: Clears the input field after adding a todo.

  - Each todo item is rendered inside an ordered list (`<ol>`), using its `id` as a key.

