import logo from "../assets/Logo.svg"
import { Link } from "react-router-dom";
import Home from "../pages/Home";
import toast from "react-hot-toast";


const Navbar = (props) => {
    let isLoggin = props.isLoggin;
    let setIsLoggin = props.setIsLoggin;
   
    return (
        <div className="flex gap-3 justify-evenly">
            <Link to="/">
                <img src={logo} alt="logo" width={160} height={32} loading="lazy" />
            </Link>

            <nav >
                <ul className="flex gap-3">
                    <li>
                        <Link to="/">Home</Link>
                    </li>
                    <li>
                        <Link to="/">About</Link>
                    </li>
                    <li>
                        <Link to="/">Contact</Link>
                    </li>
                </ul>
            </nav>

            <div className="flex ml-6 gap-3">
                {
                    !isLoggin && 
                    <Link to="/login">
                        <button>
                            Login
                        </button>
                    </Link>
                }

                {
                    !isLoggin && 
                    <Link to="/signup">
                        <button>
                            Signup
                        </button>
                    </Link>
                }

                {
                    isLoggin &&
                    <Link to="/">
                        <button onClick={() => {
                            setIsLoggin(false);
                            toast.success("Logged out");
                        }}>
                            Log out
                        </button>
                    </Link>
                }

                {
                    isLoggin &&
                    <Link to="/dashboard">
                        <button>
                            Dashboard
                        </button>
                    </Link>
                }
            </div>
        </div>
    );

}

export default Navbar;