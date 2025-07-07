import { Box, IconButton } from "@mui/material";
import React, { useState } from "react";
import SearchIcon from '@mui/icons-material/Search';
import ArrowCircleRightIcon from '@mui/icons-material/ArrowCircleRight';
import { useThemeContext } from "../hooks/useThemeContext";
const SearchBox = (props) => {
  const [text, setText] = useState("");

  const {globalThemeContext,dispatchThemeContext}=useThemeContext()

  const handleChange = (event) => {
    props.handleChange(event)
  };

  const handleResize = (event) => {
    // Reset height to auto to calculate scroll height
    event.target.style.height = "auto";
    // Set the height based on the scroll height (content height)
    event.target.style.height = `${event.target.scrollHeight}px`;
  };

  // const handleNewPrompt

  return (
<Box sx={{ display: "flex", alignItems: "end", width: "100%" }}>
      <textarea
        value={props.input}
        onChange={handleChange}
        onInput={handleResize}
        style={{
          
          borderRadius: "25px",
          width: "100%",
          height: "auto",
          padding: "10px",
          fontSize: "1.5rem",
          resize: "none", // Disable manual resize
          marginRight: "10px", // Space between textarea and icon
          overflow:"hidden",
          backgroundColor:globalThemeContext=="dark"?"rgb(68, 68, 68)":"#b5b5b5",
          color: globalThemeContext=="dark"?"white":"black"
        }}
      />
      <IconButton size="large" edge="end" onClick={props.onSearch}>
        <ArrowCircleRightIcon sx={{ color: globalThemeContext=="dark"?"white":"black", fontSize: 50 }} />
      </IconButton>
    </Box>
  );
};

export default SearchBox;
