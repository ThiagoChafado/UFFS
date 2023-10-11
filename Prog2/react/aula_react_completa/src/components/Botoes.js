import { useEffect, useState } from "react";

function Botoes() {
  let contador = 0;

  function contadorNormal() {
    contador = contador + 1;
  }

  const [contadorStateA, setContadorStateA] = useState(0);
  const [contadorStateB, setContadorStateB] = useState(0);

  function contadorComStateA() {
    setContadorStateA(contadorStateA + 1);
  }

  useEffect(function(){
    console.log("Roda a cada renderização");
  });

  useEffect(function(){
   console.log("Roda quando count state A for alterado"); 
  },[contadorStateA]);


  return (
    <div className="container row">
      <div className="col">
        <p>Contador normal: {contador}</p>
        <button type="button" class="btn btn-danger" onClick={contadorNormal}>
          Contador normal
        </button>
      </div>
      <div className="col">
        <p>Contador com State: {contadorStateA}</p>
        <button
          type="button"
          class="btn btn-success"
          onClick={contadorComStateA}
        >
          {" "}
          Contador com State{" "}
        </button>
      </div>
    </div>
  );
}
export default Botoes;
