import Templet from "../compo/Templet";
import loginImg from "../assets/login.png"

const Login = ({setIsLoggedIn}) => {
    return(
        <div>

            <Templet
            title="Welcome Back"
            des1="Build skills for today, tomorrow, and beyond."
            des2="Education to future-proof your career."
            image={loginImg}
            formentype="login"
            setIsLoggin={setIsLoggedIn}
            
            />

        </div>
    );
}

export default Login;