#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <windows.h>
// Global variables to handle scene transitions
bool isDay = false; // Start with night scene
float timeOfDay = 0.0f; // Simulates time of day (0.0f to 1.0f)

// Function to render the night scene
void renderNightScene() {
    // Clear the screen and set the background to dark blue (night sky)
    glClearColor(0.0f, 0.0f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a moon (yellow circle)
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100;
        glVertex2f(0.2f * cos(angle) - 0.5f, 0.2f * sin(angle) + 0.5f);
    }
    glEnd();

    // Draw some stars
    glColor3f(1.0f, 1.0f, 1.0f); // White for stars
    glBegin(GL_POINTS);
    glVertex2f(-0.7f, 0.8f);
    glVertex2f(0.3f, 0.6f);
    glVertex2f(-0.1f, 0.3f);
    glVertex2f(0.6f, 0.9f);
    glVertex2f(-0.9f, 0.4f);
    glEnd();

    glFlush(); // Render the night scene
}

// Function to render the day scene
void renderDayScene() {
    // Clear the screen and set the background to light blue (day sky)
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a sun (yellow circle)
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100;
        glVertex2f(0.2f * cos(angle) + 0.5f, 0.2f * sin(angle) + 0.5f);
    }
    glEnd();

    // Draw some clouds (white circles)
    glColor3f(1.0f, 1.0f, 1.0f); // White
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100;
        glVertex2f(0.15f * cos(angle) - 0.7f, 0.1f * sin(angle) + 0.7f);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100;
        glVertex2f(0.2f * cos(angle) - 0.5f, 0.1f * sin(angle) + 0.8f);
    }
    glEnd();

    glFlush(); // Render the day scene
}

// Timer callback to transition from night to day
void timer(int value) {
    // Simulate the passage of time
    timeOfDay += 0.01f;
    if (timeOfDay >= 1.0f) {
        isDay = true; // Change to day after "sunrise"
    }

    // Redraw the scene based on the time of day
    if (isDay) {
        renderDayScene();
    } else {
        renderNightScene();
    }

    // Keep updating every 100 ms
    glutTimerFunc(10, timer, 0);
}

// Initialization function
void init() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

// Main display function
void display() {
    if (isDay) {
        renderDayScene(); // Render the day scene
    } else {
        renderNightScene(); // Render the night scene
    }
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Sunrise Simulation");

    init();
    glutDisplayFunc(display);

    // Start the timer for the transition
    glutTimerFunc(100, timer, 0);

    glutMainLoop();
}
