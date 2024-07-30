import  CounterSlice  from "./Slices/counterSlice";
import { configureStore } from "@reduxjs/toolkit";

export const store = configureStore({
    reducer: {
        counter: CounterSlice
    },
})