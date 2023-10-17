const express = require("express");
const bodyParser = require("body-parser");
const app = express();
const port = 3001;
const database = require("./database");
const cors = require("cors");

app.listen(port, () => console.log("Server started at port 3001."));
app.use(cors());
app.use(express.json());
app.get("/", (req, res) => {
    res.send("Hello, world!");
});

app.get("/class", (req, res) => {
    try {
        res.json(database.class).status(200);
    } catch (error) {
        console.log(error);
        res.sendStatus(400);
    }
});

app.get("/schedule", (req, res) => {
    try {
        res.json(database.schedule).status(200);
    } catch (error) {
        console.log(error);
        res.sendStatus(400);
    }
});

    