import React from "react";
import axios from "axios";


axios.defaults.baseURL = "http://localhost:3001/";
axios.defaults.headers.common["Content-Type"] =
  "application/json;charset=utf-8";
function Table() {
  const [listSchedules, setListSchedule] = React.useState([]);

  React.useEffect(() => {
    const res = axios.get("/schedule");
    res.then((query) => {
      setListSchedule(query.data);
      console.log(query.data);
      
    });
  }, []);


  return (
    <div id="cc1" className="container-lg">
      <div className="row">
      <th scope="col" ><h1>Primeiro semestre - Noturno</h1></th>
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
                
               <th scope="row" >{schedule.nameClass[0]}</th>
               <th scope="row" >{schedule.nameClass[1]}</th>
               <th scope="row" >{schedule.nameClass[2]}</th>
               <th scope="row" >{schedule.nameClass[3]}</th>
               <th scope="row" >{schedule.nameClass[4]}</th>

               
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
export default Table