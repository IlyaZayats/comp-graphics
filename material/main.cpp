#include <OpenGL/gl.h>		// Header File For The OpenGL32 Library
#include <OpenGL/glu.h>		// Header File For The GLu32 Library
#include <GLUT/glut.h>
#include <math.h>
#include "unistd.h"
#include "iostream"

#define PI 3.141592653
//struct coords{
//    int x;
//    int y;
//    int stage;
//};
//coords position;
int z = 0;
int stage = 1;

GLfloat rotX = 0, rotY = 0, rotZ = 0;

// инициализация
void init (void)
{
//    position.x = 0;
//    position.y = 0;
//    position.stage = 1;
    // цвет фона
    glClearColor (0.3, 0.3, 0.3, 0.0);
    // рассчет освещения
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnable(GL_DEPTH_TEST);
    glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

    // двухсторонний расчет освещения
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    // автоматическое приведение нормалей к
    // единичной длине
    glEnable(GL_NORMALIZE);
}

void reshape(GLsizei width, GLsizei height)
{
    if (height == 0) height = 1;                // To prevent divide by 0
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    // двухмерное окно вывода
    glViewport(0, 0, width, height);
    // ортогональная проекция
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-1.2, 1.2, -1.2, 1.2, -1, 1);
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
    // модельная матрица единичная
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display(void)
{
    // очищаем буфер кадра и глубины
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0, -3.0f);
    //glRotatef(30,1,0,0);

    //GLfloat light2_diffuse[] = {1, 0, 0, 1.0};
    //GLfloat light2_position[] = {0, 1, 0, 1.0};
    //GLfloat light2_ambient[] = {0,1,0,1};
    //GLfloat light2_specular[] = {1,1,1,1};
    //glEnable(GL_LIGHT0);
    //glLightfv(GL_LIGHT0, GL_AMBIENT, light2_ambient);

//    usleep(10000);
//    glRotatef(rotX, 1, 0, 0);
//    glRotatef(rotY, 0, 1, 0);
//    glRotatef(rotZ, 0, 0, 1);
//    glutSolidTorus(0.3,0.5,250,250);






    GLfloat light2_diffuse[] = {0, 0, 0, 1};
    GLfloat light2_position[] = {0, 1.5, 0, 1.0};
    GLfloat light2_ambient[] = {0.3,0.3,0.3,1};
    GLfloat light2_specular[] = {10,0,0,1};
    glEnable(GL_LIGHT0);
    //glLightfv(GL_LIGHT0, GL_DIFFUSE, light2_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light2_specular);
    //glLightfv(GL_LIGHT0, GL_AMBIENT, light2_ambient);
    glLightfv(GL_LIGHT0, GL_POSITION, light2_position);
//    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.0);
//    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.2);
//    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.4);

    ////////////////
    usleep(100000);

//    glTranslatef(0.5,0,0);
//    float mat_ambient[] = { 0.0f,0.0f,0.0f,1.0f };
//    float mat_diffuse[] ={ 0.55f,0.55f,0.55f,1.0f};
//    float mat_specular[] = { 0.7f,0.7f,0.7f,1.0f};
//    float shine = 64.0f;
//    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
//    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
//    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
//    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine);
//    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
//    glColor4f(0.8,0.8,0.8,0.25);


    //glutSolidCone(0.4, 0.7, 250,250);
    //glTranslatef(-1,0,0);
    float mat_ambient1[] = { 0.05f,0.05f,0.05f,1.0f };
    float mat_diffuse1[] ={ 0.5,0.5,0.5,1.0f};
    float mat_specular1[] = { 0.7f,0.7f,0.7f,1.0f};
    float mat_e[] = {1,0,0,1};
    float shine1 = 64.0f;
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse1);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient1);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular1);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine1);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat_e);
//    glColor3f(0.5f, 0.25f, 0.0f);
//    glutSolidCube(0.7);
//    glTranslatef(0.5,0,0);


    if(stage == 1){
        if(z==10){
            stage = -1;
            z--;
        } else {
            z++;
        }
    } else {
        if(z==-10){
            stage = 1;
            z++;
        } else {
            z--;
        }
    }
    glTranslatef(float(0.1*z),0,0);
    glColor4f(0.8,0.8,0.8,0.25);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glutSolidSphere(0.2,250,250);
    glTranslatef(-float(0.1*z),0,0);
    glTranslatef(0,-0.22,0);
    //glRotatef(-30,0,0,1);
    //glColor3f(0.8,0.8,0.8);
    //glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
    //glNormal3f(0.0, 0.0, -1.0);
    glVertex3f(1.5,0,-1.5);
    glVertex3f(1.5,0,1.5);
    glVertex3f(-1.5,0,1.5);
    glVertex3f(-1.5,0,-1.5);
    glEnd();
    //glRotatef(30,0,0,1);
    glTranslatef(0,0.22,0);
    //////////////////
    //glTranslatef(0,0,3);
