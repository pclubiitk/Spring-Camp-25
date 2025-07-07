import { Box } from '@mui/material';
import React from 'react'

const ChatBox = ({ markdown, isClient }) => {
    return (
      <Box className={`flex ${isClient ? 'justify-start' : 'justify-end'}`} >
        <div className={`bg-blue-500 text-white px-4 py-2 rounded-xl max-w-sm 
          ${isClient ? 'rounded-bl-none' : 'rounded-br-none'}`} style={{marginBottom:"1rem",padding:"1rem",display:"inline-table"}} dangerouslySetInnerHTML={{ __html: markdown }} />

      </Box>
    );
  };

export default ChatBox