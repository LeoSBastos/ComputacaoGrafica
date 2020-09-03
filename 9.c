#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#define pi 3.1415926535898
#define true 1
#define false 0

int x, y;
int click = false;
int polygon;

// Raposinha__________________________________________________________//
void rabinho(){
    glBegin(GL_LINE_STRIP);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(37*12, 20*12);
        glVertex2d(30*12, 6*12);
        glVertex2d(37*12, 11*12);
        glVertex2d(37*12, 20*12);
    glEnd();
}
void corpinho(){
    glBegin(GL_LINE_STRIP);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(37*12, 20*12);
        glVertex2d(30*12, 26*12);
        glVertex2d(25*12, 11*12);
        glVertex2f(32.5*12, 11*12);
    glEnd();
}
void patinhas(){
    glBegin(GL_LINE_STRIP);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(30*12, 26*12);
        glVertex2d(25*12, 11*12);
        glVertex2d(20*12, 26*12);
        glVertex2d(25*12, 22*12);
        glVertex2d(30*12, 26*12);
    glEnd();
   
    glBegin(GL_LINE_STRIP);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(25*12, 22*12);
        glVertex2d(25*12, 11*12);
    glEnd(); 
}
void cabeca(){
    glBegin(GL_LINE_STRIP);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(25*12, 22*12);
        glVertex2f(33*12, 28.5*12);
        glVertex2d(28*12, 36*12);
        glVertex2d(22*12, 36*12);
        glVertex2f(17*12, 28.5*12);
        glVertex2d(25*12, 22*12);
    glEnd();
   
    //ORELHINHA1:
    glBegin(GL_LINE_STRIP);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(33*12, 28.5*12);
        glVertex2d(28*12, 36*12);
        glVertex2f(32.5*12, 42*12);
        glVertex2f(33*12, 28.5*12);
    glEnd();
    
    //ORELHINHA2:
    glBegin(GL_LINE_STRIP);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(22*12, 36*12);
        glVertex2f(17*12, 28.5*12);
        glVertex2d(17*12, 42*12);
        glVertex2d(22*12, 36*12);
    glEnd();

    //___________________________________________________//

    glBegin(GL_LINE_STRIP);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(25*12, 22*12);
        glVertex2d(25*12, 36*12);
    glEnd();
}
void raposa(){
    rabinho();
    corpinho();
    patinhas();
    cabeca();
}
//______________________________________________________________________________________//

void mouse(int button, int state, int mousex, int mousey) {
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mousex > 580)
    {
        x = mousex;
        y = (600 - mousey);
        click = true;
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }
    glutPostRedisplay();  
}

void circuloOuQuadrado(){
    srand(time(NULL));
    float R, G, B;
    polygon = rand()%2;
    R = (rand() % 255)/255.0;
    G = (rand() % 255)/255.0;
    B = (rand() % 255)/255.0;

    if (polygon == 0)
    {
        glBegin(GL_QUADS);
            glColor3f(R, G, B);
            glVertex2d(x+15, y+15);
            glVertex2d(x+15, y-15);
            glVertex2d(x-15, y-15);
            glVertex2d(x-15, y+15);
        glEnd();
    }
    else
    {
        GLfloat circle_points = 100.0f;
        GLfloat angle;
        glBegin(GL_POLYGON);
        glColor3f(R, G, B);
        for (int i = 0; i < circle_points; i++) {
            angle = 2*pi*i/circle_points;
            glVertex2f(x+cos(angle)*15, y+sin(angle)*15);
        }
        glEnd();    
    }
}


void separacao(){
    glBegin(GL_LINE_STRIP);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(600, 600);
        glVertex2d(600, 0);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(30, 580);
        glVertex2d(30, 560);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(630, 580);
        glVertex2d(630, 560);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(640, 580);
        glVertex2d(640, 560);
    glEnd();
}
//Função Chamada para desenhar
void desenhaCoisas()
{
    printf("%d %d %d\n", x, y, click);
    separacao();
    raposa();
    if (click)
    {
        circuloOuQuadrado();
        click = false;
    }
    glutSwapBuffers();
}

// Inicializa parâmetros de rendering
void init(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    gluOrtho2D(0, 1200, 0, 600);
}

// Programa principal
int main(int argc, char **argv)
{
    glutInit(&argc, argv);                         
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);   
    glutInitWindowSize(1200, 600);                  
    glutInitWindowPosition(100, 100);    
    glutCreateWindow("NAO MUDE O TAMANHO DA JANELA PLSSSS"); 
    init();                                       
    glutDisplayFunc(desenhaCoisas);                
    glutMouseFunc(mouse);          
    glutMainLoop();                                
    return 0;
}
