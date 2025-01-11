#include <windows.h>
#include <GL/glut.h>
// Initial ortho boundaries
float left = -1.0f, right = 1.0f, bottom = -1.0f, top = 1.0f;

// Function to draw a simple object (e.g., a rectangle)
void drawObject() {
    glBegin(GL_QUADS);  // Draw a square or rectangle
    glColor3f(1.0, 0.0, 0.0);  // Red
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the screen

    // Set the orthographic projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(left, right, bottom, top);  // Use the current ortho settings

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Draw the object within the current orthographic view
    drawObject();

    glFlush();  // Render now
}

// Keyboard interaction to change ortho views
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case '1':  // Press '1' for a zoomed-out view
            left = -2.0f;
            right = 2.0f;
            bottom = -2.0f;
            top = 2.0f;
            break;
        case '2':  // Press '2' for a zoomed-in view
            left = -0.5f;
            right = 0.5f;
            bottom = -0.5f;
            top = 0.5f;
            break;
        case '3':  // Press '3' for a shifted view to the right
            left = 0.0f;
            right = 2.0f;
            bottom = -1.0f;
            top = 1.0f;
            break;
        case '4':  // Press '4' for a shifted view to the left
            left = -2.0f;
            right = 0.0f;
            bottom = -1.0f;
            top = 1.0f;
            break;
        case 'r':  // Press 'r' to reset the view
            left = -1.0f;
            right = 1.0f;
            bottom = -1.0f;
            top = 1.0f;
            break;
    }
    glutPostRedisplay();  // Redisplay the scene after a key press
}

// Initialization function
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Set background color to black
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(left, right, bottom, top);  // Initial ortho view
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Multiple Ortho2D with Keyboard Interaction");

    init();
    glutDisplayFunc(display);  // Set the display callback
    glutKeyboardFunc(keyboard);  // Set the keyboard callback

    glutMainLoop();  // Enter the GLUT event loop
    return 0;
}
