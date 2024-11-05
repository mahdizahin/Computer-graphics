#include <GL/glut.h>

// Function to draw the red square
void drawRedSquare() {
    glColor3f(1.0f, 0.0f, 0.0f); // Set color to red
    glBegin(GL_QUADS);
        glVertex2f(1.0f, 5.0f); // Point A
        glVertex2f(1.0f, 7.0f); // Point B
        glVertex2f(3.0f, 7.0f); // Point C
        glVertex2f(3.0f, 5.0f); // Point D
    glEnd();
}

// Function to draw the green arrow
void drawGreenArrow() {
    glColor3f(0.0f, 1.0f, 0.0f); // Set color to green
    glBegin(GL_POLYGON);
        glVertex2f(5.0f, 5.0f);     // Point L
        glVertex2f(5.0f, 6.0f);     // Point K
        glVertex2f(7.0f, 6.0f);     // Point M
        glVertex2f(6.99f, 6.76f);   // Point N
        glVertex2f(8.26f, 5.53f);   // Point O
        glVertex2f(6.97f, 4.21f);   // Point P
        glVertex2f(7.0f, 5.0f);     // Point Q
    glEnd();
}

// Function to draw the purple triangle
void drawPurpleTriangle() {
    glColor3f(0.5f, 0.0f, 0.5f); // Set color to purple
    glBegin(GL_TRIANGLES);
        glVertex2f(3.0f, 3.0f); // Point E
        glVertex2f(3.0f, 1.0f); // Point F
        glVertex2f(1.0f, 2.0f); // Point G
    glEnd();
}

// Function to draw the yellow triangle
void drawYellowTriangle() {
    glColor3f(1.0f, 1.0f, 0.0f); // Set color to yellow
    glBegin(GL_TRIANGLES);
        glVertex2f(5.0f, 1.0f); // Point H
        glVertex2f(6.0f, 3.0f); // Point I
        glVertex2f(7.0f, 1.0f); // Point J
    glEnd();
}

// Function to draw the x-axis line
void drawXAxis() {
    glColor3f(0.0f, 0.0f, 0.0f); // Set color to black
    glLineWidth(2.0f); // Set line width
    glBegin(GL_LINES);
        glVertex2f(0.0f, 4.0f); // Point R
        glVertex2f(10.0f, 4.0f); // Point S
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Call each object drawing function
    drawRedSquare();
    drawGreenArrow();
    drawPurpleTriangle();
    drawYellowTriangle();
    drawXAxis(); // Draw the x-axis line

    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to white

    // Set up the orthogonal projection with a suitable viewing area
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 10.0, 0.0, 10.0); // Adjust this as needed to view all objects properly
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Multiple Objects with X-Axis Line");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
