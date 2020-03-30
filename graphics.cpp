#include "graphics.h"
#include "gameManager.h"

GLdouble width, height;
int wd;
GameManager manager;
// Mouse variables
int prevMouseX, prevMouseY;

void init()
{
    width = 800;
    height = 500;
    prevMouseX = 0;
    prevMouseY = 0;
}

/* Initialize OpenGL Graphics */
void initGL()
{
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    Vector3 camLoc = manager.getCameraLocation();
    Vector3 camLook = manager.getCameraLookingAt();
    Vector3 camUp = manager.getCameraUp();
    gluLookAt(camLoc.x, camLoc.y, camLoc.z,  // eye position
              camLook.x, camLook.y, camLook.z,  // center position (not gaze direction)
              camUp.x, camUp.y, camUp.z); // up vector
}

void draw_axes()
{
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-width/2.0, 0.0, 0.0);
    glVertex3f(width/2.0, 0.0, 0.0);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, height/2.0, 0.0);
    glVertex3f(0.0, -height/2.0, 0.0);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, width);
    glVertex3f(0.0, 0.0, -width);
    glEnd();
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display()
{

    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-width/2, width/2, -height/2, height/2, -width, width);
    gluPerspective(45, width/height, 1, 2000);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glEnable(GL_DEPTH);
    glEnable(GL_CULL_FACE);
    glPolygonMode(GL_FRONT, GL_FILL);

    // Update where the camera is
    Vector3 camLoc = manager.getCameraLocation();
    Vector3 camLook = manager.getCameraLookingAt();
    Vector3 camUp = manager.getCameraUp();
    gluLookAt(camLoc.x, camLoc.y, camLoc.z,  // eye position
              camLook.x, camLook.y, camLook.z,  // center position (not gaze direction)
              camUp.x, camUp.y, camUp.z); // up vector

    /*
     * Draw here
     */
    draw_axes();
    manager.draw();

    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y)
{
    // escape
    if (key == 27)
    {
        glutDestroyWindow(wd);
        exit(0);
    }

    switch(key)
    {
        case 'w': manager.setWKey(true);
            break;
        case 'a': manager.setAKey(true);
            break;
        case 's': manager.setSKey(true);
            break;
        case 'd': manager.setDKey(true);
            break;
        case 'r': manager.setRKey(true);
            break;
        case 'c': manager.setCKey(true);
            break;
    }

    glutPostRedisplay();
}


void kbu(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'w': manager.setWKey(false);
            break;
        case 'a': manager.setAKey(false);
            break;
        case 's': manager.setSKey(false);
            break;
        case 'd': manager.setDKey(false);
            break;
        case 'r': manager.setRKey(false);
            break;
        case 'c': manager.setCKey(false);
            break;
    }

    glutPostRedisplay();
}

void kbdS(int key, int x, int y)
{
    /*switch(key)
    {
        case GLUT_KEY_DOWN:

            break;
        case GLUT_KEY_LEFT:
            c.move(-5, 0, 0);
            break;
        case GLUT_KEY_RIGHT:
            c.move(5, 0, 0);
            break;
        case GLUT_KEY_UP:

            break;
    }*/

    glutPostRedisplay();
}

void cursor(int x, int y)
{
    double theta = atan2(y - prevMouseY, x - prevMouseX);
    manager.reactToMouseMovement(theta);
    prevMouseX = x;
    prevMouseY = y;
    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y)
{

    glutPostRedisplay();
}

void timer(int dummy)
{

    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);
    manager.tick();
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv)
{

    init();

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(100, 100); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("3D Graphics!" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);
    glutKeyboardUpFunc(kbu);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(0, timer, 0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}