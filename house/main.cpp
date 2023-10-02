#include <iostream>
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>		// Header File For The OpenGL32 Library
#include <OpenGL/glu.h>		// Header File For The GLu32 Library
#include <GLUT/glut.h>
#include <curses.h>// Header File For The GLut Library


#define _USE_MATH_DEFINES
#include <math.h>



char title[] = "House";
GLfloat rotX = 0, rotY = 0, rotZ = 0;

/* Initialize OpenGL Graphics */
void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClearDepth(1.0f);                   // Set background depth to farthest
    glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
    glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
    glShadeModel(GL_SMOOTH);   // Enable smooth shading
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix

    // Render a color-cube consisting of 6 quads with different colors
    glLoadIdentity();                 // Reset the model-view matrix
    glTranslatef(0.0f, -0.5f, -7.0f);  // Move right and into the screen
    glRotatef(rotX, 1, 0, 0);
    glRotatef(rotY, 0, 1, 0);
    glRotatef(rotZ, 0, 0, 1);
    glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
    // Top face (y = 1.0f)
    // Define vertices in counter-clockwise (CCW) order with normal pointing out
    glColor3f(1.0f, 0.8f, 0.1f);     // Green
    glVertex3f( 1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f,  1.0f);
    glVertex3f( 1.0f, 1.0f,  1.0f);

    // Bottom face (y = -1.0f)
    glColor3f(1.0f, 0.5f, 0.0f);     // Orange
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);

    // Front face  (z = 1.0f)
    glColor3f(1.0f, 0.8f, 0.1f);     // Red
    glVertex3f( 1.0f,  1.0f, 1.0f);
    glVertex3f(-1.0f,  1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f( 1.0f, -1.0f, 1.0f);

    glColor3f(0.5f, 0.25f, 0.0f);
    glVertex3f( 0.25f,  -0.15f, 1.01f);
    glVertex3f(-0.25f,  -0.15f, 1.01f);
    glVertex3f(-0.25f, -1.0f, 1.01f);
    glVertex3f( 0.25f, -1.0f, 1.01f);

    glColor3f(0.0f, 0.8f, 1.0f);
    glVertex3f( 0.75f,  0.15f, 1.01f);
    glVertex3f(0.5f,  0.15f, 1.01f);
    glVertex3f(0.5f, 0.5f, 1.01f);
    glVertex3f( 0.75f, 0.5f, 1.01f);

    glColor3f(0.0f, 0.8f, 1.0f);
    glVertex3f( -0.75f,  0.15f, 1.01f);
    glVertex3f(-0.5f,  0.15f, 1.01f);
    glVertex3f(-0.5f, 0.5f, 1.01f);
    glVertex3f( -0.75f, 0.5f, 1.01f);

//    glColor3f(0.5f, 0.25f, 0.0f);
//    glVertex3f( 0.25f,  0.15f, 1.01f);
//    glVertex3f(-0.25f,  0.15f, 1.01f);
//    glVertex3f(-0.25f, -1.0f, 1.01f);
//    glVertex3f( 0.25f, -1.0f, 1.01f);

    // Back face (z = -1.0f)
    glColor3f(1.0f, 0.8f, 0.1f);     // Yellow
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);

