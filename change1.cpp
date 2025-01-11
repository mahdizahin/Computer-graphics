 #include <GL/glut.h>
#include <math.h>

int weatherState = 0; // 0: Sunny, 1: Overcast, 2: Rainy
float rainDropY = 1.0f;

void drawSun() {
    glColor3f(1.0, 1.0, 0.0); // Yellow color
    float radius = 0.1f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.8f, 0.8f); // Center of the sun
    for (int i = 0; i <= 360; i++) {
        float angle = i * M_PI / 180.0f;
        glVertex2f(0.8f + radius * cos(angle), 0.8f + radius * sin(angle));
    }
    glEnd();
}

void drawCloud(float x, float y) {
    glColor3f(0.7, 0.7, 0.7); // Gray color
    float radius = 0.1f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 360; i++) {
        float angle = i * M_PI / 180.0f;
        glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
    }
    glEnd();
}

void drawRain() {
    glColor3f(0.5, 0.5, 1.0); // Light blue color for raindrops
    for (float x = -1.0f; x <= 1.0f; x += 0.1f) {
        glBegin(GL_LINES);
        glVertex2f(x, rainDropY);
        glVertex2f(x, rainDropY - 0.1f);
        glEnd();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Weather conditions
    if (weatherState == 0) {
        // Sunny
        glClearColor(0.5f, 0.8f, 1.0f, 1.0f); // Blue sky
        drawSun();
    } else if (weatherState == 1) {
        // Overcast
        glClearColor(0.6f, 0.6f, 0.6f, 1.0f); // Gray sky
        drawCloud(-0.6f, 0.8f);
        drawCloud(-0.4f, 0.7f);
        drawCloud(-0.2f, 0.8f);
    } else if (weatherState == 2) {
        // Rainy
        glClearColor(0.2f, 0.2f, 0.4f, 1.0f); // Dark sky
        drawRain();
        rainDropY -= 0.02f;
        if (rainDropY < -1.0f) rainDropY = 1.0f;
    }

    glutSwapBuffers();
}

void timer(int value) {
    weatherState = (weatherState + 1) % 3; // Cycle through weather states
    glutPostRedisplay();
    glutTimerFunc(5000, timer, 0); // Change weather every 5 seconds
}

void init() {
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Weather Change Animation");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(5000, timer, 0);
    glutMainLoop();
    return 0;
}
