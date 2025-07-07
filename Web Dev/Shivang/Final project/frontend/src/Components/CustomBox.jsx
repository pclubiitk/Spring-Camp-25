import { Box } from '@mui/material';
import { styled } from '@mui/system';

const CustomBox = styled(Box)(({ theme }) => ({
  backgroundColor: theme.palette.background.paper,
}));

export default CustomBox;