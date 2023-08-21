const price = (value,payment) =>{
    if(payment == 2){
        let plus = value * 0.10;
        return value + plus;
    }else{
        let plus2 = value * 0.05
        return value - plus2;
    }
}

let value = parseFloat(prompt("Preço do produto:"));
let payment = parseInt(prompt("Forma de pagamento:"));
console.log("Preço final:"+price(value,payment));