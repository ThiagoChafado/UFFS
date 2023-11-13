import React from "react";

import './App.css';
import Header from './components/Header/Header';
import NavBar from './components/NavBar/Navbar';
import Table from './components/Table/Table';
import Table2 from './components/Table2/Table2';
import Table3 from './components/Table3/Table3';
import Table4 from './components/Table4/Table4';
import Table5 from './components/Table5/Table5';
import Table6 from './components/Table6/Table6';
import Table7 from './components/Table7/Table7';
import Table8 from './components/Table8/Table8';
import Table9 from './components/Table9/Table9';
import Footer from './components/Footer/Footer';
import Button from './components/Button/Button';
import Cliente from './components/Cliente';

function App() {
  const [clienteSelecionado, setClienteSelecionado] = React.useState();
  return (

    <div className="App">
      <div ClassName="container-sm">
      <Header/>
      <NavBar/>
      <Button/>
      <Table/>
      <Cliente/>
      <br/>
      <br/>
      <br/>
    

      <Footer/>

      </div>
      
    </div>
  );
}


export default App;
