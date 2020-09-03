#include <GL/glut.h>
#include <math.h>

int r = 1.0;
int g = 0.0;
int b = 0.0;

void teclinhas(unsigned char key, int x, int y){
    switch (key) {
        case 97:                              
	        r = 0.0;
            b = 1.0;
	        break;
        case 118:
            r = 1.0;
            b = 0.0;
            break;
    }
}

//Função Chamada para desenhar
void desenhaCoisas()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
        glColor3f(r, g, b);
        glVertex2d(30, 226);
        glVertex2d(30, 30);
        glVertex2d(226, 30);
        glVertex2d(226, 226);
    glEnd();
    glutPostRedisplay();
    glFlush();
}

// Inicializa parâmetros de rendering
void init(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    gluOrtho2D(0, 256, 0, 256);
}

// Programa principal
int main(int argc, char **argv)
{
    glutInit(&argc, argv);                         
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);   
    glutInitWindowSize(256, 256);                  
    glutInitWindowPosition(100, 100);              
    glutCreateWindow("Azul..Vermelho..Azul..Vermelho..."); 
    init();                                        
    glutDisplayFunc(desenhaCoisas);
    glutKeyboardFunc(teclinhas);                
    glutMainLoop();                                
    return 0;
}
