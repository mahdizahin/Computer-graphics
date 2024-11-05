#include<windows.h>
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);


    glColor3f(0.0f, 0.0f, 0.0f); //black


    glLineWidth(5.0f);


    glBegin(GL_LINE_LOOP);
        glVertex2f(1.0f, 1.0f); // Point A
        glVertex2f(1.0f, 4.0f); // Point B
        glVertex2f(6.0f, 4.0f); // Point C
        glVertex2f(6.0f, 1.0f); // Point D
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //   background color white
    glColor3f(0.0f, 0.0f, 0.0f); //   drawing color  black

    // Set up the orthogonal projection with a suitable viewing area
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 10.0, 0.0, 10.0); // Adjust this as needed to view the rectangle properly
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Black Border Rectangle");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
