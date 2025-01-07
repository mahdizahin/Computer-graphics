 #include <windows.h>
#include <GL/glut.h>

// Array of background colors (Red, Green, Blue, Yellow, Cyan, Magenta)
GLfloat backgroundColor[][3] = {
    {1.0f, 0.0f, 0.0f}, // Red
    {0.0f, 1.0f, 0.0f}, // Green
    {0.0f, 0.0f, 1.0f}, // Blue
    {1.0f, 1.0f, 0.0f}, // Yellow
    {0.0f, 1.0f, 1.0f}, // Cyan
    {1.0f, 0.0f, 1.0f}  // Magenta
};

int currentColorIndex = 0;
int xPos = -50; // Initial X coordinate for the shape
int direction = 1; // Direction to move the shape

// Function to change the background color and shape position
void changeBackgroundColor(int value) {
    // Cycle through colors
    currentColorIndex = (currentColorIndex + 1) % 6;

    // Set the new background color
    glClearColor(backgroundColor[currentColorIndex][0], backgroundColor[currentColorIndex][1], backgroundColor[currentColorIndex][2], 0.0f);

    // Update the shape's X position
    xPos += direction * 5;
    if (xPos > 50 || xPos < -50) {
        direction = -direction; // Reverse direction when hitting boundaries
    }

    // Request a redraw of the window
    glutPostRedisplay();

    // Set up the timer for the next color change after 20 milliseconds
    glutTimerFunc(20, changeBackgroundColor, 0);
}

// Function to display the shape
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set shape color (opposite of background color for contrast)
    glColor3f(1.0f - backgroundColor[currentColorIndex][0],
              1.0f - backgroundColor[currentColorIndex][1],
              1.0f - backgroundColor[currentColorIndex][2]);

    // Draw a square that moves horizontally
    glBegin(GL_QUADS);
        glVertex2f(xPos - 10, -10);
        glVertex2f(xPos + 10, -10);
        glVertex2f(xPos + 10, 10);
        glVertex2f(xPos - 10, 10);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(80, 50);
    glutCreateWindow("Color Animation with Shape");

    // Set initial background color
    glClearColor(backgroundColor[currentColorIndex][0], backgroundColor[currentColorIndex][1], backgroundColor[currentColorIndex][2], 0.0f);

    glutDisplayFunc(display);

    // Set up the timer for the first color change after 20 milliseconds
    glutTimerFunc(20, changeBackgroundColor, 0);

    glutMainLoop();
    return 0;
}
