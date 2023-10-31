import { Box, Stack } from "@mui/material";
import React from "react";

function Cliente(props) {
    return (
        <Box>
            {props.cliente && (
                <Stack direction="row" spacing={2}>
                    <Box>
                        <b>#: </b>
                        {props.cliente.id}
                    </Box>
                    <Box>
                        <b>Nome: </b>
                        {props.cliente.nome}
                    </Box>
                    <Box>
                        <b>E-mail: </b>
                        {props.cliente.email}
                    </Box>
                </Stack>
            )}
        </Box>
    );
}

export default Cliente;
