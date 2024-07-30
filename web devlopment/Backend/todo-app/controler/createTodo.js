// import todo
const Todo = require("../model/todo");

// define route handler
exports.createTodo = async(req , res) => {
     try{
        // title and description fecth in req
        const {title , description} = req.body;
        // create a new todo object and insert in db
        const response = await Todo.create({title , description});
        // send a json response with a sucess flag
        res.status(200).json(
            {
                success:true,
                data:response,
                message:"Entry Created Sucessfully"
            }
        );
     }
     catch(err){
        console.error(err);
        console.log(err);
        res.status(500)
        .json(
            {
                success:false,
                data:"Internal server error",
                message:err.message
            }
        )
     }
}