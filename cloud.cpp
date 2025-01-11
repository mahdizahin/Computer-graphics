#include <GL/freeglut.h>
#include <cmath>

// Function to draw a circle (used for cloud)
void drawCircle(float x, float y, float radius) {
    int triangleAmount = 50;  // Number of triangles used to draw circle
    float angle;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);  // Center of circle
    for (int i = 0; i <= triangleAmount; i++) {
        angle = i * 2.0f * M_PI / triangleAmount;
        glVertex2f(x + (cos(angle) * radius), y + (sin(angle) * radius));
    }
    glEnd();
}

// Function to draw the sky gradient
void drawSky() {
    glBegin(GL_QUADS);
    // Top part of the sky (dark blue)
    glColor3f(0.1f, 0.1f, 0.4f);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);

    // Bottom part of the sky (lighter blue)
    glColor3f(0.4f, 0.6f, 1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();
}

// Function to draw a cloud using multiple circles
void drawCloud(float x, float y) {
    glColor3f(1.0f, 1.0f, 1.0f);  // Cloud color (white)
    drawCircle(x, y, 0.1f);
    drawCircle(x + 0.1f, y + 0.05f, 0.1f);
    drawCircle(x + 0.2f, y, 0.1f);
    drawCircle(x + 0.1f, y - 0.05f, 0.1f);
    drawCircle(x - 0.05f, y, 0.08f);
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the sky background
    drawSky();

    // Draw clouds
    drawCloud(-0.5f, 0.5f);
    drawCloud(0.2f, 0.6f);
    drawCloud(-0.3f, 0.3f);

    glutSwapBuffers();
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1200, 800);
    glutCreateWindow("Cloud with Dark Blue Sky");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Black background
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