//    glColor3f(0.5f, 0.25f, 0.0f);
//    glVertex3f( 0.75f,  0.15f, -1.01f);
//    glVertex3f(0.5f,  0.15f, -1.01f);
//    glVertex3f(0.5f, 0.5f, -1.01f);
//    glVertex3f( 0.75f, 0.5f, -1.01f);

    glColor3f(0.0f, 0.8f, 1.0f);
    glVertex3f( -0.75f,  0.15f, -1.01f);
    glVertex3f(0.75f,  0.15f, -1.01f);
    glVertex3f(0.75f, 0.5f, -1.01f);
    glVertex3f( -0.75f, 0.5f, -1.01f);

    // Left face (x = -1.0f)
    glColor3f(1.0f, 0.8f, 0.1f);     // Blue
    glVertex3f(-1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);

    glColor3f(0.0f, 0.8f, 1.0f);
    glVertex3f( -1.01f,  -0.5f, 0.75f);
    glVertex3f(-1.01f,  -0.5f, 0.25f);
    glVertex3f(-1.01f, 0.5f, 0.25f);
    glVertex3f( -1.01f, 0.5f, 0.75f);

    glColor3f(0.0f, 0.8f, 1.0f);
    glVertex3f( -1.01f,  -0.5f, -0.75f);
    glVertex3f(-1.01f,  -0.5f, -0.25f);
    glVertex3f(-1.01f, 0.5f, -0.25f);
    glVertex3f( -1.01f, 0.5f, -0.75f);

    // Right face (x = 1.0f)
    glColor3f(1.0f, 0.8f, 0.1f);      // Magenta
    glVertex3f(1.0f,  1.0f, -1.0f);
    glVertex3f(1.0f,  1.0f,  1.0f);
    glVertex3f(1.0f, -1.0f,  1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd();  // End of drawing color-cube

    // Render a pyramid consists of 4 triangles
    //glLoadIdentity();                  // Reset the model-view matrix
    glTranslatef(0.0f, 2.0f, 0.0f);
    //glRotatef(rotX, 1, 0, 0);
    //glRotatef(rotY, 0, 1, 0);// Move left and into the screen

    glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
    // Front
    glColor3f(0.5f, 0.25f, 0.0f);     // Red
    glVertex3f( 0.0f, 0.5f, 0.0f);
    //glColor3f(0.0f, 1.0f, 0.0f);     // Green
    glVertex3f(-1.0f, -1.0f, 1.0f);
    //glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Right
    //glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f(0.0f, 0.5f, 0.0f);
    //glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    glVertex3f(1.0f, -1.0f, 1.0f);
    //glColor3f(0.0f, 1.0f, 0.0f);     // Green
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Back
    //glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f(0.0f, 0.5f, 0.0f);
    //glColor3f(0.0f, 1.0f, 0.0f);     // Green
    glVertex3f(1.0f, -1.0f, -1.0f);
    //glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    glVertex3f(-1.0f, -1.0f, -1.0f);

    // Left
    //glColor3f(1.0f,0.0f,0.0f);       // Red
    glVertex3f( 0.0f, 0.5f, 0.0f);
    //glColor3f(0.0f,0.0f,1.0f);       // Blue
    glVertex3f(-1.0f,-1.0f,-1.0f);
    //glColor3f(0.0f,1.0f,0.0f);       // Green
    glVertex3f(-1.0f,-1.0f, 1.0f);
    glEnd();   // Done drawing the pyramid

    glTranslatef(2.0f,-2.0f,0.0f);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.8f, 0.1f);     // Yellow
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f,  0.5f, -1.0f);
    glVertex3f( 1.0f,  0.5f, -1.0f);

    glColor3f(0.0f, 0.8f, 1.0f);
    glVertex3f( 0.5f,  0.15f, -1.01f);
    glVertex3f(-0.5f,  0.15f, -1.01f);
    glVertex3f(-0.5f, 0.3f, -1.01f);
    glVertex3f( 0.5f, 0.3f, -1.01f);

    glColor3f(1.0f, 0.8f, 0.1f);     // стол + в плоскости 12
    glVertex3f( 1.0f,  0.5f, 1.0f);
    glVertex3f(-1.0f,  0.5f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f( 1.0f, -1.0f, 1.0f);

    glColor3f(0.5f, 0.25f, 0.0f);
    glVertex3f( 0.5f,  -0.15f, 1.01f);
    glVertex3f(-0.5f,  -0.15f, 1.01f);
    glVertex3f(-0.5f, -1.0f, 1.01f);
    glVertex3f( 0.5f, -1.0f, 1.01f);

    glColor3f(0.0f, 0.8f, 1.0f);
    glVertex3f( 0.5f,  0.15f, 1.01f);
    glVertex3f(-0.5f,  0.15f, 1.01f);
    glVertex3f(-0.5f, 0.3f, 1.01f);
    glVertex3f( 0.5f, 0.3f, 1.01f);

    glColor3f(1.0f, 0.8f, 0.1f);     // Blue
    glVertex3f(-1.0f,  0.5f,  1.0f);
    glVertex3f(-1.0f,  0.5f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glColor3f(1.0f, 0.8f, 0.1f);     // Green
    glVertex3f( 1.0f, 0.5f, -1.0f);
    glVertex3f(-1.0f, 0.5f, -1.0f);
    glVertex3f(-1.0f, 0.5f,  1.0f);
    glVertex3f( 1.0f, 0.5f,  1.0f);
    glColor3f(1.0f, 0.5f, 0.0f);     // Orange
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glColor3f(1.0f, 0.8f, 0.1f);      // Magenta
    glVertex3f(1.0f,  0.5f, -1.0f);
    glVertex3f(1.0f,  0.5f,  1.0f);
    glVertex3f(1.0f, -1.0f,  1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glColor3f(0.5f, 0.25f, 0.0f);     // Rooftop
    glVertex3f( -1.0f,  1.0f, 1.0f);
    glVertex3f(1.0f,  0.5f, 1.0f);
    glVertex3f(1.0f, 0.5f, -1.0f);
    glVertex3f( -1.0f, 1.0f, -1.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.8f, 0.1f);      // Rooftop
    glVertex3f( -1.0f,  1.0f, 1.0f);
    glVertex3f(-1.0f,  0.5f, 1.0f);
    glVertex3f(1.0f, 0.5f, 1.0f);
    glColor3f(1.0f, 0.8f, 0.1f);      // Rooftop
    glVertex3f( -1.0f,  1.0f, -1.0f);
    glVertex3f(-1.0f,  0.5f, -1.0f);
    glVertex3f(1.0f, 0.5f, -1.0f);
    glEnd();



    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
    // Compute aspect ratio of the new window
    if (height == 0) height = 1;                // To prevent divide by 0
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // Set the viewport to cover the new window
    glViewport(0, 0, width, height);

    // Set the aspect ratio of the clipping volume to match the viewport
    glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
    glLoadIdentity();             // Reset
    // Enable perspective projection with fovy, aspect, zNear and zFar
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

static void key(unsigned char key, int x, int y)
{
        switch (key) {
            case 'w' :
                rotX -= 3;
                break;
            case 's' :
                rotX += 3;
                break;
            case 'a' :
                rotY -= 3;
                break;
            case 'd' :
                rotY += 3;
                break;
            case 'q' :
                rotZ -= 3;
                break;
            case 'e' :
                rotZ += 3;
                break;
            case 'o':
                exit(0);
                break;
        }
        //std::cout << rotX;
        glutPostRedisplay();
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    glutInit(&argc, argv);            // Initialize GLUT
    //glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
    glutInitWindowSize(640, 480);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow(title);          // Create window with the given title
    glutDisplayFunc(display);
    glutKeyboardFunc(key);// Register callback handler for window re-paint event
    glutReshapeFunc(reshape);// Register callback handler for window re-size event
    initGL();// Our own OpenGL initialization
    glutMainLoop();
    return 0;
}