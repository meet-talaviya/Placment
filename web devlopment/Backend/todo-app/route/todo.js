const express = require("express");
const router = express.Router();

// import controller
const {createTodo} = require("../controler/createTodo")

// defind API router
router.post("createTodo" , createTodo);

module.exports = router;