import { StrictMode } from 'react'
import { createRoot } from 'react-dom/client'
import './index.css'
import { UserContextProvider } from './context/userContext'
import { SessionContextProvider } from './context/sessionContext'
import { ThemeContextProvider } from './context/themeContext'
import { QueryContextProvider } from './context/queryContext'
import App from './App.jsx'
import { CurrentPageContextProvider } from './context/currentPageContext.jsx'

import { ThemeProvider, CssBaseline } from "@mui/material";

createRoot(document.getElementById('root')).render(
  
  <StrictMode>
    <CurrentPageContextProvider>
      <QueryContextProvider>
        <ThemeContextProvider>
          <SessionContextProvider>
            <UserContextProvider>
              
           
              <App />

            </UserContextProvider>
          </SessionContextProvider>
        </ThemeContextProvider>
      </QueryContextProvider>
    </CurrentPageContextProvider>
  </StrictMode>,
)
