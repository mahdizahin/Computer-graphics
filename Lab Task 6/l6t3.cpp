//Develop a code that will have four different objects (keep it simple). The objects will move to the left, right, up and down in a loop. 


#include <GL/glut.h>

float leftObjectX = -0.8f, rightObjectX = 0.8f, upObjectY = 0.8f, downObjectY = -0.8f;

void drawObject(float x, float y) {
    glBegin(GL_QUADS);
        glVertex2f(x - 0.05f, y - 0.05f);
        glVertex2f(x + 0.05f, y - 0.05f);
        glVertex2f(x + 0.05f, y + 0.05f);
        glVertex2f(x - 0.05f, y + 0.05f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);  // Red for the left object
    drawObject(leftObjectX, 0.0f);

    glColor3f(0.0f, 1.0f, 0.0f);  // Green for the right object
    drawObject(rightObjectX, 0.0f);

    glColor3f(0.0f, 0.0f, 1.0f);  // Blue for the up object
    drawObject(0.0f, upObjectY);

    glColor3f(1.0f, 1.0f, 0.0f);  // Yellow for the down object
    drawObject(0.0f, downObjectY);

    glutSwapBuffers();
}

void update(int value) {
    leftObjectX -= 0.01f;
    if (leftObjectX < -1.0f) leftObjectX = 1.0f;  // Wrap around when off-screen

    rightObjectX += 0.01f;
    if (rightObjectX > 1.0f) rightObjectX = -1.0f;  // Wrap around when off-screen

    upObjectY += 0.01f;
    if (upObjectY > 1.0f) upObjectY = -1.0f;  // Wrap around when off-screen

    downObjectY -= 0.01f;
    if (downObjectY < -1.0f) downObjectY = 1.0f;  // Wrap around when off-screen

    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Moving Objects");

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);  // Set background color
    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0);  // Start the update function

    glutMainLoop();
    return 0;
}
