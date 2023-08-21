function calculator(x,y){
    let sum = 0;
    for(let i = 1;i<=y;i++){
        sum = sum + x;
    }
    return sum;
}

let x = parseInt(prompt("Digite o primeiro valor: "));
let y = parseInt(prompt("Digite o segundo valor: "));

console.log("Resultado:"+calculator(x,y));