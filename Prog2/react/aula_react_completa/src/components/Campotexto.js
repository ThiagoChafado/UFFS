function Campotexto(props){
    return (
        <div>
            <label>{props.label}</label>
            <input placeholder={`Digite seu ${props.placeholder}`}></input>
        </div>
    );
}

export default Campotexto;