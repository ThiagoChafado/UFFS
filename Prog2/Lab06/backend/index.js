const express = require("express");
const bodyParser = require("body-parser");
const app = express();
const port = 3001;
const database = require("./database");
const cors = require("cors");

app.listen(port, () => console.log("Server started at port 3001."));
