import Templet from "../compo/Templet";
import signupImg from "../assets/signup.png"

const Signup = (setIsLoggedIn) => {
    return(
        <div>

            <Templet
                title="Join the millions learning to code with StudyNotion for free"
                des1="Build skills for today, tomorrow, and beyond."
                des2="Education to future-proof your career."
                image={signupImg}
                formentype="signup"
                setIsLoggin={setIsLoggedIn}
            
            />

        </div>
    );
}

export default Signup;