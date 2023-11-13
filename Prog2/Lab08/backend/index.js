const express = require("express");
const bodyParser = require("body-parser");
const app = express();
const port = 3001;
const cors = require("cors");

const pgp = require("pg-promise")({});
const usuario = "postgres";
const senha = "alicerce1";
const db = pgp(`postgres://${usuario}:${senha}@localhost:5432/prog2`);


app.listen(port, () => console.log("Server started at port 3001."));
app.use(cors());
app.use(express.json());
app.get("/", (req, res) => {
    res.send("Hello, world!");
});

app.get("/cursos", async (req, res) => {
    try {
        const cursos = await db.any("SELECT * FROM class;");
        console.log('Retornando todos os cursos.');
        res.json(cursos).status(200);
    } catch (error) {
        console.log(error);
        res.sendStatus(400);
    }
});

app.post("/cursos", async (req, res) => {
    try {
        const clienteNome = req.body.nome;
        const clienteEmail = req.body.email;
        console.log(`Nome: ${clienteNome} - Email: ${clienteEmail}`);
        db.none(
            "INSERT INTO class (classname, descr) VALUES ($1, $2);",
            [clienteNome, clienteEmail]
        );
        res.sendStatus(200);
    } catch (error) {
        console.log(error);
        res.sendStatus(400);
    }
});



    