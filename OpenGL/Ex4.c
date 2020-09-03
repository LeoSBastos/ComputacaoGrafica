#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926535898

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    gluOrtho2D(-20, 20, -35, 15);
}

void drawTijolo25D(float x,float y,float w,float h, float r, float g, float b)
{
    float altura=(w/2);
    glBegin(GL_POLYGON);
    glColor3f(r, g, b);
    glVertex3f(x-w,y,0.0);
    glVertex3f(x, y-altura, 0.0);
    glVertex3f(x+w, y, 0.0);
    glVertex3f(x, y+altura, 0.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0, 0, 0);
    glVertex3f(x-w,y,0.0);
    glVertex3f(x,y-altura, 0.0);
    glVertex3f(x+w, y, 0.0);
    glVertex3f(x,y+altura, 0.0);
    glVertex3f(x-w,y,0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(r*0.6, g*0.6, b*0.6);
    glVertex3f(x-w,y,0.0);
    glVertex3f(x-w,y-h,0.0);
    glVertex3f(x, y-(altura+h), 0.0);
    glVertex3f(x, y-altura, 0.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(r*0.6, g*0.6, b*0.6);
    glVertex3f(x+w,y,0.0);
    glVertex3f(x+w,y-h,0.0);
    glVertex3f(x, y-(altura+h), 0.0);
    glVertex3f(x, y-altura, 0.0);
    glEnd();
}
void drawCanvas(){
     float heigth3D = 2.0, width = 4.0, propWiHe = 1.0; // Proporçao entre largura e altura
    //Cores normalizadas
    float   R = 255.0/255.0;
    float   G = 0.0/255.0;
    float   B = 0.0/255.0;

    float  R2 = R*0.35, G2 = G*0.35, B2 = B*0.35;// Cor dos losandos sem altura

    glClear(GL_COLOR_BUFFER_BIT);


    // Losangos dir baixo-direita1
    drawTijolo25D( 0.0*width,  0.0*width, width, heigth3D, R, G, B);// Losango base(0,0)
    drawTijolo25D( 1.0*width, -0.5*width, width, heigth3D, R, G, B);
    drawTijolo25D( 2.0*width, -1.0*width, width, heigth3D, R, G, B);
    drawTijolo25D( 3.0*width, -1.5*width, width, heigth3D, R, G, B);
    
    // Losangos dir baixo-direia2
    drawTijolo25D(-1.0*width, -0.5*width, width, heigth3D,  R, G, B);
    drawTijolo25D( 0.0*width, -(1.0*width+heigth3D), width, 0.0, R2, G2, B2); // "+heigth3", para tirar a altura
    drawTijolo25D( 1.0*width, -1.5*width, width, heigth3D,  R, G, B);
    drawTijolo25D( 2.0*width, -2.0*width, width, heigth3D,  R, G, B);

    // Losangos dir baixo-direia3
    drawTijolo25D(-2.0*width, -1.0*width, width, heigth3D, R, G, B);
    drawTijolo25D(-1.0*width, -(1.5*width+heigth3D), width, 0.0, R2, G2, B2); // "+heigth3", para tirar a altura
    drawTijolo25D( 0.0*width, -(2.0*width+heigth3D), width, 0.0, R2, G2, B2); // "+heigth3", para tirar a altura
    drawTijolo25D( 1.0*width, -2.5*width, width, heigth3D, R, G, B);

    // Losangos dir baixo-direita4
    drawTijolo25D(-3.0*width,   -1.5*width, width, heigth3D, R, G, B);
    drawTijolo25D(-2.0*width,   -2.0*width, width, heigth3D, R, G, B);
    drawTijolo25D(-1.0*width,   -2.5*width, width, heigth3D, R, G, B);
    drawTijolo25D( 0.0*width,   -3.0*width, width, heigth3D, R, G, B);
 
    
    glFlush();
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    drawCanvas();
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