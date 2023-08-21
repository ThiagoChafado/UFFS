function result(){
    negativeAcumulator = 0;
    positiveAcumulator = 0;
    for(let i =1;i<=4;i++){
        let number = parseFloat(prompt("Digite N"+i));
        if (number >= 0){
            positiveAcumulator++;
        }else if(number<0){
            negativeAcumulator++;
        }
    }
    console.log("Positivos:"+positiveAcumulator+" , Negativos:"+negativeAcumulator);
}   
result();