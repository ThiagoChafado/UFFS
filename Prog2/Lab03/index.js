const express = require("express");
const bodyParser = require("body-parser");
const app = express();
const port = 3001;
const database = require("./database");



app.use(bodyParser.json());
app.listen(port,()=>{
    console.log("Server started at port 3001");
})

app.use(express.static(`${__dirname}/public`));

app.get("/",(req,res)=>{
    res.sendFile(`${__dirname}/index.html`);
})

app.get("/cursos",(req,res) =>{
    res.status(200).send(database.cursos);
})

app.get("/ccrs",(req,res)=>{
    res.status(200).send(database.ccrs);
})

app.post("/cursos",(req,res)=>{
    const curso = {
        "id": req.body.id,
        "nome": req.body.nome,
        "turno": req.body.turno,
        "id_campus": req.body.id_campus
    }
    database.cursos.push(curso);
    res.status(201).send("Class add");
})

app.post("/ccrs",(req,res)=>{
    const ccr = {
        "id": req.body.id,
        "nome": req.body.nome
    }
    database.ccrs.push(ccr);
    res.status(201).send("Ccr Add")
})


//delete by id
app.delete("/cursos",(req,res)=>{
    for(let i=0;i<database.cursos.length;i++){

        if(database.cursos[i].id == req.body.id){
            database.cursos.splice(i,1);
            res.send("Class removed");
        }
    }
        res.send("Not Found");
    
})

//delete by id
app.delete("/ccrs",(req,res)=>{
    for(let i=0;i<database.ccrs.length;i++){

        if(database.ccrs[i].id == req.body.id){
            database.ccrs.splice(i,1);
            res.send("Ccr removed");
        }
    }
        res.send("Not Found");
})

app.put("/cursos",(req,res)=>{
    for(let i=0;i<database.cursos.length;i++){

        if(database.cursos[i].id == req.body.id){
            database.cursos[i].nome = req.body.nome;
            database.cursos[i].turno = req.body.turno;
            database.cursos[i].id_campus = req.body.id_campus;
            res.send("Sucess");
        }
    }
    res.send("Not found");


})

app.put("/ccrs",(req,res)=>{
    for(let i=0;i<database.ccrs.length;i++){

        if(database.ccrs[i].id == req.body.id){
            database.ccrs[i].nome = req.body.nome;
            database.ccrs[i].turno = req.body.turno;
            database.ccrs[i].id_campus = req.body.id_campus;
            res.send("Sucess");
        }
    }
    res.send("Not found");



})





// para inserir na lista, use push:
// db.cursos.push({ ... })


// para remover da lista, use splice passando o índice do elemento e a quantidade de
// elementos a serem removidos. Exemnplo para remover o primeiro elemento:
// db.cursos.splice(0, 1) remove um elemento a partir do índice 0