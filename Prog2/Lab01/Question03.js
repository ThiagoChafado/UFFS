function duration (start,end){
    if(end <= start){
        return 24 + end - start;
    }else{
        return end - start;
    }
}



let start = parseInt(prompt("Início: "));
let end = parseInt(prompt("Fim: "));

console.log("Duração:"+duration(start,end));

