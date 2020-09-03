#include <GL/freeglut.h>
#include <stdlib.h>
#include <unistd.h>

void init(void)
{
    //Fundo (branco)
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
void drawQuadrado(float r, float b, float g)
{
    glBegin(GL_POLYGON);
    glColor3f(r / 255.0, g / 255.0, b / 255.0);
    glVertex2f(-1, 1);
    glVertex2f(1, 1);
    glVertex2f(1, -1);
    glVertex2f(-1, -1);
    glEnd();
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    while (1)
    {
        for (float r = 0; r < 255; r++)
        {
            for (float g = 0; g < 255; g++)
            {
                for (float b = 0; b < 255; b++)
                {
                    drawQuadrado(r, g, b);
                    sleep(10000000);
                }
            }
        }
    }
    glPopMatrix();
    glutSwapBuffers();
}
void main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(256, 256);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Quadrado RGB");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}