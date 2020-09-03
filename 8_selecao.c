#include <GL/glut.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//Cor do quadrado 
int  r1 = 255.0,  g1 = 255.0,  b1 = 0.0;
int  r2 = 255.0,  g2 = 255.0,  b2 = 0.0;
int  r3 = 255.0,  g3 = 255.0,  b3 = 0.0;
int  r4 = 255.0,  g4 = 255.0,  b4 = 0.0;

//Cor de bordas
int br1 = 0.0, bg1 = 0.0, bb1 = 0.0;
int br2 = 0.0, bg2 = 0.0, bb2 = 0.0;
int br3 = 0.0, bg3 = 0.0, bb3 = 0.0;
int br4 = 0.0, bg4 = 0.0, bb4 = 0.0;


int selec = 0;

void mouse(int button, int state, int x, int y) {
    srand(time(NULL));
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
	if (selec == 0) {
		if ( x <= 113 && x >= 30 && y >= 143 && y<= 226) {
			r3 = (rand() % 255);
			g3 = (rand() % 255);
			b3 = (rand() % 255);
		}
		if ( x <= 226 && x >= 143 && y >= 143 && y <= 226) {
			r4 = (rand() % 255);
			g4 = (rand() % 255);
			b4 = (rand() % 255);
		}
		if ( x <= 113 && x >= 30 && y >= 30 && y<= 113) {
			r1 = (rand() % 255);
			g1 = (rand() % 255);
			b1 = (rand() % 255);
		}
		if ( x <= 226 && x >= 143 && y >= 30 && y <= 113) {
			r2 = (rand() % 255);
			g2 = (rand() % 255);
			b2 = (rand() % 255);
		}
	}
	else if(selec == 1)
	{
		if ( x <= 113 && x >= 30 && y >= 143 && y<= 226) {
			br3 = (rand() % 255);
			bg3 = (rand() % 255);
			bb3 = (rand() % 255);
		}
		if ( x <= 226 && x >= 143 && y >= 143 && y <= 226) {
			br4 = (rand() % 255);
			bg4 = (rand() % 255);
			bb4 = (rand() % 255);
		}
		if ( x <= 113 && x >= 30 && y >= 30 && y<= 113) {
			br1 = (rand() % 255);
			bg1 = (rand() % 255);
			bb1 = (rand() % 255);
		}
		if ( x <= 226 && x >= 143 && y >= 30 && y <= 113) {
			br2 = (rand() % 255);
			bg2 = (rand() % 255);
			bb2 = (rand() % 255);
		}
	}
	
	
    }
}
void teclinhas(unsigned char key, int x, int y){
    switch (key) {
        case 98:                              
	        selec = 1;
	        break;
        case 102:
            selec = 0;
            break;
    }
}
//Função Chamada para desenhar
void desenhaCoisas()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // QUADRADOS
    glBegin(GL_POLYGON);
        glColor3f(r1/255.0, g1/255.0, b1/255.0);
        glVertex2i(30, 226);
        glVertex2i(113, 226);
        glVertex2i(113, 143);
        glVertex2i(30, 143);
    glEnd();

    
    glBegin(GL_POLYGON);
        glColor3f(r2/255.0, g2/255.0, b2/255.0);
        glVertex2i(143, 226);
        glVertex2i(226, 226);glLineWidth(4.0); 
        glVertex2i(226, 143);
        glVertex2i(143, 143);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(r3/255.0, g3/255.0, b3/255.0);
        glVertex2i(30, 113);
        glVertex2i(113, 113);
        glVertex2i(113, 30);
        glVertex2i(30, 30);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(r4/255.0, g4/255.0, b4/255.0);
        glVertex2i(143, 113);
        glVertex2i(226, 113);
        glVertex2i(226, 30);
        glVertex2i(143, 30);
    glEnd();


    // BORDAS
    glLineWidth(2.0); 
    glBegin(GL_LINE_STRIP);
        glColor3f(br1/255.0, bg1/255.0, bb1/255.0);
        glVertex2i(30, 226);
        glVertex2i(113, 226);
        glVertex2i(113, 143);
        glVertex2i(30, 143);
        glVertex2i(30, 226);
    glEnd();

    
    glBegin(GL_LINE_STRIP);
        glColor3f(br2/255.0, bg2/255.0, bb2/255.0);
        glVertex2i(143, 226);
        glVertex2i(226, 226);
        glVertex2i(226, 143);
        glVertex2i(143, 143);
        glVertex2i(143, 226);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glColor3f(br3/255.0, bg3/255.0, bb3/255.0);
        glVertex2i(30, 113);
        glVertex2i(113, 113);
        glVertex2i(113, 30);
        glVertex2i(30, 30);
        glVertex2i(30, 113);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glColor3f(br4/255.0, bg4/255.0, bb4/255.0);
        glVertex2i(143, 113);
        glVertex2i(226, 113);
        glVertex2i(226, 30);
        glVertex2i(143, 30);
        glVertex2i(143, 113);
    glEnd();
    glutPostRedisplay();
    glFlush();
    glutSwapBuffers();

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
    glutCreateWindow("Usando teclas e mouse");
    init();
    glutDisplayFunc(desenhaCoisas);
    glutKeyboardFunc(teclinhas);                
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
