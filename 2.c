#include <GL/glut.h>

//Função Chamada para desenhar 
void desenhaPoligono(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.5, 1.0);
        glVertex2f(-1.0, 0.0);
        glVertex2f(0.0, 0.33);
        glVertex2f(1.0, 0.0);
        glVertex2f(0.0, -0.33);
    glEnd();
    glFlush();
}

// Inicializa parâmetros de rendering
void init(void)
{
    //Fundo (branco)
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
    glutCreateWindow("Desenha um \"Tijolo\" Isometrico");
    init();
    glutDisplayFunc(desenhaPoligono);
    glutMainLoop();
} 
