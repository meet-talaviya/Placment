import Card from "./Card";
function Cards(props){
    let coures = props.coures;
    console.log("printing data");
    console.log(coures);

    function getCourses(){
        let allCourses = [];
        Object.values(coures).forEach(array => {
            array.forEach(couresData => {
                allCourses.push(couresData);
            })
        })
        return allCourses;
    }

    return(
        <div>
            {
                getCourses().map((coures) => {
                    <Card key={coures.id} course={coures}/>
                })
            }

            
        </div>
    );
}

export default Cards;