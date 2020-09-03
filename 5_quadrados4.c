#include <GL/glut.h>
#include <math.h>

//Função Chamada para desenhar
void desenhaCoisas()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
        glColor3f(0.0/255.0, 250.0/255.0, 0.0/255.0);
        glVertex2d(-128, 128);
        glVertex2d(-128, 0);
        glVertex2d(0, 0);        
        glVertex2d(0, 128);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.0/255.0, 0.0/255.0, 200.0/255.0);
        glVertex2d(128, -128);
        glVertex2d(128, 0);
        glVertex2d(0, 0);        
        glVertex2d(0, -128);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(200.0/255.0, 0.0/255.0, 0.0/255.0);
        glVertex2d(-128, 0);
        glVertex2d(0, 0);
        glVertex2d(0, -128);        
        glVertex2d(-128, -128);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(255.0/255.0,0.0/255.0,255.0/255.0);
        glVertex2d(0, 128);
        glVertex2d(128, 128);
        glVertex2d(128, 0);
        glVertex2d(0, 0);        
    glEnd();
    glFlush();
}
void init(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    gluOrtho2D(-128, 128, -128, 128);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(256, 256);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Quadradinhos coloridos AYAYA");
    init();
    glutDisplayFunc(desenhaCoisas);
    glutMainLoop();
    return 0;
}
