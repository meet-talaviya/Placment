const express = require('express');
const app = express();

const bodyParser = require('body-parser');

// only json fromet data submited
app.use(bodyParser.json());


app.listen(3000, () => {
    console.log("Server Start at a 3000 number port");
});

// Route Create
app.get('/' , (req , res) => {
    res.send("Hello jee, kai she ho");
})

app.post('/api/car' , (req , res) => {
    const {name , brand} = req.body;
    console.log(name);
    console.log(brand);
    res.send("Submitted car sucessfully.");
})

// Using Node.js `require()`
const mongoose = require('mongoose');


mongoose.connect('mongodb://127.0.0.1:27017/test')
  .then(() => console.log('Connected!'));