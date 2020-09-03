#include <GL/glut.h>
#include <math.h>
int mainWindow, secondWindow ;
//Função Chamada para desenhar
void desenhaCoisas()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

// Inicializa parâmetros de rendering
void init(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    gluOrtho2D(-2, 2, -2, 2);
}
int glutCreateSubWindow(int win, int x, int y, int width, int height){

}

// Programa principal
int main(int argc, char **argv)
{
    glutInit(&argc, argv);                         
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);   
    glutInitWindowSize(600, 500);                  
    glutInitWindowPosition(100, 100);              
    glutCreateWindow("Modelo de Programa OpenGL"); 
    init();                                        
    glutDisplayFunc(desenhaCoisas);                
    glutMainLoop();                                
    return 0;
}
