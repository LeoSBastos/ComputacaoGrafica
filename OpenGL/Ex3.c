#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926535898

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
}

void drawTijolo25D()
{
    glBegin(GL_POLYGON);
    glColor3f(0.545, 0.0, 0.0);
    glVertex3f(-1.0,0.0,0.0);
    glVertex3f(0, -0.5, 0.0);
    glVertex3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.5, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 0.0, 0.0);
    glVertex3f(-1.0,0.0,0.0);
    glVertex3f(-1.0,-0.33,0.0);
    glVertex3f(0, -0.83, 0.0);
    glVertex3f(0.0, -0.5, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.862, 0.078, 0.235);
    glVertex3f(1.0,0.0,0.0);
    glVertex3f(-1.0,-0.33,0.0);
    glVertex3f(0, -0.83, 0.0);
    glVertex3f(0.0, -0.5, 0.0);
    glEnd();
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    drawTijolo25D();
    glPopMatrix();
    glutSwapBuffers();
}

void main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tijolo Isometrico 2.5D");
    init(); 
    glutDisplayFunc(display);
    glutMainLoop();
}