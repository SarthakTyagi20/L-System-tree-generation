#include "turtle.h"
#include "cmath"

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
    float lineWidth[2];

    std::cout <<current_state.width <<"current width\n"; 
    glLineWidth(current_state.width);

    glBegin(GL_LINES);
    glColor3f(0.5f, 0.2f, 0.0f);
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
    if (state_stk.empty())
    {
        return;
    }
    State temp = state_stk.top();
    state_stk.pop();

    current_state.x = temp.x;
    current_state.y = temp.y;
    current_state.rotation = temp.rotation;
}

void Turtle::drawCircle()
{

    // std::cout <<" draw circle\n";
    GLfloat x, y, angle, curSize;
    float const Gl_Pi = M_PI;
    // glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.2f, 0.0f);

    for (angle = 0.0f; angle <= (2.0f * Gl_Pi); angle += 0.1f)
    {
        x = 4.0f * sin(angle) + current_state.x;
        y = 4.0f * cos(angle) + current_state.y;

        GLfloat x1 = 3.0f * sin(angle) + current_state.x;
        GLfloat y1 = 3.0f * cos(angle) + current_state.y;

        glVertex3f(x1, y1, 0.0f);
        glVertex3f(x, y, 0.0f);
    }

    glEnd();
}

void Turtle::drawTriangle() {

    // glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.8f, 0.0f); 
    

    glVertex3f(current_state.x + 5.0f, current_state.y, 0.0f);
    glVertex3f(current_state.x - 5.0f, current_state.y, 0.0f);
    glVertex3f(current_state.x + 5.0f, current_state.y, 0.0f);
    glVertex3f(current_state.x, current_state.y + 5.0f, 0.0f);
    glVertex3f(current_state.x - 5.0f, current_state.y, 0.0f);
    glVertex3f(current_state.x, current_state.y + 5.0f, 0.0f);

    glEnd();

}

void Turtle::changeWidth(int temp){

    // std::cout << current_state.width << "im here\n";  
    if(temp == 0){

        current_state.width *= branch_contractio_ratio;
        // std::cout << "inside if " << c/urrent_state.width << " \n";

    }
    
}
