 #include <GL/freeglut.h>

float box1PosX = -09.9f; // Starting position of the first box
float box2PosX = 09.9f;  // Starting position of the second box
float speed = 0.1f;    // Speed of movement

// Function to display the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
    glLoadIdentity();

    // Draw the first box (moving right)
    glPushMatrix();
    glTranslatef(box1PosX, 0.0f, 0.0f); // Move box1 horizontally
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glBegin(GL_QUADS);
    glVertex2f(-01.1f, -01.1f);
    glVertex2f(01.1f, -01.1f);
    glVertex2f(01.1f, 01.1f);
    glVertex2f(-01.1f, 01.1f);
    glEnd();
    glPopMatrix();

    // Draw the second box (moving left)
    glPushMatrix();
    glTranslatef(box2PosX, 0.0f, 0.0f); // Move box2 horizontally
    glColor3f(0.0f, 0.0f, 1.0f); // Blue color
    glBegin(GL_QUADS);
     glVertex2f(-01.1f, -01.1f);
    glVertex2f(01.1f, -01.1f);
    glVertex2f(01.1f, 01.1f);
    glVertex2f(-01.1f, 01.1f);
    glEnd();
    glPopMatrix();

    glutSwapBuffers(); // Swap the buffers for smooth animation
}

// Function to update the positions of the boxes
void update(int value) {
    box1PosX += speed; // Move box1 to the right
    box2PosX -= speed; // Move box2 to the left

    // Reset positions if boxes go out of bounds
    if (box1PosX > 10.1f) {
        box1PosX = -10.1f;
    }
    if (box2PosX < -10.1f) {
        box2PosX = 10.1f;
    }

    glutPostRedisplay();          // Request a redraw
    glutTimerFunc(16, update, 0); // Call update again after 16 ms (~60 FPS)
}

// Initialize OpenGL settings
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set the background color to black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0); // Set the coordinate system
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Opposite Moving Boxes");

    init();

    glutDisplayFunc(display);          // Set the display function
    glutTimerFunc(160, update, 0);      // Set the update function for animation

    glutMainLoop(); // Enter the GLUT event loop
    return 0;
}
