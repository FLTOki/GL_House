#include<Windows.h>       
#include<GL\glut.h> 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GLFW/glfw3.h>
GLFWwindow* window;



//void drawCrescentLine(float step, float scale, float fullness) {
//    float angle = 0.0f;
//    while (angle < M_PI) {
//        glVertex2f(scale * sinf(angle), scale * cosf(angle));
//        angle += step;
//    }
//    while (angle < (2.0f * M_PI)) {
//        glVertex2f(fullness * scale * sinf(angle), scale * cosf(angle));
//        angle += step;
//    }
//    glVertex2f(0.0f, scale);
//}

void init()
{
    
    //glClearColor(0.5, 0.9, 0.4, 0.0);
    glClearColor(1, 1, 1, 0.0);   
    glMatrixMode(GL_PROJECTION);    
    gluOrtho2D(0.0, 800, 0.0, 600);
}

void home()
{
    //Roof
    //glClear(GL_COLOR_BUFFER_BIT);    
    glColor3f(1.0f, 1.0f, 1.0f);
    //glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(120, 410);  //adjusts height/top vertix
    glVertex2i(700, 410);
    glVertex2i(700, 350);
    glVertex2i(120, 350); //for bottom vertix
    glEnd();  

    // semi-circle roof
    int center_x = 400;          //centering the axes
    int center_y = 400;
    int radius = 150;            // roof's radius
    int diameter = 300;           // roof's diameter
    float PI = 3.141592653589793238f;
    float circle_angle = PI * 1.0f;
    int steps = 100;
    glBegin(GL_TRIANGLE_FAN);

    for (int i = 0; i < steps; i++) {
        float theta = circle_angle * float(i) / float(steps);    // the circle angle
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x + center_x, y + center_y);
    }
    glEnd();            

    // Wall main
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2i(200, 350);
    glVertex2i(600, 350); //upper right
    glVertex2i(600, 100);
    glVertex2i(200, 100);
    glEnd();

    // Front Door
    glColor3f(0.2f, 0.4f, 0.3f);
    glBegin(GL_POLYGON);    
    glVertex2i(350, 320);
    glVertex2i(450, 320);
    glVertex2i(450, 100);
    glVertex2i(350, 100);
    glEnd();

    // Front Door Lock
    glColor3f(0.3f, 0.7f, 0.9f);
    glPointSize(15);
    glBegin(GL_POINTS);
    glVertex2i(270, 270);
    glEnd();

    // window 1
    glColor3f(0.2f, 0.4f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2i(220, 320);
    glVertex2i(340, 320);
    glVertex2i(340, 230);
    glVertex2i(220, 230);
    glEnd();

    // bars: window 1
    glColor3f(0.1f, 0.7f, 0.5f);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(280, 320);
    glVertex2i(280, 230);
    glVertex2i(220, 273);
    glVertex2i(340, 273);
    glEnd();

    // window 2
    glColor3f(0.2f, 0.4f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2i(460, 320);
    glVertex2i(580, 320);
    glVertex2i(580, 230);
    glVertex2i(460, 230);
    glEnd();

    // bars: window 2
    glColor3f(0.1f, 0.7f, 0.5f);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(520, 320);
    glVertex2i(520, 230);
    glVertex2i(460, 273);
    glVertex2i(580, 273);
    glEnd();  
       
    glFlush();
}

int main(int argc, char** argv)
{
    // Initialize GLUT
    glutInit(&argc, argv);
    // Set display mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   
    glutInitWindowPosition(100, 100);    
    glutInitWindowSize(900, 700);    
    glutCreateWindow("2D House");     
    init();
    
    glutDisplayFunc(home);
   
   
    glutMainLoop();
}

