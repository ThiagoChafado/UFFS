const express = require("express");
const bodyParser = require("body-parser");
const app = express();
const port = 3001;
app.use(bodyParser.json());
app.listen(port, () => console.log("Server started on port 3001"));

app.get ("/", (req,res) => {
    res.send("Hello World!");
});

app.post("/put", (req,res) => {
    const name = req.body.name;
    res.send("Hello "+name);
});