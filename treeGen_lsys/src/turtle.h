#ifndef TURTLE_H
#define TURTLE_H

#include <GLFW/glfw3.h>
#include <stack>
// #include <Stack.h>
#include <iostream>
#include <math.h>
using namespace std;


class State{

    public:
        int x;
        int y;
        float rotation;

};

class Turtle
{
private:
    int len;
    State current_state;
    stack<State> state_stk;
    float pi = 3.1415;

public:

    Turtle()
    {
        len = 10; 
        current_state.rotation = pi/2; 
    }

    void translate(int new_x=0, int new_y=0);

    void save_Pos();

    void retrieve_Pos();

    void setTheta(float theta=0);

    void RotateTurtle(float angle=0);

    void draw();
};

#endif