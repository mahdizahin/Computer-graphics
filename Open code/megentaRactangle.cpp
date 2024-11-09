#include <GL/freeglut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the color to red
    glColor3f(1.0f, 0.0f, 1.0f);

    // Draw a rectangle
    glBegin(GL_QUADS);
        glVertex2f(-0.5f, -0.5f); // Bottom-left corner
        glVertex2f(0.5f, -0.5f);  // Bottom-right corner
        glVertex2f(0.5f, 0.5f);   // Top-right corner
        glVertex2f(-0.5f, 0.5f);  // Top-left corner
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Red Rectangle");

    // Set the clear color to white
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
