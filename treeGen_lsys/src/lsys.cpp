#include "lsys.h"

//applying production rules 
string lsys::productionrules(char s){
    if(s == 'F')
        return "FF"; //when we have F we will replace it by 'FF'

    if(s == 'X') 
        return "F+[-F-XF-X][+FF][--XF[+X]][++F-X]"; //when we have "X" we will replace it by this string 
    
    else
        return "";
}

void lsys::create_sequence(string current, int depth, int current_depth)
        {
            string new_string;
        
    //in this function we are using the production rules to generate the string that will 
    //represent our tree in L-system form 
            if(current_depth >= depth) {
                genStr = current;
                return;
            }
     
            for (int i = 0; i < current.length(); i++) {
                new_string += productionrules(current[i]) + current[i]; 
            }
            
        //calling this recursive function to generate the strings 
            return create_sequence(new_string, depth, current_depth+1); 
        }

void lsys::visualise_sequence(string food)
{
    
    //here our string food is the final sequence
    //now we are feeding this string to the turtle to generate the string 
    
    float theta = 25.0; 
    Turtle turt;
    turt.translate(500, 0);

    int for_fruits = 0;
    bool trunk = true;
    
    for (int i = 0; i < food.length(); i++) {
        char feeding = food[i];

        if( feeding == 'X' && food[i+1] != '[' && for_fruits%5 == 0){
            //this is to generate the fruits 
            //we have this count of for_fruits, we have made this to restrict the count of the fruits
            
            // std::cout <<"in lsys.cpp";
            trunk = true;
            turt.drawCircle();
        }   
         else if(feeding == '['){
             
             //we are saaving the state of the turtle 
            turt.save_Pos();
            turt.changeWidth(0);
        } else if(feeding == ']'){
             
             //retriving position
            turt.retrieve_Pos();
            turt.changeWidth(0);
        }
        else if(feeding == 'F'){
            // std::cout <<"are we going here"; 
            //drawing forward 
            turt.draw();
        } 
        else if(feeding == '+'){
            turt.RotateTurtle(theta);
        } else if(feeding == '-'){
            turt.RotateTurtle(-theta);
        
        }
        // std::cout <<"out side of if";
        else if(feeding == 'X' && food[i+1]!= '[' && for_fruits%5 != 0){
            //we are making leaves to the tree 
            trunk = true;
            turt.drawTriangle(); 
        }
        for_fruits++;

    }
}
