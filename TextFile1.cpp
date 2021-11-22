// Include standard headers
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Include GLEW
#include "include/GL/glew.h"
// Include GLFW
#include <GLFW/glfw3.h>
GLFWwindow* window;

// Include GLM
#include <glm/glm.hpp>
using namespace glm;


int width = 1200,
height = 740;
const double PI = 3.141592;
const float radius = 0.3;


void drawRightHalfCircle();
void drawRect();
void drawKnob();
void drawMoon();

void Draw() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    //x, y, width, height

    drawRect();
    drawRightHalfCircle();
    drawKnob();
    drawMoon();
    glFlush();
}
void Update() {

}
void drawRightHalfCircle()
{
    glColor3f(0.5f, 0.5f, 0.5f);
    glTranslatef(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= 30; i++) {
        double angle = PI * i / 30;
        double x = radius * cos(angle);
        double y = radius * sin(angle) + 0.4;
        glVertex2d(x, y);
    }
    glEnd();
}

void drawMoon() {
    float theta;
    int i;

    // Moon
    glColor3f(0.957f, 0.643f, 0.376f); // white moon
    // glColor3f(0,0,0); // black moon
    // glColor3f(0.255, 0.412, 0.714); // blue moon
    glBegin(GL_POLYGON);

    for (i = 0; i < 360; i++)
    {
        theta = i * 3.142f / 180;



        glVertex2f(0.6 + 0.13f * cos(theta), 0.8 + 0.13f * sin(theta));
    }

    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);

    for (i = 0; i < 360; i++)
    {
        theta = i * 3.142f / 180;



        glVertex2f(0.67f + 0.14f * cos(theta), 0.85f + 0.14f * sin(theta));

    }

    glEnd();
}

void drawKnob()
{
    glColor3f(0.173f, 0.173f, 0.643f);
    glTranslatef(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 30; i++) {
        double angle = 2 * PI * i / 30;
        double x = 0.015f * cos(angle) + 0.07f;
        double y = 0.015f * sin(angle) - 0.35f;
        glVertex2d(x, y);
    }
    glEnd();
}

void drawRect() {
    //main house

    //floor
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0.5f, -0.7f);
    glVertex2f(-0.5f, -0.7f);
    //glVertex2f(-0.5f, 0.2f);
    //glVertex2f(0.5f, 0.2f);
    glEnd();

    //left wall
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(-0.5f, 0.2f);
    glVertex2f(-0.5f, -0.7f);
    //glVertex2f(-0.5f, 0.2f);
    //glVertex2f(0.5f, 0.2f);
    glEnd();

    //right wall
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0.5f, 0.2f);
    glVertex2f(0.5f, -0.7f);
    //glVertex2f(-0.5f, 0.2f);
    //glVertex2f(0.5f, 0.2f);
    glEnd();


    //window one
    glBegin(GL_LINE_LOOP);
    //y-axis
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex2f(-0.3f, -0.1f);
    glVertex2f(-0.4f, -0.1f);
    glVertex2f(-0.4f, -0.2f);
    glVertex2f(-0.3f, -0.2f);
    glVertex2f(-0.3f, -0.0f);
    glVertex2f(-0.4f, -0.0f);
    glVertex2f(-0.4f, -0.1f);
    glVertex2f(-0.3f, -0.1f);
    //x-axis
    glVertex2f(-0.2f, -0.1f);
    glVertex2f(-0.3f, -0.1f);
    glVertex2f(-0.3f, -0.2f);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(-0.2f, -0.0f);
    glVertex2f(-0.3f, -0.0f);
    glVertex2f(-0.3f, -0.1f);
    glVertex2f(-0.2f, -0.1f);
    glEnd();

    //window one
    glBegin(GL_LINE_LOOP);
    //y-axis
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex2f(0.3f, -0.1f);
    glVertex2f(0.4f, -0.1f);
    glVertex2f(0.4f, -0.2f);
    glVertex2f(0.3f, -0.2f);
    glVertex2f(0.3f, -0.0f);
    glVertex2f(0.4f, -0.0f);
    glVertex2f(0.4f, -0.1f);
    glVertex2f(0.3f, -0.1f);
    //x-axis
    glVertex2f(0.2f, -0.1f);
    glVertex2f(0.3f, -0.1f);
    glVertex2f(0.3f, -0.2f);
    glVertex2f(0.2f, -0.2f);
    glVertex2f(0.2f, -0.0f);
    glVertex2f(0.3f, -0.0f);
    glVertex2f(0.3f, -0.1f);
    glVertex2f(0.2f, -0.1f);
    glEnd();


    //roof
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0.6f, 0.2f);
    glVertex2f(0.5f, 0.2f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(-0.6f, 0.2f);
    glVertex2f(-0.6f, 0.4f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0.6f, 0.2f);
    glVertex2f(0.6f, 0.4f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(-0.5f, 0.2f);
    glVertex2f(-0.6f, 0.2f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(-0.6f, 0.4f);
    glVertex2f(0.6f, 0.4f);
    glEnd();



    //door
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0.1f, -0.0f);
    glVertex2f(-0.1f, -0.0f);
    glVertex2f(-0.1f, -0.7f);
    glVertex2f(0.1f, -0.7f);
    glEnd();


    glFlush();
}




int main(void) {


    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1280, 680, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        Draw();
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}