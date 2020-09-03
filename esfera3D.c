
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

float alpha = 0;
float beta = 0;
float delta = 1;

void init(void)
{
	glClearColor(0, 0, 0, 0); //define a cor de fundo
	glEnable(GL_DEPTH_TEST); //remoção de superfície oculta
	glMatrixMode(GL_PROJECTION); //define que a matrix é a de projeção
	glLoadIdentity(); //carrega a matrix de identidade
	glOrtho(-5, 5, -5, 5, -5, 5); //define uma projeção ortográfica
}

void display(void)
{
	//limpa o buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//define que a matrix é a de modelo
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); //carrega matrix identidade
	//rotaciona e escala uma esfera ' aramado '
	glRotatef(beta, 0, 1, 0);
	glRotatef(alpha, 1, 0, 0);
	glScalef(delta, delta, delta);
	glColor3f(1,1,0);
	glutWireSphere(1.0f,20,20);
	//desenha um ' piso ' sob a esfera
	glTranslatef(0,-1,0);
	glScalef(4, 0.1, 4);
	glColor3f(0,0,1);
	glutSolidCube(1.0f);
	//força o desenho das primitivas
	glutSwapBuffers();
}

void special_keyboard(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_PAGE_UP: //faz zoom − in
		delta = delta * 1.1;
		break;
	case GLUT_KEY_PAGE_DOWN: //faz zoom − out
		delta = delta * 0.809;
		break;
	case GLUT_KEY_UP: //gira sobre o eixo − x
		alpha = alpha - 1;
		break;
	case GLUT_KEY_DOWN: //gira sobre o eixo − x
		alpha = alpha + 1;
		break;
	case GLUT_KEY_LEFT: //gira sobre o eixo − y
		beta = beta + 1;
		break;
	case GLUT_KEY_RIGHT: //gira sobre o eixo − y
		beta = beta - 1;
		break;
	}
	//forçar o redesenho da tela usando double − buffering
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	// ' q ' ou ' Q ' ou ESC para sair do sistema
	if ('q' == key || 'Q' == key || 27 == key)
	{
		exit(0);
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("3D");
	init();
	//funções de callback
	glutDisplayFunc(display); //registra função de desenho
	glutKeyboardFunc(keyboard); //registra teclado
	glutSpecialFunc(special_keyboard); //registra teclado especial
	glutMainLoop();
	return 0;
}
//esfera3D.c
//Displaying esfera3D.c.
