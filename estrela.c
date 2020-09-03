 #include <GL/glut.h>

void desenhaPoligono(){
    glClear(GL_COLOR_BUFFER_BIT);
    float R = 0.9, G = 0.9, B = 0.0;
    gluOrtho2D(-3, 3, -3, 3); // Tamanho da grade (Plano Cartesiano)
    //Pentagono
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0,0.0);
        glVertex2f(0.0, -1.0);
        glVertex2f(-1.0, -0.2);
        glVertex2f(-0.6, 1.0);
        glVertex2f(0.6, 1.0);
        glVertex2f(1.0, -0.2);
        glVertex2f(0.0, -1.0);
    glEnd();
    //Pontas da estrela
    glBegin(GL_TRIANGLES);
    glColor3f(R, G, B);
        glVertex2f(-0.6, 1.0);
        glVertex2f(0.6, 1.0);
        glVertex2f(0.0, 2.8);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(R, G, B);
        glVertex2f(0.0, -1.0);
        glVertex2f(1.0, -0.2);
        glVertex2f(1.5, -2.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(R, G, B);
        glVertex2f(0.0, -1.0);
        glVertex2f(-1.0, -0.2);
        glVertex2f(-1.5, -2.0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(R, G, B);
        glVertex2f(-0.6, 1.0);
        glVertex2f(-1.0, -0.2);
        glVertex2f(-2.3, 1.1);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(R, G, B);
        glVertex2f(0.6, 1.0);
        glVertex2f(1.0, -0.2);
        glVertex2f(2.3, 1.1);
    glEnd();

    glFlush();
}

// Inicializa parâmetros de rendering
void init(void)
{
    //Fundo branco
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

// Programa principal

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Desenha uma Estrelinha ayaya");
    init();
    glutDisplayFunc(desenhaPoligono);
    glutMainLoop();
} 
