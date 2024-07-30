import { useDispatch, useSelector } from "react-redux";
import { decrement, increment } from "../redux/Slices/counterSlice";

const Counter = () => {
    const count = useSelector((state) => state.counter.value);
    const dispatch = useDispatch();

    return(
        <div>
            <button onClick={() => dispatch(increment())}>
                inc
            </button>

            <br></br>
            <br></br>

            <div>{count}</div>

            <br></br>
            <br></br>

            <button onClick={() => dispatch(decrement())}>
                dec
            </button>
        </div>
    );
}

export default Counter;