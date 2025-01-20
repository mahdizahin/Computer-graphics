#include <GL/glut.h>
#include <cmath>
#include <iostream>

// Initial values for translation and scaling
float translateX = 0.0f;
float translateY = 0.0f;
float scale = 1.0f;

// Function to draw a mountain using sine wave
void drawMountain() {
    glPushMatrix(); // Save the current transformation matrix

    // Apply translation and scaling transformations
    glTranslatef(translateX, translateY, 0.0f);
    glScalef(scale, scale, 1.0f);

    // Set mountain color
    glColor3f(0.4f, 0.26f, 0.13f); // Brownish color

    glBegin(GL_TRIANGLE_STRIP);
    for (float x = 0.0f; x <= 500.0f; x += 1.0f) {
        float y = 200.0f + 50.0f * sin(x * 0.01f); // Sine wave for mountain peaks
        glVertex2f(x, y);
        glVertex2f(x, 0.0f); // Base of the mountain
    }
    glEnd();

    glPopMatrix(); // Restore the previous transformation matrix
}

// Display callback
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawMountain();

    glFlush();
}

// Keyboard controls for moving and scaling
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': translateY += 10.0f; break; // Move up
        case 's': translateY -= 10.0f; break; // Move down
        case 'a': translateX -= 10.0f; break; // Move left
        case 'd': translateX += 10.0f; break; // Move right
        case '+': scale += 0.1f; break;      // Increase size
        case '-': scale -= 0.1f; break;      // Decrease size
    }
    glutPostRedisplay(); // Request redisplay
}

// Initialize OpenGL settings
void init() {
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f); // Sky blue background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mountain Drawing");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
