#include "turtle.h"

void Turtle::translate(int new_x, int new_y)
    {
        current_state.x = new_x; 
        current_state.y = new_y;
    }

void Turtle::setTheta(float theta)
    {
        current_state.rotation = theta;
    }

void Turtle::draw()
    {

        int a = current_state.x + (int)(len * cos(current_state.rotation));
        int b = current_state.y + (int)(len * sin(current_state.rotation));

        glBegin(GL_LINES);
            glVertex3f(current_state.x, current_state.y, 0.0f);
            glVertex3f(a, b, 0.0f);
        glEnd();
        
        
        current_state.x = a;
        current_state.y = b;
    }

void Turtle::RotateTurtle(float angle)
    {
        current_state.rotation += angle;
    }

void Turtle::save_Pos()
    {
        state_stk.push(current_state);
    }

void Turtle::retrieve_Pos()
    {
        if (state_stk.empty()) {
            return;
        }
        State temp = state_stk.top();
        state_stk.pop();

        current_state.x = temp.x;
        current_state.y = temp.y;
        current_state.rotation = temp.rotation;
    }