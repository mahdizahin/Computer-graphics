#include <windows.h>
#include <GL/glut.h>
#include <math.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);

    glColor3f(1.0, 1.0, 1.0); // White color

    // Define semi-circle
    float radius = 0.5;
    float pi = 3.14159265359;
    for (int i = 0; i <= 180; i++) {
        float angle = i * pi / 180.0;
        glVertex2f(cos(angle) * radius, sin(angle) * radius);
    }

    glEnd();
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Black background
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // 2D projection
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500); // Window size
    glutInitWindowPosition(100, 100); // Window position
    glutCreateWindow("Semi Circle"); // Window title
    init();
    glutDisplayFunc(display); // Display function
    glutMainLoop();
    return 0;
}
