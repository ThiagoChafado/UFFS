let value = 1;
let validNumbers = 0;
let numbers=0;
while(true){

    let value = parseInt(prompt("Digite um número(0 ou menor encerra a digitação):"));
    if (value <=0){
        break;
    }
    if(value >=10 && value <=20){
        validNumbers++;
    }
    numbers++;

}
let result = (validNumbers/numbers) * 100;
console.log(result+"%");