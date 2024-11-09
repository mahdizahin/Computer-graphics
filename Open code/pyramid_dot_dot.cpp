#include <iostream>
#include <vector>
#include <GL/glut.h>

using namespace std;

struct Point {
    int x, y;
};

vector<Point> points = {
    {4, 6}, {5, 8}, {6, 10}, {7, 12}, {8, 10}, {9, 8}, {10, 6}, {11, 4}, {3, 4}
};

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5.0);
    glColor3f(1.0, 0.0, 0.0); // Set color to red
    glBegin(GL_POINTS);

    for (const auto& point : points) {
        glVertex2i(point.x, point.y);
    }

    glEnd();
    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 15.0, 0.0, 15.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Pyramid Points");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
