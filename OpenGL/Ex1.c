#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926535898

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
}

void drawPoligon()
{
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(-1.0, -1.0, 0.0);
    glVertex3f(-1.0, 1.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(1.0, -1.0, 0.0);
    glEnd();
}
void drawEmptyCircle()
{

    GLfloat circle_points = 100.0f;

    GLfloat angle, raioX = 0.5f, raioY = 0.5f;

    glBegin(GL_LINE_STRIP);
    glColor3f(1.0, 0.0, 0.0);

    for (int i = 0; i < circle_points; i++)
    {

        angle = 2 * PI * i / circle_points;

        glVertex2f(cos(angle) * raioX, sin(angle) * raioY);
    }

    glEnd();
}

void drawCircle()
{
    GLfloat circle_points = 100.0f;

    GLfloat angle, raioX = 0.5f, raioY = 0.5f;

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);

    for (int i = 0; i < circle_points; i++)
    {

        angle = 2 * PI * i / circle_points;

        glVertex2f(cos(angle) * raioX, sin(angle) * raioY);
    }

    glEnd();
}
void drawElipse()
{
    GLfloat circle_points = 100.0f;

    GLfloat angle, raioX = 1.0f, raioY = 0.5f;

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);

    for (int i = 0; i < circle_points; i++)
    {

        angle = 2 * PI * i / circle_points;

        glVertex2f(cos(angle) * raioX, sin(angle) * raioY);
    }

    glEnd();
}
void drawPizza()
{
    GLfloat circle_points = 100.0f;

    GLfloat angle, raioX = 0.5f, raioY = 0.5f;

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);

    for (int i = 0; i < 30; i++)
    {

        angle = 2 * PI * i / circle_points;

        glVertex2f(cos(angle) * raioX, sin(angle) * raioY);
    }
    glVertex2f(0.0,0.0);
    glEnd();
}
void drawBow()
{
    GLfloat circle_points = 100.0f;

    GLfloat angle, raioX = 1.0f, raioY = 0.5f;

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);

    for (int i = 0; i < 50; i++)
    {

        angle = 2 * PI * i / circle_points;

        glVertex2f(cos(angle) * raioX, sin(angle) * raioY);
    }
    glVertex2f(0.0,0.0);
    glEnd();
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    //drawPoligon();
    drawEmptyCircle();
    //drawCircle();
    //drawElipse();
    //drawPizza();
    //drawBow();
    glPopMatrix();
    glutSwapBuffers();
}

void main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Desenho Primitivo");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}