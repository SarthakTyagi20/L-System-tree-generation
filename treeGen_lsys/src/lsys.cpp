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
    for (int i = 0; i < food.length(); i++) {
        char feeding = food[i];

        switch(feeding){

            case 'F':
            turt.draw();
            break;

            case '+':
            turt.RotateTurtle(theta);
            break;

            case '-':
            turt.RotateTurtle(-theta);
            break;

            case '[':
            turt.save_Pos();
            break;

            case ']':
            turt.retrieve_Pos();
            break;

            default:
            break;
        }
    }
}