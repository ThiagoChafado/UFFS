import * as React from 'react';
import Stack from '@mui/material/Stack';
import Button from '@mui/material/Button';
import Snackbar from '@mui/material/Snackbar';
import MuiAlert from '@mui/material/Alert';
import {useState} from 'react';

const Alert = React.forwardRef(function Alert(props, ref) {
  return <MuiAlert elevation={6} ref={ref} variant="filled" {...props} />;
});

export default function Alert1() {
  const [open, setOpen] = React.useState(false);

  const handleClick = () => {
    setOpen(true);
  };

  const handleClose = (event, reason) => {
    if (reason === 'clickaway') {
      return;
    }
    setOpen(false);
  };
  const [title,setTitle] = useState("Follow");

  function changeTitle(){
    if (title == "Follow"){
      setTitle("Following");
      console.log("Recebi follow");

    }else{
      setTitle("Follow");
      console.log("Recebi unfollow");
    }
  }

  return (
    <Stack spacing={2} sx={{ width: '100%'
      }}>
      <Button variant="outlined" onClick={changeTitle} sx={{
        color: 'white',
        bgcolor: (title === 'Follow') ? 'gray' : 'blue',
        ':hover':{
          color: 'white',
          bgcolor: (title === 'Follow') ? 'gray' : 'blue',
        }
      }}>
        {title}
      </Button>

      <Snackbar open={open} autoHideDuration={6000} onClose={handleClose}>
        <Alert onClose={handleClose} severity="success" sx={{ width: '100%',bgcolor:'gray'}}>
          Você está seguindo
        </Alert>
      </Snackbar>
    </Stack>
  );
}