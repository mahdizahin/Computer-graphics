#include<windows.h>
#include <GL/glut.h>

void drawx(){
    glColor3f(0.0f, 0.0f, 0.0f );
    glBegin(GL_QUADS);
        glVertex2f(0.0f,4.0f);
        glVertex2f(10.0f,4.0f);
         glVertex2f(10.01f,3.9f);
          glVertex2f(0.0004f,3.90f);
    glEnd();
};

void drawy(){
    glColor3f(0.0f, 0.0f, 0.0f );
    glBegin(GL_QUADS);
        glVertex2f(4.0f,8.0f);
        glVertex2f(4.07f,8.00f);
         glVertex2f(4.05f,0.0f);//b1
          glVertex2f(4.0f,0.00f);
    glEnd();
};
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
    glBegin(GL_QUADS);
        glVertex2f(5.0f, 5.0f);     // Point L
        glVertex2f(5.0f, 6.0f);     // Point K
        glVertex2f(7.0f, 6.0f);     // Point M
       // glVertex2f(6.99f, 6.76f);   // Point N
        //glVertex2f(8.26f, 5.53f);   // Point O
        //glVertex2f(6.97f, 4.21f);   // Point P
        glVertex2f(7.0f, 5.0f);     // Point Q
    glEnd();
}

void drawGreenArrowpt2() {
     glColor3f(0.0f, 1.0f, 0.0f); // Set color to green
    glBegin(GL_TRIANGLES);
        glVertex2f(6.99f, 6.76f);   // Point N
        glVertex2f(8.26f, 5.53f);   // Point O
        glVertex2f(6.97f, 4.21f);   // Point P
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

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Call each object drawing function
    drawRedSquare();
    drawGreenArrow();
    drawGreenArrowpt2();
    drawPurpleTriangle();
    drawYellowTriangle();
    drawx();
    drawy();

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
    glutCreateWindow("Multiple Objects");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
