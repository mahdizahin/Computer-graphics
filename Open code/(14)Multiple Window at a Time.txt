#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
// Window IDs for managing multiple windows
int window1, window2;

// Function to display for window 1
void displayWindow1() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); // Red color
    glBegin(GL_POLYGON);
        glVertex2f(-0.5, -0.5);
        glVertex2f( 0.5, -0.5);
        glVertex2f( 0.5,  0.5);
        glVertex2f(-0.5,  0.5);
    glEnd();
    glFlush();
}

// Function to display for window 2
void displayWindow2() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0); // Green color
    glBegin(GL_POLYGON);
        glVertex2f(-0.5, -0.5);
        glVertex2f( 0.5, -0.5);
        glVertex2f( 0.5,  0.5);
        glVertex2f(-0.5,  0.5);
    glEnd();
    glFlush();
}

// Keyboard callback function
void handleKeyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 27: // 'Esc' key to exit
            glutDestroyWindow(window1);
            glutDestroyWindow(window2);
            exit(0);
            break;
        case 'r': // 'r' key to change color to red in window 1
            glutSetWindow(window1);
            glClearColor(1.0, 0.0, 0.0, 1.0); // Red background
            glutPostRedisplay();
            break;
        case 'g': // 'g' key to change color to green in window 2
            glutSetWindow(window2);
            glClearColor(0.0, 1.0, 0.0, 1.0); // Green background
            glutPostRedisplay();
            break;
        default:
            break;
    }
}

void initializeWindow(int winID) {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Create first window
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    window1 = glutCreateWindow("Window 1 - Red Square");
    initializeWindow(window1);
    glutDisplayFunc(displayWindow1);

    // Create second window
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(600, 100);
    window2 = glutCreateWindow("Window 2 - Green Square");
    initializeWindow(window2);
    glutDisplayFunc(displayWindow2);

    // Set up the keyboard callback for both windows
    glutKeyboardFunc(handleKeyboard);

    // Enter the GLUT main loop
    glutMainLoop();

    return 0;
}
