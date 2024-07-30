import { useState } from "react";
import { AiOutlineEye , AiOutlineEyeInvisible } from "react-icons/ai";

const SignupFrom = () => {

    const [fromData, setFromData] = useState(
        {
            firstname: "",
            lastname: "",
            email: "",
            password: "",
            comfompassword: ""
        }
    )

    const [showPassword, setShowPassword] = useState(false)

    function changeHandaler(event) {
        setFromData((prevData) => {
            return {
                ...prevData,
                [event.target.name]: event.target.value
            }
        })
    }

    return (
        <div>
            <div>
                <button>
                    Student
                </button>

                <button>
                    Instctour
                </button>
            </div>

            <from>
                {/* first and last name */}

                <div>

                    <label>
                        <p>First Name<sup>*</sup></p>
                        <input
                            required
                            type="text"
                            name="firstname"
                            onChange={changeHandaler}
                            placeholder="first name"
                            value={fromData.firstname}
                        />
                    </label>

                    <label>
                        <p>Last Name<sup>*</sup></p>
                        <input
                            required
                            type="text"
                            name="lastname"
                            onChange={changeHandaler}
                            placeholder="last name"
                            value={fromData.lastname}
                        />
                    </label>

                </div>

                {/* email */}

                <label>
                    <p>Email Address<sup>*</sup></p>
                    <input
                        required
                        type="email"
                        name="email"
                        onChange={changeHandaler}
                        placeholder="Enter the email"
                        value={fromData.email}
                    />
                </label>

                {/* password and conformpassword */}

                <div>
                    <label>
                        <p>Create password<sup>*</sup></p>
                        <input
                            required
                            type={showPassword ? ("text") : ("password")}
                            name="password"
                            onChange={changeHandaler}
                            placeholder="password"
                            value={fromData.password}
                        />

                        <span onClick={() => setShowPassword((prev) => !prev)}>
                            {showPassword ? (<AiOutlineEyeInvisible />) : (<AiOutlineEye />)}
                        </span>

                    </label>

                    <label>
                        <p>Conform password<sup>*</sup></p>
                        <input
                            required
                            type={showPassword ? ("text") : ("password")}
                            name="Conform"
                            onChange={changeHandaler}
                            placeholder="conform"
                            value={fromData.comfompassword}
                        />

                        <span onClick={() => setShowPassword((prev) => !prev)}>
                            {showPassword ? (<AiOutlineEyeInvisible />) : (<AiOutlineEye />)}
                        </span>

                    </label>




                </div>

                <button>
                    Create Account
                </button>




            </from>
        </div>
    );
}

export default SignupFrom;