import React from "react";
import axios from "axios";


axios.defaults.baseURL = "http://localhost:3001/";
axios.defaults.headers.common["Content-Type"] =
  "application/json;charset=utf-8";
function Table6() {
  const [listSchedules, setListSchedule] = React.useState([]);

  React.useEffect(() => {
    const res = axios.get("/schedule");
    res.then((query) => {
      setListSchedule(query.data);
      console.log(query.data);
      
    });
  }, []);


  return (
    <div id="cc6" className="container-lg">
      <div className="row">
      <th scope="col" ><h1>Sexto semestre - Noturno</h1></th>
      </div>
      <div className="row">
        <div className="col-4">
      
        </div>
      </div>
      <div className="row">
        {listSchedules.length > 0 && (
          <table className="table">
            <thead>
              <tr >

                <th scope="col" >Segunda</th>
                <th scope="col" >Terça</th>
                <th scope="col" >Quarta</th>
                <th scope="col" >Quinta</th>
                <th scope="col" >Sexta</th>
              </tr>
            </thead>

            <tbody>
              {listSchedules && 
               listSchedules.map((schedule,index)=>
               <tr key={index}>
                
               <th scope="row" >{schedule.nameClass[25]}</th>
               <th scope="row" >{schedule.nameClass[26]}</th>
               <th scope="row" >{schedule.nameClass[27]}</th>
               <th scope="row" >{schedule.nameClass[28]}</th>
               <th scope="row" >{schedule.nameClass[29]}</th>

               
               <td></td>
             </tr>
               )}
            </tbody>
          </table>
        )}
      </div>
    </div>
  );
}
export default Table6