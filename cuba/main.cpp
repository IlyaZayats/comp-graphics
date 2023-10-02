#include <iostream>
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>		// Header File For The OpenGL32 Library
#include <OpenGL/glu.h>		// Header File For The GLu32 Library
#include <GLUT/glut.h>
#include <curses.h>// Header File For The GLut Library

#define _USE_MATH_DEFINES
#include <math.h>



#define kWindowWidth    1820
#define kWindowHeight	910
#define flagSizeX 1820
#define flagSizeY 910



GLvoid InitGL(GLvoid);
GLvoid DrawGLScene(GLvoid);
GLvoid ReSizeGLScene(int Width, int Height);

void drawTriangel(float n, float transX, float transZ){
    glTranslatef(transX,0.0f,transZ);
    // Move left 1.5 units, and in to the screen 6.0 units

}

void drawMain(float n){


}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;
    }
    glutPostRedisplay();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (kWindowWidth, kWindowHeight);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    glutKeyboardFunc(key);


    InitGL();
    glutDisplayFunc(DrawGLScene);
    //glutDisplayFunc(DrawGLScene);	// tells GLUT that to use the DrawGLScene function when we want the scene drawn
    glutReshapeFunc(ReSizeGLScene);

    glutMainLoop();	// starts the program. Once called, program only returns to main() when quitting

    return 0;
}



// All the drawing code. Anything to be displayed on the screen should go in here.
GLvoid DrawGLScene(GLvoid)
{	    // Reset the view
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear The Screen And The Depth Buffer
    glLoadIdentity();

    glTranslatef(0.0f,0.0f,-2.0f);
    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-1, -0.5, 0.0f);
    glVertex3f( 1, -0.5, 0.0f);
    glVertex3f( 1,0.5, 0.0f);
    glVertex3f(-1,0.5, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-1, 0.1, 0.0f);
    glVertex3f(1,0.1, 0.0f);
    glVertex3f( 1, 0.3, 0.0f);
    glVertex3f( -1,0.3, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-1, -0.1, 0.0f);
    glVertex3f(1,-0.1, 0.0f);
    glVertex3f( 1, -0.3, 0.0f);
    glVertex3f( -1,-0.3, 0.0f);
    glEnd();
    //0.5



    float xPoint = -(1.0-sqrt(pow(kWindowHeight, 2)-pow((kWindowHeight/2),2))/kWindowHeight);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(xPoint,0.0f);
    glVertex2f(-1.0f, 0.5);
    glVertex2f(-1.0f,-0.5);
    glEnd();

    float xPoint1 = (float)((-1)-xPoint)/2+xPoint;
    float xPoint2 = (float)-3 / 4 + xPoint / 4;
    float xPoint3 = (float)-7 / 8 + (float)xPoint / 8;


    float radius = (xPoint1-xPoint)/3;
    float a = 1.1755705045849463*radius;
    float h = 1.5388417685876268*a;
    //float z = xPoint1 + radius - 3 * cos(56) * sqrt((9*pow(a,2)+4*pow(radius,2))/81);
    //float t = sqrt(-((pow(a,2)/4) + (pow(radius,2)/9 - pow(xPoint1+radius-z, 2))));
    std::cout << a << std::endl;
    std::cout << radius << std::endl;
    std::cout << h << std::endl;
    std::cout << "x1 " << xPoint1 << std::endl;
    std::cout << "mid " << xPoint1+radius << std::endl;
    std::cout << "mid+radius " << xPoint1+(float)2*radius << std::endl;
    std::cout << "bottom " << xPoint1+(2*radius-h) << std::endl;
    float l = sqrt(pow(xPoint1-xPoint,2)+ pow(0.25,2));
    std::cout << l << std::endl;
    glTranslatef(0,-0.2,0);
    glRotatef(-18,0,0,1);
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,1);
    glVertex2f(xPoint1+(float)2*radius, 0);
    glVertex2f( xPoint1+(2*radius-h), a/2);
    glVertex2f( xPoint1+(2*radius-h), -a/2);
    glColor3f(1,1,1);
    glVertex2f(xPoint1+radius+(-0.04436),-0.137);
    glVertex2f(xPoint1+radius+(-0.04436),0.137);
    glVertex2f(xPoint1+3*(2*radius-h), 0);
    glColor3f(1,0,0);
    glVertex2f( xPoint1+(2*radius-h), a/2);
    glVertex2f( xPoint1+(2*radius-h), -a/2);
    glVertex2f(xPoint1+3*(2*radius-h), 0);
    glEnd();

//    glTranslatef(xPoint1+radius,0,0);
//    glBegin(GL_LINE_STRIP);
//    glColor3f(1.0f,1.0f,0.0f);
//    float x = xPoint1+radius;
//    float y = 0;
//    float r = radius;
//    float start_angle = 1.5;
//    float end_angle = 8;
//    float angle_increment = M_PI / 1000;
//    for (float theta = start_angle; theta < end_angle; theta += angle_increment)
//    {
//        x = r * cos(theta);
//        y = r * sin(theta);
//        glVertex2f(x, y);
//        std::cout << "Length: "<<sqrt(pow(-(radius-x),2)+pow(y,2)) << std::endl;
//        std::cout << "X is: " << x << std::endl;
//        std::cout << "Y is: " << y << std::endl;
//    }
//    glEnd();
//    glTranslatef(-(xPoint1+radius),0,0);
    glFlush();
    //glutSwapBuffers();

}



// Perform the setup for OpenGL: colour for clearing the screen, turning on the depth buffer,
// enable smooth shading, etc. This routine is not called until the OpenGL window has been created.
// Note: this function returns a value, but we'll ignore it for now
GLvoid InitGL(GLvoid)
{
    glShadeModel(GL_SMOOTH);	// Enable Smooth Shading (blends colours across a polygon/smoothed lighting
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	// Green Background (RGBA; 0.0f = darkest, 1.0f = brightest)


    // Set-up the depth buffer
    glClearDepth(1.0f);		// Depth Buffer Setup
    glEnable(GL_DEPTH_TEST);	// Enables Depth Testing
    glDepthFunc(GL_LEQUAL);		// The Type Of Depth Testing To Do

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

}



// - Resize the OpenGL scene each time the window has been resized.
// - This will be called at least once when the program is first run in order to set-up the perspective view.
// - The OpenGL scene will be resized based on the width and height of the window it's being displayed within.
GLvoid ReSizeGLScene(int Width, int Height)
{
    // Prevent Division By Zero
    // This condition occurs when the window height is 0 or less. We simply
    // pretend it has a height of 1. The window will probably not be drawn.
    if (Height<=0) { Height=1; }

    glViewport(0,0,Width,Height);	// Reset the current viewport.

    // The following lines set-up the screen for perspective view (things in the distance are smaller).
    // The perspective is calculated with a 45 degree viewing angle based on the window's width/height
    // 0.f, 100.0f are the starting and ending points for how deep we can draw in to the screen
    glMatrixMode(GL_PROJECTION);	// Select The Projection Matrix
    glLoadIdentity();				// Reset The Projection Matrix

    gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);	// Calculate The Aspect Ratio Of The Window

    glMatrixMode(GL_MODELVIEW);		// Select The Modelview Matrix
    glLoadIdentity();			// Reset The Modelview Matrix
}
