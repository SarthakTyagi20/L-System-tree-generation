#include "lsys.h"

string lsys::productionrules(char s){
    if(s == 'F')
        return "FF";

    if(s == 'X') 
        return "F+[-F-XF-X][+FF][--XF[+X]][++F-X]";
    
    else
        return "";
}

void lsys::create_sequence(string current, int depth, int current_depth)
        {
            string new_string;

            if(current_depth >= depth) {
                genStr = current;
                return;
            }
            
            for (int i = 0; i < current.length(); i++) {
                new_string += productionrules(current[i]) + current[i]; 
            }

            return create_sequence(new_string, depth, current_depth+1); 
        }

void lsys::visualise_sequence(string food)
{
    float theta = 25.0; 
    Turtle turt;
    turt.translate(500, 0);

    int for_fruits = 0;
    bool trunk = true;
    
    for (int i = 0; i < food.length(); i++) {
        char feeding = food[i];

        if( feeding == 'X' && food[i+1] != '[' && for_fruits%5 == 0){
            // std::cout <<"in lsys.cpp";
            trunk = true;
            turt.drawCircle();
        }   
         else if(feeding == '['){
            turt.save_Pos();
            turt.changeWidth(0);
        } else if(feeding == ']'){
            turt.retrieve_Pos();
            turt.changeWidth(0);
        }
        else if(feeding == 'F'){
            // std::cout <<"are we going here"; 
            turt.draw();
        } 
        else if(feeding == '+'){
            turt.RotateTurtle(theta);
        } else if(feeding == '-'){
            turt.RotateTurtle(-theta);
        
        }
        // std::cout <<"out side of if";
        else if(feeding == 'X' && food[i+1]!= '[' && for_fruits%5 != 0){
            trunk = true;
            turt.drawTriangle(); 
        }
        for_fruits++;

    }
}
