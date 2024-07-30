// console.log("namshte duniya5");

// // fectory function

// function crateRec(length , breadth){
//     return rec = {
//         length : length,
//         breadth : breadth,

//         draw: function(){
//             console.log("drwing rec");
//         }
//     };
// }

// let rec1 = crateRec(5,10);
// let rec2 = crateRec(7,19);

// console.log(rec1.length);

// // constrcter function

// function Rectangle(){
//     this.length = 1;
//     this.breadth = 2;

//     this.draw = function(){
//         console.log('drwing');
//     }
// }

// let r = new Rectangle();
// // add 
// r.color = 'white';
// // delete
// delete r.color;
// console.log(r);

// // copy
// let a = 10;
// let b = a;
// a++;
// console.log(a);
// console.log(b);


// // refarence
// let a1 = {value:10};
// let b1 = a1;
// a1.value++;
// console.log(a1.value);
// console.log(b1);

// let n = {value:10};

// function inc(n){
//     n.value++;
// }
// inc(n);

// console.log(n);

// let rectangle = {
//     length : 2,
//     breadth : 4
// };

// // for(let key in rectangle){
// //     console.log(key , rectangle[key]);
// // }

// for(let key of Object.entries(rectangle)){
//     console.log(key);
// }

// let src = {
//     a : 10,
//     b : 20,
//     c : 30
// };

// let dest = {};

// for(let key in src){
//     dest[key] = src[key];
// }

// console.log(dest);
// src.a++;
// console.log(dest);

// let src = {
//     a : 10,
//     b : 20,
//     c : 30
// };

// let dest = Object.assign({} , src);

// console.log(dest);
// src.a++;
// console.log(dest);

// let src = {
//     a : 10,
//     b : 20,
//     c : 30
// };

// let dest = {...src};

// console.log(dest);
// src.a++;
// console.log(dest);

// let number = [1,2,3,4,5];

// console.log(number);

// console.log(number[0]);
// // end push
// number.push(9);
// // start push
// number.unshift(8);
// // middal push
// number.splice(2 , 0 , 'a','b','c');

// console.log(number);

// // serching
// console.log(number.indexOf(5));

// // find
// console.log(number.includes(5));


// Serching ref for callback function used
// let p = [
//     {no : 1, name: 'meet'},
//     {no : 2, name: 'pankaj'}
// ];

// let p1 = p.find(function(p){
//     return p.name = 'meet';
// })

// console.log(p1);

// let p = [
//     {no : 1, name: 'meet'},
//     {no : 2, name: 'pankaj'}
// ];

// let p1 = p.find(p1 => p1.name === 'meet')

// console.log(p1);

// remove - end - pop
// remove - begin - shift
// remove - middale - splice(index , no.of.ele.delete)

// let number = [1,2,3,4,5];
// number.pop();
// number.shift();
// number.splice(2 , 1);

// let a = [1,2,3];
// let b = [4,5,6];
// let c = [...a , ...b];
// console.log(c);


// let a = [1,2,3,4,5];
// for(let key of a){
//     console.log(key);
// }

// a.forEach(number => console.log(number));


// let fun = function run(){
//     console.log("running3");
// }

// fun();

function sum(...args){
    console.log(args);
}

sum(1,2,3,4,5);

