
import Image from './logo.png';
import './style.css';
function Header (){
    return (
        <header>
        <img src={Image} alt="logos" class="logo"></img>
        <h1>UNIVERSIDADE FEDERAL DA FRONTEIRA SUL </h1>
      </header>
    );
}
export default Header;