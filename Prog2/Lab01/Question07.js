function factorial(value){
    if(value==0){
        return 1;
    }else{
        return value*factorial(value-1);
    }
}

let value = parseInt(prompt("Digite o valor: "));
console.log("Resultado = "+factorial(value));