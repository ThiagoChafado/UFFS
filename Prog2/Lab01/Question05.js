const calculator = (value)=>{
    let sum = 0;
    for(let i=1;i<=value;i++){
        sum = sum + i;
    }
    return sum;
}


let value = parseInt(prompt("Digite o valor: "));
console.log("Soma:"+calculator(value));
