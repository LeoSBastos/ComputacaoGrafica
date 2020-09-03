#include <GL/freeglut.h>
#include <stdlib.h>
void init(void)
{
    //Fundo (branco)
    glClearColor(0.0f , 0.0f, 0.0f, 1.0f);
}
void drawQuadrado(float x, float y, float l, float r, float g, float b){
    glBegin(GL_POLYGON);
    glColor3f(r,g,b);
    glVertex2f(x,y);
    glVertex2f(x+l,y);
    glVertex2f(x+l,y-l);
    glVertex2f(x,y-l);
    glEnd();
}
void drawQuadrados(){
    drawQuadrado(-1.0,1.0,1.0,1.0,0.0,0.0);
    drawQuadrado(0.0,1.0,1.0,1.0,1.0,0.0);
    drawQuadrado(-1.0,0.0,1.0,0.0,1.0,0.0);
    drawQuadrado(0.0,0.0,1.0,0.0,0.0,1.0);
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    drawQuadrados();
    glPopMatrix();
    glutSwapBuffers();
}
void main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(256, 256);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Quatro Quadrados");
    init(); 
    glutDisplayFunc(display);
    glutMainLoop();
}