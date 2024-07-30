import { useState } from "react";
import toast from "react-hot-toast";
import { AiOutlineEye , AiOutlineEyeInvisible } from "react-icons/ai";
import { Link, useNavigate } from "react-router-dom";

const LoginForm = ({setIsLoggin}) => {
    const [fromData , setFromData] = useState(
        {
            email:"",
            password:""
        }
    )

    const [showPassword , setShowPassword] = useState(false)

    const naviget = useNavigate();

    function changHandlaer(event){
        setFromData( (prevData) => {
           return {
            ...prevData,
            [event.target.name] : event.target.value
           }
        })
    }

    function submitHandaler(event){
        event.preventDefault();
        setIsLoggin(true);
        toast.success("Loggied in");
        naviget("/dashboard");
    }
    
    return (


        <from onSubmit = {submitHandaler}>
            <label>
                <p>Email Address <sup>*</sup></p>
                <input
                 required
                 type="email"
                 value={fromData.email}
                 onChange={changHandlaer}
                 placeholder="Enter email id"
                 name="email"
                />
            </label>

            <label>
                <p>Password <sup>*</sup></p>
                <input
                 required
                 type={showPassword ? ("text") : ("password")}
                 value={fromData.password}
                 onChange={changHandlaer}
                 placeholder="Enter password"
                 name="password"
                />

                <span onClick={() => setShowPassword((prev) => !prev)}>
                    {showPassword ? (<AiOutlineEyeInvisible/>) : (<AiOutlineEye/>)}
                </span>

                <Link to  = "#">forget password</Link>
            </label>

            <button>
                Sign In
            </button>
        </from>


    );
}

export default LoginForm;