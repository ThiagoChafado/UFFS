import { useState } from "react";



function Button(){
    const [state, setState] = useState("Follow");

    function mudar(){
    setState("Following");
}

    return(
        
        <button type="button" onClick={mudar} class="btn btn-primary">{state}</button>
        
        
    );
}
export default Button;