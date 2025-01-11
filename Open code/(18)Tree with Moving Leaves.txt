#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <math.h>
#include <cmath>

// Variables for leaves movement
float leafOffset = 0.0f;

// Function to draw the tree trunk
void drawTrunk() {
    glColor3f(0.6f, 0.3f, 0.0f);  // Brown color
    glBegin(GL_POLYGON);
        glVertex2f(-0.05f, -0.5f);
        glVertex2f(0.05f, -0.5f);
        glVertex2f(0.05f, 0.0f);
        glVertex2f(-0.05f, 0.0f);
    glEnd();

}

// Function to draw the leaves
void drawLeaves() {
    glColor3f(0.0f, 1.0f, 0.0f);  // Green color
    glBegin(GL_POLYGON);  // Draw a simple triangle to represent a leaf
        glVertex2f(-0.2f + leafOffset, 0.0f);
        glVertex2f(0.0f + leafOffset, 0.3f);
        glVertex2f(0.2f + leafOffset, 0.0f);
    glEnd();
}

// Function to render the tree with moving leaves
void renderTree() {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the trunk
    drawTrunk();

    // Animate the leaves by slightly changing their position
    drawLeaves();

    glFlush();  // Render the tree
}

// Timer function to update the leaf movement
void timer(int value) {
    // Simulate simple leaf movement (oscillating back and forth)
    leafOffset = 0.01f * sin(value * 0.1f);  // Simple sine wave motion

    // Request a redraw
    glutPostRedisplay();

    // Set up the next timer event
    glutTimerFunc(30, timer, value + 1);  // Update every 30 ms
}

// Initialization function
void init() {
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);  // Light blue background for sky
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);  // Set up the coordinate system
}

// Main display function
void display() {
    renderTree();  // Call the function to render the tree and leaves
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Simple Tree with Moving Leaves");

    init();
    glutDisplayFunc(display);  // Set the display callback
    glutTimerFunc(0, timer, 0);  // Start the timer for animation

    glutMainLoop();  // Enter the GLUT main loop
    return 0;
}
