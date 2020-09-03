#include <GL/glut.h>
#include <math.h>
//Bibliotecas: -lglut -lGL -lGLU -lm

//Função Chamada para desenhar 
void desenhaCoisas(){
    glClear(GL_COLOR_BUFFER_BIT);// Limpeza de buffer 
    gluOrtho2D(-2, 2, -2, 2); // Tamanho da grade (Plano Cartesiano, -x,x,-y,y)
    glBegin(GL_POLYGON); // Começa o poligono
        //Cor do poligono com glColor
        //Vertices do poligono com glVertexXX 
    glEnd();// Termina o poligono
    glFlush();//Carrega os comandos no buffer
}

// Inicializa parâmetros de rendering
void init(void)
{
    //Cor de Fundo, inicial , RGB + Canal Alpha (Transparencia)
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

// Programa principal
int main(int argc, char** argv)
{
    glutInit(&argc,argv); // Inicializa a biblioteca
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);// Modo(Single para animações, Duplo para animação...) e Padrão de cores 
    glutInitWindowSize(600,500);// Tamanho da janela (largura, altura)
    glutInitWindowPosition(100,100);// Posição de iniciaçizaçao da janela
    glutCreateWindow("Modelo de Programa OpenGL");// Título da janela
    init();// Limpa a tela com a cor de fundo definida na função
    glutDisplayFunc(desenhaCoisas);// Função que desenha a funçao definida entre ()
    glutMainLoop();// Loop da aplicação
    return 0;
} 

