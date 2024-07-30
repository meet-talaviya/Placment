import { useState } from "react";

function Card({id , image ,info , price, name, removeTour} ){

    const [readMore , setReadmore] = useState(false);

    const desc =`${info.substring(0,200)}....`;

    function readMoreHandler(){
        setReadmore(!readMore);
    }


    return(

        <div className="card">
            <img src={image} className="image"></img>

            <div className="tour-info">

            <div className="tour-details">
                <h4 className="tour-price">{price}</h4>
                <h4 className="tour-name">{name}</h4>
            </div>

            <div className="des">
                {desc}
                <span className="read-more" onClick={readMoreHandler}>
                    {readMore ? `show less` : `read more`};
                </span>
            </div>

            </div>
         

            <button className="btn-red" onClick={() => removeTour(id)}>
                Not Interested
            </button>

        </div>

    
    );

}

export default Card;