//    glTranslatef(0,-5,1);
//    glBegin(GL_QUADS);
//    glVertex3f(1,0,0);
//    glVertex3f(1,0,1);
//    glTranslatef(0,5,-1);

    //glRotatef(-10,0,1,0);
//    glTranslatef(0,0,-1);
//    glRotatef(15,1,0,0);
//    glutSolidTeapot(0.5);
//    glRotatef(-15,1,0,0);
//    glTranslatef(0,0,1);


    glDisable(GL_LIGHT0);

//    usleep(100000);
//    switch(position.stage){
//        case(1):{
//            if(position.x == 10){
//                position.stage = -1;
//                position.x-=1;
//                position.y-=1;
//            } else {
//                position.x+=1;
//                position.y+=1;
//            }
//            break;
//        }
//        case(-1):{
//            if(position.x == 0){
//                position.stage = 2;
//                position.x-=1;
//                position.y-=1;
//            } else {
//                position.x-=1;
//                position.y-=1;
//            }
//            break;
//        }
//        case(2):{
//            if(position.x == -10){
//                position.stage = -2;
//                position.x+=1;
//                position.y+=1;
//            } else {
//                position.x-=1;
//                position.y-=1;
//            }
//            break;
//        }
//        case(-2):{
//            if(position.x == 0){
//                position.stage = 3;
//                position.x-=1;
//                position.y+=1;
//            } else {
//                position.x+=1;
//                position.y+=1;
//            }
//            break;
//        }
//        case(3):{
//            if(position.x == -10){
//                position.stage = -3;
//                position.x+=1;
//                position.y-=1;
//            } else {
//                position.x-=1;
//                position.y+=1;
//            }
//            break;
//        }
//        case(-3):{
//            if(position.x == 0){
//                position.stage = 4;
//                position.x+=1;
//                position.y-=1;
//            } else {
//                position.x+=1;
//                position.y-=1;
//            }
//            break;
//        }
//        case(4):{
//            if(position.x == 10){
//                position.stage = -4;
//                position.x-=1;
//                position.y+=1;
//            } else {
//                position.x+=1;
//                position.y-=1;
//            }
//            break;
//        }
//        case(-4):{
//            if(position.x == 0){
//                position.stage = 1;
//                position.x+=1;
//                position.y+=1;
//            } else {
//                position.x-=1;
//                position.y+=1;
//            }
//            break;
//        }
//    }
    //std::cout << position.x << "\t" << position.y << "\t" << position.stage << "\n";
    glutPostRedisplay();
    // элемент двойной буферизации
    glutSwapBuffers();
}

void keyboard_function(unsigned char key, int x, int y)
{
    switch (key) {
        case 'w' :
            rotX -= 10;
            break;
        case 's' :
            rotX += 10;
            break;
        case 'a' :
            rotY -= 10;
            break;
        case 'd' :
            rotY += 10;
            break;
        case 'q' :
            rotZ -= 10;
            break;
        case 'e' :
            rotZ += 10;
            break;
        case 'o':
            exit(0);
            break;
    }
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