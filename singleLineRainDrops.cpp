#include <GL/glut.h>
#include <math.h>

float rainDropY = 1.0f; // Initial position of raindrops

void drawRain() {
    glColor3f(0.5, 0.5, 1.0); // Light blue color for raindrops
    for (float x = -1.0f; x <= 1.0f; x += 0.02f) { // More raindrops by reducing spacing
        glBegin(GL_LINES);
        glVertex2f(x, rainDropY);
        glVertex2f(x, rainDropY - 0.05f); // Smaller drops
        glEnd();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.2f, 0.2f, 0.4f, 1.0f); // Dark sky for rain scene
    drawRain();
    glutSwapBuffers();
}

void timer(int value) {
    rainDropY -= 0.01f; // Rain speed
    if (rainDropY < -1.0f) rainDropY = 1.0f; // Reset raindrops when they go off-screen
    glutPostRedisplay();
    glutTimerFunc(30, timer, 0); // Update rain position more frequently for smoother animation
}

void init() {
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Heavy Rain Animation");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(10, timer, 0);
    glutMainLoop();
    return 0;
}
