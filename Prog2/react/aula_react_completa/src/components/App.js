import Botoes from "./Botoes";
import Campotexto from "./Campotexto";
import Navbar from "./Navbar";

function App() {
  return (
    <>
      <h1>Hello World!</h1>
      <Navbar />
      <Botoes />
      <br/>
      <h1>Formulario</h1>
      <Campotexto label="Nome" placeholder="nome"/>
      <Campotexto label="Email" placeholder="email"/>
      <Campotexto label="Curso" placeholder="curso"/>
      
    </>
  );
}

export default App;
