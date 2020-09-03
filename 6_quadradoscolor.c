#include <GL/glut.h>
#include <time.h>
#include <math.h>

int r1 = 0.0, g1 = 0.0, b1 = 0.0;
int r2 = 0.0, g2 = 0.0, b2 = 0.0;
int r3 = 0.0, g3 = 0.0, b3 = 0.0;
int r4 = 0.0, g4 = 0.0, b4 = 0.0;
int tam = 256;

//Função Chamada para desenhar
void desenhaCoisas()
{
    glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(r1/255.0, g1/255.0, b1/255.0);
        glVertex2d(-tam, tam);
        glVertex2d(-tam, 0);
        glVertex2d(0, 0);        
        glVertex2d(0, tam);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(r2/255.0, g2/255.0, b2/255.0);
        glVertex2d(tam, -tam);
        glVertex2d(tam, 0);
        glVertex2d(0, 0);        
        glVertex2d(0, -tam);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(r3/255.0, g3/255.0, b3/255.0);
        glVertex2d(-tam, 0);
        glVertex2d(0, 0);
        glVertex2d(0, -tam);        
        glVertex2d(-tam, -tam);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(r4/255.0, g4/255.0, b4/255.0);
        glVertex2d(0, tam);
        glVertex2d(tam, tam);
        glVertex2d(tam, 0);
        glVertex2d(0, 0);        
    glEnd();

    glFlush();
    glutPostRedisplay();
}
void mudaCor(){
    srand(time(NULL));
    
    r1 = rand() % 255;
    g1 = rand() % 255;
    b1 = rand() % 255;

    r2 = rand() % 255;
    g2 = rand() % 255;
    b2 = rand() % 255;

    r3 = rand() % 255;
    g3 = rand() % 255;
    b3 = rand() % 255;

    r4 = rand() % 255;
    g4 = rand() % 255;
    b4 = rand() % 255;

    glutTimerFunc(100, mudaCor, 1);
}
void init(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    gluOrtho2D(-tam, tam, -tam, tam);

}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(tam, tam);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Quadradinhos coloridos e piscantes AYAYA");
    init();
    glutDisplayFunc(desenhaCoisas);
    glutTimerFunc(100, mudaCor, 1);
    glutMainLoop();
    return 0;
}
