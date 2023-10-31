import Box from "@mui/material/Box";
import Typography from "@mui/material/Typography";
import Stack from "@mui/material/Stack";
import React from "react";

function Titulo(props) {
    return (
        <Box>
            <Stack
                direction="row"
                justifyContent="center"
                alignItems="center"
                spacing={4}
            >
                <Typography
                    variant="h3"
                    gutterBottom
                    style={{ fontSize: "28px" }}
                    sx={{ color: "primary.main" }}
                >
                    {props.mensagem}
                </Typography>
                {props.image && props.alternative && (
                    <img
                        src={props.image}
                        alt={props.alternative}
                        width={100}
                    />
                )}
            </Stack>
        </Box>
    );
}

export default Titulo;
