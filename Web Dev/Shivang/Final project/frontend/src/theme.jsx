import { createTheme } from '@mui/material/styles';

const darkTheme = createTheme({
  palette: {
    mode: 'dark',
    primary: {
      main: '#90caf9',
    },
    secondary: {
      main: '#f48fb1',
    },
    background: {
      default: '#121212',
      paper: '#1e1e1e',
    },
    text: {
      primary: '#ffffff',
      secondary: '#b0bec5',
    },
    error: {
      main: '#ef5350',
    },
    warning: {
      main: '#ffa726',
    },
    info: {
      main: '#29b6f6',
    },
    success: {
      main: '#66bb6a',
    },
  },
  typography: {
    fontFamily: 'Roboto, Arial, sans-serif',
    h1: {
      fontSize: '2rem',
      fontWeight: 600,
    },
    h2: {
      fontSize: '1.75rem',
      fontWeight: 500,
    },
    body1: {
      fontSize: '1rem',
    },
  },
  components: {
    MuiButton: {
      styleOverrides: {
        root: {
          textTransform: 'none',
          borderRadius: '8px',
        },
      },
    },
    MuiPaper: {
      styleOverrides: {
        root: {
          backgroundColor: '#000',
        },
      },
    },
    MuiBox: {
        styleOverrides: {
        root: {
          backgroundColor: '#000',
          borderRadius: '8px',
          padding: '16px',
        },
      },
    },
    MuiTextField: {
        styleOverrides: {
          root: {
            backgroundColor: '#1e1e1e', // Dark background for text fields
            color:"#ffffff"
          },
        },
      },
      MuiInputBase: {
        styleOverrides: {
          root: {
            color: '#ffffff', // White text color
          },
          input: {
            '&::placeholder': {
              color: 'rgb(255, 0, 55)', // Custom placeholder color
              opacity: 1, // Ensure visibility
            },
          },
        },
      },
      MuiOutlinedInput: {
        styleOverrides: {
          root: {
            '& .MuiOutlinedInput-notchedOutline': {
              borderColor: 'rgb(0, 255, 98)', // Custom border color
            },
            '&:hover .MuiOutlinedInput-notchedOutline': {
              borderColor: 'rgb(229, 255, 0)', // Border color on hover
            },
            '&.Mui-focused .MuiOutlinedInput-notchedOutline': {
              borderColor: 'rgb(0, 255, 98)', // Border color when focused
            },
            "&.MuiInputBase-root.MuiFilled": {
                backgroundColor: "#333333", // Background when filled with text
            },
            "& .MuiSelect-select": {
                backgroundColor: "green", // Prevents unwanted changes when selecting
            },
          },
        },
      },
  },
  
});



const lightTheme = createTheme({
  palette: {
    mode: 'light',
    primary: {
      main: '#1976d2',
    },
    secondary: {
      main: '#d81b60',
    },
    background: {
      default: '#ffffff',
      paper: '#f5f5f5',
    },
    text: {
      primary: '#212121',
      secondary: '#757575',
    },
    error: {
      main: '#d32f2f',
    },
    warning: {
      main: '#f57c00',
    },
    info: {
      main: '#0288d1',
    },
    success: {
      main: '#388e3c',
    },
  },
  typography: {
    fontFamily: 'Roboto, Arial, sans-serif',
    h1: {
      fontSize: '2rem',
      fontWeight: 600,
    },
    h2: {
      fontSize: '1.75rem',
      fontWeight: 500,
    },
    body1: {
      fontSize: '1rem',
    },
  },
  components: {
    MuiButton: {
      styleOverrides: {
        root: {
          textTransform: 'none',
          borderRadius: '8px',
        },
      },
    },
    MuiPaper: {
      styleOverrides: {
        root: {
          backgroundColor:" #008cff",
        },
      },
    },
    MuiBox: {
      styleOverrides: {
        root: {
          backgroundColor: '#ffffff',
          borderRadius: '8px',
          boxShadow: '0px 2px 4px rgba(0, 0, 0, 0.1)',
        },
      },
    },
    MuiTextField: {
        styleOverrides: {
          root: {
            backgroundColor: '#ffffff', // Dark background for text fields
            color:"#000000"
          },
        },
      },
      MuiInputBase: {
        styleOverrides: {
          root: {
            color: '#000000', // White text color
          },
          input: {
            '&::placeholder': {
              color: 'rgb(255, 0, 55)', // Custom placeholder color
              opacity: 1, // Ensure visibility
            },
          },
        },
      },
      MuiOutlinedInput: {
        styleOverrides: {
          root: {
            '& .MuiOutlinedInput-notchedOutline': {
              borderColor: 'rgb(0, 153, 255)', // Custom border color
            },
            '&:hover .MuiOutlinedInput-notchedOutline': {
              borderColor: 'rgb(195, 0, 255)', // Border color on hover
            },
            '&.Mui-focused .MuiOutlinedInput-notchedOutline': {
              borderColor: 'rgb(0, 153, 255)', // Border color when focused
            },
            "&.MuiInputBase-root.MuiFilled": {
                backgroundColor: "#333333", // Background when filled with text
            },
          },
        },
      },
  },
  
});

export {darkTheme,lightTheme}



