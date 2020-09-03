#include <GL/glut.h>
#include <math.h>
#define pi 3.1415926535898
void desenhaPoligono(){
    glClear(GL_COLOR_BUFFER_BIT);
    GLfloat circle_points = 100.0f;
    GLfloat angle, raioX=1.5f, raioY=1.5f;

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    for (int i = 0; i <= circle_points/2; i++) {
        angle = 2*pi*i/circle_points;
        glVertex2f(cos(angle)*raioX, sin(angle)*raioY);
    }
    glEnd();
    glFlush();
}

// Inicializa parâmetros de rendering
void init(void)
{
    //Fundo branco
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    gluOrtho2D(-2, 2, -2, 2); // Tamanho da grade (Plano Cartesiano)
}

// Programa principal

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Desenha uma fatia de pizza(semi-círculo)");
    init();
    glutDisplayFunc(desenhaPoligono);
    glutMainLoop();
} 
