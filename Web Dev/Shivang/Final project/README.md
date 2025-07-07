# Final Project Summary

## The Two Users on Same Browser Problem

### Problem Explanation
During development, a major issue arose due to the difference in how `sessionStorage` and cookies are stored in the browser:

- **sessionStorage**: Stored on a per-tab basis. Each tab has a unique session storage, even when visiting the same site.
- **Cookies**: Stored on a per-origin basis. If cookies change in one tab, they change for all tabs with the same origin.

### Issue Faced
For example, consider two users `u1` and `u2`:
1. `u1` logs in and performs actions.
2. `u2` logs in on another tab of the same browser.
3. The cookies get updated for `u2`, affecting `u1` as well.
4. If `u1` requests data, the backend (which relies on cookies) may return data for `u2`, causing a security issue.

### Solution Implemented
To resolve this issue, **userContext** and **sessionContext** were sent to the backend along with cookies to verify user authenticity.

---

## Backend

### 1) `Database/db.go`
- Connected to the PostgreSQL database using GORM.
- GORM provides utility functions to interact with the database.
- The database object is passed to handler functions in `main.go`.

### 2) `Models/models.go` and `Models/jsonReq.go`

#### PostgreSQL’s Binary JSON Format (JSONB)
PostgreSQL provides two ways to store JSON data:
- **JSON**: Stores raw JSON text (slower for queries).
- **JSONB**: Stores binary JSON format (optimized for indexing and queries).

#### JSONB Storage Mechanism
- Parses JSON text.
- Converts it into a structured binary format.
- Removes whitespace and duplicate keys.
- Sorts object keys lexicographically (e.g., `{"b":1,"a":2}` is stored as `{"a":2,"b":1}`).

#### GORM Integration
We used the **Scan and Value** functions in `Models/models.go` to handle JSONB storage.

### 3) Controllers
#### a) `HistoryControllers.go`
- **Paths**: `/getAllTalksOfAUser`, `/downloadTheTalks`, `/getAllTalksOfASession`
- **Functions**:
  1. `GetTalksOfASessionForDownloadPurpose`: Generates a temporary Markdown file on the server, sends it to the client, and deletes it.
  2. `GetAllTalksOfASession`: Used in `app.jsx` to counter webpage refresh issues.
  3. `GetSessionsOfAUser`: Retrieves a user's session history with authentication.

#### b) `PromptControllers.go`
- **Paths**: `/createPrompt`
- **Functions**:
  1. `GettingQueriesAnswer`: Fetches user query responses from the **Groq API** via Resty.

#### c) `SessionControllers.go`
- **Paths**: `/createSession`, `/setSession`
- **Functions**:
  1. `CreateSession`: Triggered when a user clicks "New Session" in the sidebar. It verifies tokens and userContext.
  2. `SessionSetter`: Provides context for an existing session.

#### d) `UserController.go`
- **Paths**: `/login`, `/signup`, `/logout`
- **Functions**:
  1. `LogIn`: Verifies returning users and sets cookies (causing the same-browser issue).
  2. `SignUp`: Creates a new user with a hashed password.
  3. `Logout`: Expires cookies.

---

## Frontend

### 1) Components
#### a) `ChatBox`
- Renders chat bubbles for replies and questions.

#### b) `CustomBox`
- A wrapper over MUI's Box component to inherit styles.

#### c) `Form`
- Basic login and signup form component.

#### d) `HistoryCards`
- Displays user history cards.

#### e) `SearchBox`
- Built on top of an HTML `<textarea>` for auto-height adjustment.

### 2) Context
#### a) `currentPageContext`
- Manages the active page view.
- The homepage is always displayed, with subpages rendered based on `currentPageContext`.
- Key values:
  - `history`: Displays the history subpage.
  - `newsession`: Prompts the user to create a new session.

#### b) `queryContext`
- Stores all chats in a session.
- Sent to the backend to maintain chat context for Groq API queries.
- Used to display session chats.

#### c) `sessionContext`
- Tracks session ID stored in `sessionStorage` and cookies.
- Sent to the backend to verify message authenticity.

#### d) `themeContext`
- Tracks the website theme.

#### e) `userContext`
- Tracks the currently logged-in user.
- Helps verify users and prevent session conflicts.

### 3) Hooks
Contains functions that return values from `ContextProviders`.

### 4) Pages
#### a) `experimentPage`
- Used for testing during development.

#### b) `HomePage`
- Core layout visible to users most of the time.

#### c) `LoginPage`
- Handles user login.

#### d) `SignupPage`
- Handles user registration.

---

## Conclusion
This project tackled key challenges in session management, user authentication, and frontend-backend communication. The two-user issue was resolved using **userContext** and **sessionContext**, ensuring session integrity even when multiple users share the same browser.

