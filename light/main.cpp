#include <OpenGL/gl.h>		// Header File For The OpenGL32 Library
#include <OpenGL/glu.h>		// Header File For The GLu32 Library
#include <GLUT/glut.h>
#include <math.h>
#include "unistd.h"
#include "iostream"

#define PI 3.141592653
struct coords{
    int x;
    int y;
    int stage;
};
coords position;

// инициализация
void init (void)
{
    position.x = 0;
    position.y = 0;
    position.stage = 1;
    // цвет фона
    glClearColor (0.3, 0.3, 0.3, 0.0);
    // рассчет освещения
    glEnable(GL_LIGHTING);
    // двухсторонний расчет освещения
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    // автоматическое приведение нормалей к
    // единичной длине
    glEnable(GL_NORMALIZE);
}

void reshape(int width, int height)
{
    // двухмерное окно вывода
    glViewport(0, 0, width, height);
    // ортогональная проекция
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.2, 1.2, -1.2, 1.2, -1, 1);
    // модельная матрица единичная
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display(void)
{
    // очищаем буфер кадра и глубины
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // свойства материала
    //GLfloat material_diffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat material_diffuse[] = {0.4, 0.4, 0.4};
    GLfloat material_ambient[] = {0.25,0.25,0.25};
    GLfloat material_specular[] = {0.774597,0.774597,0.774597};
    glMaterialfv(GL_BACK, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_BACK, GL_AMBIENT, material_ambient);
    glMaterialfv(GL_BACK, GL_SPECULAR, material_specular);
    glMaterialf(GL_BACK, GL_SHININESS, 0.6);
    //GLfloat a[] = {0,0,0,1};
    //glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, a);

    GLfloat light2_diffuse[] = {10, 0, 0, 1.0};
    GLfloat light2_position[] = {(float)position.x/10, (float)position.y/10, 0.0, 1.0};
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light2_diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light2_position);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.0);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.2);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.4);



    glColor3f(0,0,0);
    //glNormal3f(1, 1, 0);
    //glRotatef(20,1,0,0);
    //glutSolidSphere(0.5,250,250);
    glTranslatef(0,0,-1);
    glRotatef(15,1,0,0);
    glutSolidTeapot(0.5);
    glRotatef(-15,1,0,0);
    glTranslatef(0,0,1);


    glDisable(GL_LIGHT0);

    usleep(100000);
    switch(position.stage){
        case(1):{
            if(position.x == 10){
                position.stage = -1;
                position.x-=1;
                position.y-=1;
            } else {
                position.x+=1;
                position.y+=1;
            }
            break;
        }
        case(-1):{
            if(position.x == 0){
                position.stage = 2;
                position.x-=1;
                position.y-=1;
            } else {
                position.x-=1;
                position.y-=1;
            }
            break;
        }
        case(2):{
            if(position.x == -10){
                position.stage = -2;
                position.x+=1;
                position.y+=1;
            } else {
                position.x-=1;
                position.y-=1;
            }
            break;
        }
        case(-2):{
            if(position.x == 0){
                position.stage = 3;
                position.x-=1;
                position.y+=1;
            } else {
                position.x+=1;
                position.y+=1;
            }
            break;
        }
        case(3):{
            if(position.x == -10){
                position.stage = -3;
                position.x+=1;
                position.y-=1;
            } else {
                position.x-=1;
                position.y+=1;
            }
            break;
        }
        case(-3):{
            if(position.x == 0){
                position.stage = 4;
                position.x+=1;
                position.y-=1;
            } else {
                position.x+=1;
                position.y-=1;
            }
            break;
        }
        case(4):{
            if(position.x == 10){
                position.stage = -4;
                position.x-=1;
                position.y+=1;
            } else {
                position.x+=1;
                position.y-=1;
            }
            break;
        }
        case(-4):{
            if(position.x == 0){
                position.stage = 1;
                position.x+=1;
                position.y+=1;
            } else {
                position.x-=1;
                position.y+=1;
            }
            break;
        }
    }
    std::cout << position.x << "\t" << position.y << "\t" << position.stage << "\n";
    glutPostRedisplay();
    // элемент двойной буферизации
    glutSwapBuffers();
}

void keyboard_function(unsigned char key, int x, int y)
{
    if (key == 'e') exit(0);
}



int main (int argc, char** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition (50, 100);
    glutInitWindowSize (500, 500);
    glutCreateWindow ("Cringe");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard_function);
    glutMainLoop ();
}