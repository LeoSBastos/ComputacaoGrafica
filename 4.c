#include <GL/glut.h>


void losango(float positionx, float positiony, float propWiHe, float width, float heigth3D, float R, float G, float B){
    float height = width/propWiHe; 
    glBegin(GL_POLYGON);
        glColor3f   (R, G, B);
        glVertex2f  (positionx-width, positiony);
        glVertex2f  (positionx, positiony+height);
        glVertex2f  (positionx+width, positiony);
        glVertex2f  (positionx, positiony-height);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glColor3f   (0.0, 0.0, 0.0);
        glVertex2f  (positionx-width, positiony);
        glVertex2f  (positionx, positiony+height);
        glVertex2f  (positionx+width, positiony);
        glVertex2f  (positionx, positiony-height);
        glVertex2f  (positionx-width, positiony);     
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(R*0.6, G*0.6, B*0.6);
        glVertex2f(positionx-width, positiony);
        glVertex2f(positionx, positiony-height);
        glVertex2f(positionx, positiony-(height + heigth3D));
        glVertex2f(positionx-width, positiony - (heigth3D));
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(R*0.6, G*0.6, B*0.6);
        glVertex2f(positionx, positiony-height);
        glVertex2f(positionx+width, positiony);
        glVertex2f(positionx+width, positiony-(heigth3D));
        glVertex2f(positionx, positiony-(height+heigth3D));
    glEnd();
}
//Função Chamada para desenhar 
void desenhaPoligono(){
    float heigth3D = 2.0, width = 4.0, propWiHe = 1.0; // Proporçao entre largura e altura
    //Cores normalizadas
    float   R = 107.0/255.0;
    float   G = 66.0/255.0;
    float   B = 38.0/255.0;

    float  R2 = R*0.35, G2 = G*0.35, B2 = B*0.35;// Cor dos losandos sem altura

    glClear(GL_COLOR_BUFFER_BIT);


    // Losangos dir baixo-direita1
    losango( 0.0*width,  0.0*width/propWiHe,                propWiHe, width,        heigth3D, R, G, B);// Losango base(0,0)
    losango( 1.0*width, -1.0*width/propWiHe,                propWiHe, width,        heigth3D, R, G, B);
    losango( 2.0*width, -2.0*width/propWiHe,                propWiHe, width,        heigth3D, R, G, B);
    losango( 3.0*width, -3.0*width/propWiHe,                propWiHe, width,        heigth3D, R, G, B);
    
    // Losangos dir baixo-direia2
    losango(-1.0*width, -1.0*width/propWiHe,                propWiHe, width,        heigth3D,  R, G, B);
    losango( 0.0*width, -(2.0*width+heigth3D)/propWiHe,     propWiHe, width,        0.0,       R2, G2, B2); // "+heigth3", para tirar a altura
    losango( 1.0*width, -3.0*width/propWiHe,                propWiHe, width,        heigth3D,  R, G, B);
    losango( 2.0*width, -4.0*width/propWiHe,                propWiHe, width,        heigth3D,  R, G, B);

    // Losangos dir baixo-direia3
    losango(-2.0*width, -2.0*width/propWiHe,                propWiHe, width,        heigth3D, R, G, B);
    losango(-1.0*width, -(3.0*width+heigth3D)/propWiHe,     propWiHe, width,        0.0,      R2, G2, B2); // "+heigth3", para tirar a altura
    losango( 0.0*width, -(4.0*width+heigth3D)/propWiHe,     propWiHe, width,        0.0,      R2, G2, B2); // "+heigth3", para tirar a altura
    losango( 1.0*width, -5.0*width/propWiHe,                propWiHe, width,        heigth3D, R, G, B);

    // Losangos dir baixo-direita4
    losango(-3.0*width,   -3.0*width/propWiHe,              propWiHe, width,        heigth3D, R, G, B);
    losango(-2.0*width,   -4.0*width/propWiHe,              propWiHe, width,        heigth3D, R, G, B);
    losango(-1.0*width,   -5.0*width/propWiHe,              propWiHe, width,        heigth3D, R, G, B);
    losango( 0.0*width,   -6.0*width/propWiHe,              propWiHe, width,        heigth3D, R, G, B);
 
    
    glFlush();
}


// Inicializa parâmetros de rendering
void init(void)
{
    //Fundo (branco)
    glClearColor(255.0/255.0f, 255.0/255.0f, 255.0/255.0f, 1.0f);
    gluOrtho2D(-20, 20, -35, 15); // Tamanho da grade (Plano Cartesiano)
}

// Programa principal
int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Conjuntao top de Poligonos");
    init();
    glutDisplayFunc(desenhaPoligono);
    glutMainLoop();
} 
