const express = require("express");
const app = express();

require("dotenv").config();

const PORT = process.env.PORT || 4000;

// middlerwer to parse json requset body
app.use(express.json());

// import router for todo api
const todoRoute = require("./route/todo")

// mount the todo apis routes
app.use("/api/v1" , todoRoute);

// start server
app.listen(PORT , () => {
    console.log(`Server started at port number ${PORT}`);
})

// connection DB
const dbConnect = require("./config/database");
dbConnect();

// default route
app.get("/" , (req , res) => {
    res.send(`<h1>this is a home page </h1>`);
})

