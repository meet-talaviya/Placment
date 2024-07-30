import freamImage from "../assets/frame.png"
import LoginForm from "./LoginForm";
import SignupFrom from "./SignupFrom";

const Templet = ({ title, des1, des2, image, formentype, setIsLoggin }) => {
    return (
        <div>
            <div>
                <h1>{title}</h1>
                <p>
                    <span>{des1}</span>
                    <span>{des2}</span>

                </p>

                {formentype === "signup" ? (<SignupFrom setIsLoggin={setIsLoggin} />) : <LoginForm setIsLoggin = {setIsLoggin}/>}

                <div>
                    <div></div>
                    <p>OR</p>
                    <div></div>
                </div>

                <button>SignUp with google</button>
            </div>

            <div>
                <img src={freamImage} alt="fatten" width={558} height={584} loading="lazy" />

                <img src={image} alt="student" width={558} height={490} loading="lazy" />

            </div>
        </div>
    );
}

export default Templet;