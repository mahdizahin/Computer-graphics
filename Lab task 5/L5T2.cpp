#include <GL/freeglut.h>
#include <cmath>

float wheelAngle = 0.0f; // Rotation angle of the wheels
float carPosX = -10.0f;   // Car's initial horizontal position
float speed = 0.1f;     // Car's speed

// Function to draw a circle (wheel)
void drawCircle(float x, float y, float radius, int segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= segments; ++i) {
        float angle = 2.0f * M_PI * i / segments;
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();
}

// Function to display the car
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Draw the car body
    glPushMatrix();
    glTranslatef(carPosX, 0.0f, 0.0f); // Move the car horizontally

    // Tesla car body (sleek design)
    glColor3f(0.1f, 0.1f, 0.1f); // Dark gray color for the body
    glBegin(GL_POLYGON);
    glVertex2f(-05.5f, 01.1f);
    glVertex2f(05.5f, 01.1f);
    glVertex2f(04.4f, 03.3f);
    glVertex2f(-04.4f, 03.3f);
    glEnd();

    // Tesla roof (sloping design)
    glBegin(GL_POLYGON);
    glVertex2f(-04.0f, 03.0f);//e
    glVertex2f(04.0f, 03.0f);//f
    glVertex2f(02.0f, 04.5f);
    glVertex2f(-02.0f, 04.5f);
    glEnd();

    // Windows (sleek, tinted)
    glColor3f(0.2f, 0.2f, 0.3f); // Tinted blue-gray
    glBegin(GL_POLYGON);
    glVertex2f(-03.5f, 3.0f);
    glVertex2f(-01.5f, 3.0f);
    glVertex2f(-01.0f, 04.0f);
    glVertex2f(-03.0f, 04.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(1.5f, 3.0f);
    glVertex2f(3.5f, 03.0f);
    glVertex2f(3.0f, 04.0f);
    glVertex2f(01.0f, 4.0f);
    glEnd();

    // Wheels
    glPushMatrix();
    glTranslatef(-03.0f, 0.5f, 0.0f); // Left wheel position
    glRotatef(wheelAngle, 0.0f, 0.0f, 1.0f); // Rotate the wheel
    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    drawCircle(0.0f, 0.0f, 01.0f, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(03.0f, 0.5f, 0.0f); // Right wheel position
    glRotatef(wheelAngle, 0.0f, 0.0f, 1.0f); // Rotate the wheel
    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    drawCircle(0.0f, 0.0f, 01.0f, 50);
    glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
}

// Function to update the car's position and wheel rotation
void update(int value) {
    carPosX += speed; // Move the car to the right
    wheelAngle -= 5.0f; // Rotate the wheels

    // Reset the car's position when it moves off-screen
    if (carPosX > 12.0f) {
        carPosX = -12.0f;
    }

    glutPostRedisplay();          // Request a redraw
    glutTimerFunc(16, update, 0); // Call update again after 16 ms (~60 FPS)
}

// Initialize OpenGL settings
void init() {
    glClearColor(0.5f, 0.7f, 1.0f, 1.0f); // Light blue background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-15.0, 15.0, -10.0, 10.0); // Set the coordinate system
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Tesla Car with Rotating Wheels");

    init();

    glutDisplayFunc(display);          // Set the display function
    glutTimerFunc(16, update, 0);      // Set the update function for animation

    glutMainLoop(); // Enter the GLUT event loop
    return 0;
}
