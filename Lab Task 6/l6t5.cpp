//Develop a scenario where it will rain and gradually create flood

#include <GL/glut.h>

// Screen dimensions
const int WIDTH = 800;
const int HEIGHT = 600;

// Water level
float waterLevel = 0.0f;

// Number of raindrops
const int MAX_RAIN = 500;
struct RainDrop {
    float x, y;
};

// Array to store raindrops
RainDrop rainDrops[MAX_RAIN];

// Function to initialize OpenGL
void initGL() {
    glClearColor(0.1f, 0.1f, 0.2f, 1.0f);  // Set background color (dark blue)
    glEnable(GL_POINT_SMOOTH);
    glPointSize(3.0f);  // Size of raindrop points
}

// Simple random number generator
float randFloat() {
    return (rand() % 2000 - 1000) / 1000.0f;  // Random float between -1.0 and 1.0
}

// Function to draw the scene
void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the ground (flooded area)
    glColor3f(0.1f, 0.5f, 0.1f); // Dark green for the ground
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -0.8f); // Left corner of the ground
        glVertex2f(1.0f, -0.8f);  // Right corner of the ground
        glVertex2f(1.0f, -1.0f);  // Right bottom corner
        glVertex2f(-1.0f, -1.0f); // Left bottom corner
    glEnd();

    // Draw the water (flooded area)
    glColor3f(0.0f, 0.0f, 1.0f); // Blue for water
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -0.8f);  // Left corner
        glVertex2f(1.0f, -0.8f);   // Right corner
        glVertex2f(1.0f, -0.8f + waterLevel);  // Right height depending on flood level
        glVertex2f(-1.0f, -0.8f + waterLevel); // Left height depending on flood level
    glEnd();

    // Draw the raindrops
    glColor3f(0.7f, 0.7f, 1.0f); // Light blue for raindrops
    glBegin(GL_POINTS);
    for (int i = 0; i < MAX_RAIN; i++) {
        if (rainDrops[i].y >= -1.0f) {
            glVertex2f(rainDrops[i].x, rainDrops[i].y); // Draw each raindrop at its position
        }
    }
    glEnd();

    glutSwapBuffers();
}

// Function to update the simulation (rain and flood)
void update(int value) {
    // Add new raindrop if the water level hasn't reached max flood
    if (waterLevel < 0.6f) {
        // Create a new raindrop
        for (int i = 0; i < MAX_RAIN; i++) {
            if (rainDrops[i].y < -1.0f) {  // Find an empty raindrop slot
                rainDrops[i].x = randFloat();  // Randomize x
                rainDrops[i].y = 1.0f;         // Start at the top
                break;
            }
        }
    }

    // Update position of raindrops
    for (int i = 0; i < MAX_RAIN; i++) {
        rainDrops[i].y -= 0.02f;  // Raindrops fall down
        if (rainDrops[i].y < -1.0f) { // If raindrop goes below the screen, reset it
            rainDrops[i].y = 1.0f;
            rainDrops[i].x = randFloat(); // Reset raindrop position
        }
    }

    // Gradually increase the water level (simulate flood)
    if (waterLevel < 0.6f) {
        waterLevel += 0.001f; // Slow increase in water level
    }

    glutPostRedisplay(); // Request redraw of the scene
    glutTimerFunc(50, update, 0); // Call the update function every 50 ms
}

// Function to handle keyboard input
void keyPressed(unsigned char key, int x, int y) {
    if (key == 27) {  // ESC key to exit
        exit(0);
    }
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Rain and Flood Simulation");

    initGL();

    // Set up callback functions
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(keyPressed);
    glutTimerFunc(25, update, 0); // Start the update function

    // Start the GLUT main loop
    glutMainLoop();
    return 0;
}
