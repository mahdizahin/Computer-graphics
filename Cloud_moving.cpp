#include <GL/freeglut.h>
#include <cmath>

// Cloud position variable
float cloudX = -1.5f;  // Initial X position of the cloud
// Function to draw a circle (used for cloud)
void drawCircle(float x, float y, float radius) {
    int triangleAmount = 50;  // Number of triangles used to draw circle
    float angle;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);  // Center of circle
    for (int i = 0; i <= triangleAmount; i++) {
        angle = i * 2.0f * M_PI / triangleAmount;
        glVertex2f(x + (cos(angle) * radius), y + (sin(angle) * radius));
    }
    glEnd();
}

// Function to draw the sky gradient

void drawSky() {
    glBegin(GL_QUADS);

    // Top part of the sky (dark blue)
    glColor3f(0.1f, 0.1f, 0.4f);
    glVertex2f(0.0f, 500.0f);  // Top-left corner
    glVertex2f(500.0f, 500.0f);  // Top-right corner

    // Bottom part of the sky (lighter blue)
    glColor3f(0.4f, 0.6f, 1.0f);
    glVertex2f(500.0f, 0.0f);  // Bottom-right corner
    glVertex2f(0.0f, 0.0f);  // Bottom-left corner

    glEnd();
}

void drawSun(){

    glColor3f(1.0f, 0.9f, 0.2f);  // Sun color (yellow)
    drawCircle(438.26f, 441.12f, 27.5f);//c

}

// Function to draw a cloud using multiple circles

void drawCloud() {
    //Cloud_ID_1
    glColor3f(1.0f, 1.0f, 1.0f);  // Cloud color (white)
    drawCircle(288.75f, 369.81f, 18.54f);//c
    drawCircle(295.29f, 339.22f, 23.34f);//d
    drawCircle(313.16303f, 359.84252f, 18.0f);//e
    drawCircle(251.2f, 354.2f, 24.1f);//f
    drawCircle(213.2f, 344.2f, 14.0f);//g
    drawCircle(232.2f, 344.28f, 15.71f);//h
    drawCircle(276.64f, 341.56f, 15.1f);//i

    //chuto megh cloud_ID_2
    drawCircle(140.0f,368.0f,4.6f);//j
    drawCircle( 147.0f, 366.0f, 3.66f);//k
    drawCircle(  153.0f, 361.0f,6.22f);//l
    drawCircle( 140.34f,359.3f,8.59f);//m
    drawCircle( 148.21f, 357.88f,5.32f);//n
    drawCircle( 129.13f,356.87f, 5.16f);//o
    drawCircle(  135.15f, 361.89f, 4.85f);//p

     //cloud_ID_3
     drawCircle(281.24f,441.43f,7.34f);//q
     drawCircle(286.18f,427.74f,12.5103f );//r
     drawCircle(258.9f,434.37f,10.85f );//t
     drawCircle(269.8f,441.99f,7.5f );//u
     drawCircle(271.36f,427.31f,10.70526f );//v
     drawCircle(256.25f,427.74f,11.85f );//w
     drawCircle(243.13f,426.46f,7.29f );//z

     //Cloud_ID_4
     drawCircle(187.06f,393.48f,20.0f);//b
     drawCircle(207.06f,383.48f,10.0f);//b
     drawCircle(168.06f,375.48f,12.0f);//b

}
// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the sky background
    drawSky();
    drawSun();
    // Apply translation to move the cloud
    glPushMatrix();
    glTranslatef(cloudX, 0.0f, 0.0f);
    drawCloud();
    glPopMatrix();

    glutSwapBuffers();


}
// Function to draw a cloud using multiple circles

void update(int value) {
    cloudX += 1.0f;  // Move cloud to the right

    // Reset position if cloud goes off the right edge
    if (cloudX > 500.5f) {
        cloudX = -200.5f;
    }

    glutPostRedisplay();  // Request display update
    glutTimerFunc(16, update, 0);  // Call update function again after 16 ms
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1080, 1080);
    glutCreateWindow("Cloud with Dark Blue Sky");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Black background
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);

    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);  // Start timer
    glutMainLoop();

    return 0;
}
