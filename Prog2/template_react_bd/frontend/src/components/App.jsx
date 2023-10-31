import React from "react";
import axios from "axios";

import Container  from "@mui/material/Container";
import CssBaseline  from "@mui/material/CssBaseline";
import Grid  from "@mui/material/Unstable_Grid2";
import Stack  from "@mui/material/Stack";

import Titulo from "./Titulo";
import Table from "./Table";
import Cliente from "./Cliente";

axios.defaults.baseURL = "http://localhost:3010/";
axios.defaults.headers.common["Content-Type"] =
    "application/json;charset=utf-8";

function App() {
    const [clienteSelecionado, setClienteSelecionado] = React.useState();
    const [listaClientes, setListaClientes] = React.useState([]);

    React.useEffect(() => {
        const res = axios.get("/clientes");

        res.then((query) => {
            setListaClientes(query.data);
            console.log(query.data);
        });
    }, []);

    return (
        <Container sx={{ flexGrow: 1 }} maxWidth="lg" >
            <CssBaseline />
            <Grid container justifyContent="center"  spacing={2}>
                <Grid  md={6}>
                    <Stack spacing={2}>
                        <Titulo mensagem={"Hello World of PostgreSQL!"} image='postgresql_logo.png' alternative='Logo do PostgreSQL.' />
                        <Cliente cliente={clienteSelecionado}/>
                        <Table clientes={listaClientes} onClientSelect={setClienteSelecionado}/>
                    </Stack>
                </Grid>
            </Grid>
        </Container>
    );
}

export default App;
