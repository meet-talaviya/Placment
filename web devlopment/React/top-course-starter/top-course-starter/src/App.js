import React, { useEffect, useState } from "react";
import {apiUrl , filterData} from "./data";
import Navbar from "./compontes/Navbar";
import Filter from "./compontes/Filter";
import Cards from "./compontes/Cards";
import { toast } from "react-toastify";
import Spinner from "./compontes/Spinner";

const App = () => {

  const [coures , setCoures] = useState([]);
  const [loding , setLoding] = useState(true);
 
  async function fetchdata(){
    setLoding(true);
    try{
      let res = await fetch(apiUrl);
      let output = await res.json();
      setCoures(output.data);
    }
    catch(error){
      toast.error("Network error");
    }
    setLoding(false);
  }

  useEffect(() => {
    fetchdata();
  },[]);
  

  return (
    <div>
       <div>
        <Navbar/>
       </div>

       <div>
        <Filter filterData = {filterData}/>
       </div>

       <div>
        {
          loding ? (<Spinner/>) : (<Cards coures = {coures}/>)
        }
       </div>
    </div>
  );
};

export default App;
