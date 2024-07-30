import { Route, Routes } from "react-router-dom";
import "./App.css";
import Navbar from "./compo/Navbar"
import Home from "./pages/Home"
import Login from "./pages/Login"
import Signup from "./pages/Signup"
import Dashboard from "./pages/Dashboard"
import { useState } from "react";

function App() {
  const [isLoggin , setIsLoggin] = useState(false);
  return (
    <div>
      <Navbar isLoggin={isLoggin} setIsLoggin={setIsLoggin}>
        
      </Navbar>

      <Routes>
        <Route path="/" element={<Home></Home>}/>
        <Route path="/login" element={<Login setIsLoggin={setIsLoggin}></Login>} />
        <Route path="/signup" element={<Signup></Signup>} />
        <Route path="/dashboard" element={<Dashboard></Dashboard>} />
      </Routes>
    </div>
  );
}

export default App;
