function calculate(hours,value){
    let salary=0;
    if(hours >200){
        salary = hours * value;
        let bonus = salary * 0.05
        return salary + bonus;
    }
    return hours*value;
}


let hours = prompt("Digite o número de horas trabalhadas");
let value = prompt("Digite o valor de cada hora");
console.log("Salário:"+calculate(hours,value));
