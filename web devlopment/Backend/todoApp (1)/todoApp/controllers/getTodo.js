const Todo = require("../models/Todo");

exports.getTodo = async(req,res) => {
    try {
        // fecth all todoo item database
        const todos = await Todo.find({});
        // res 
        res.status(200).json(
            {
                success:true,
                data:todos,
                message:'data is fetched'
            }
        );
    }
    catch(err) {
        console.error(err);
        res.status(500)
        .json({
            success:false,
            error:err.message,
            message:"Server Error"
        });
        
    }
}

exports.getTodoById = async(req , res) => {
    try{
        // extract todo items basis on id
        const id = req.params.id;
        const todo = await Todo.findById({_id : id});

        // data for given id not found
        if(!todo){
            return res.status(400).json({
                success:true,
                message:"No data found for given id"
            });
        }else{
            return res.status(200).json({
                success:true,
                data:todo,
                message:`Todo ${id} data succesfully fecth`
            })
        }

    }
    catch(err){
        console.error(err);
        res.status(500)
        .json({
            success:false,
            error:err.message,
            message:"Server Error"
        });
    }
}