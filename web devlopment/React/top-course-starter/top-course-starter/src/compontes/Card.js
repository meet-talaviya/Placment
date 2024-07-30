import { FcLike } from "react-icons/fc";


function Card(props){
    let coures = props.coures;

    return(
        <div>
            <div>
                <div>

                <img src={coures.image.url}></img>
                </div>

                <div>
                    <button>
                       <FcLike frontSize="1.75rem" />    
                    </button>
                </div>

            </div>

            <div>
                <p>{coures.title}</p>
                <p>{coures.description}</p>
            </div>
        </div>
    );

}

export default Card;
