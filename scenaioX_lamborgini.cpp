#include <GL/freeglut.h>
#include <cmath>

// Cloud position variable
float carSpeed = -10.5f;
float cloudX = -1.5f;  // Initial X position of the cloud
float skyColorFactor = 0.0f;  // This will control the transition



//rain
const int numRaindrops = 1000;  // Number of raindrops
float rainX[numRaindrops];      // X positions of raindrops
float rainY[numRaindrops];      // Y positions of raindrops
float rainSpeed[numRaindrops];  // Speed of each raindrop
bool isRaining = false;         // Whether it is raining

//Weather States
enum WeatherState { CLEAR, OVERCAST, RAIN };
WeatherState currentWeather = CLEAR;  // Starting weather state
//
// Function prototypes
void initRain();
void drawRain();
void updateRain();
void changeWeather();

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

void initRain() {
    for (int i = 0; i < numRaindrops; ++i) {
        rainX[i] = rand() % 500;  // Random X position across the width of the screen
        rainY[i] = rand() % 500;  // Random Y position at the top of the screen
        rainSpeed[i] = 0.5f + (rand() % 10) * 0.1f;  // Random speed for each raindrop
    }
    isRaining = true;
}
void drawRain() {
    glColor3f(0.0f, 0.0f, 1.0f);  // Set color to blue for rain

    // Draw each raindrop
    for (int i = 0; i < numRaindrops; ++i) {
        glBegin(GL_LINES);
        glVertex2f(rainX[i], rainY[i]);
        glVertex2f(rainX[i], rainY[i] - 10);  // Raindrop length
        glEnd();
    }
}
void updateRain() {
    if (isRaining) {
        for (int i = 0; i < numRaindrops; ++i) {
            rainY[i] -= rainSpeed[i];  // Move the raindrop down

            // Reset raindrop to the top if it goes off the bottom of the screen
            if (rainY[i] < 0) {
                rainY[i] = 500.0f;  // Reposition at the top
                rainX[i] = rand() % 500;  // Random X position
            }
        }
    }
}
/*
void changeWeather(int value) {
    switch (currentWeather) {
        case CLEAR:
            // Transition to overcast
            skyColorFactor += 0.001f;
            if (skyColorFactor >= 1.0f) {
                currentWeather = OVERCAST;
            }
            break;
        case OVERCAST:
            // Transition to rain
            if (!isRaining) {
                initRain();  // Start raining when overcast
            }
            break;
        case RAIN:
            // Keep raining, can add more weather states if needed
            break;
    }
    glutPostRedisplay();
    glutTimerFunc(5000, changeWeather, 0);  // Change weather every 5 seconds
}*/
// Function to change the weather state
void changeWeather() {
    switch (currentWeather) {
        case CLEAR:
            skyColorFactor = 0.0f;
            isRaining = false;
            break;
        case OVERCAST:
            skyColorFactor = 0.5f;
            isRaining = false;
            break;
        case RAIN:
            skyColorFactor = 1.0f;
            if (!isRaining) initRain();
            break;
    }
    glutPostRedisplay();
}
// Function to handle keyboard input
void handleKeyboard(unsigned char key, int x, int y) {
    if (key == '1') {
        currentWeather = CLEAR;
    } else if (key == '2') {
        currentWeather = OVERCAST;
    } else if (key == '3') {
        currentWeather = RAIN;
    }
    changeWeather();
}

// Function to draw the sky gradient
/*
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

void drawSky() {
    glBegin(GL_QUADS);

    // Interpolate between clear and overcast colors based on skyColorFactor
    float r = 0.4f + (0.3f * skyColorFactor);  // From blue (0.4) to gray (0.7)
    float g = 0.6f + (0.1f * skyColorFactor);  // From light blue (0.6) to grayish (0.7)
    float b = 1.0f - (0.3f * skyColorFactor);  // From blue (1.0) to gray (0.7)

    glColor3f(r, g, b);  // Set the sky color based on skyColorFactor

    glVertex2f(0.0f, 500.0f);
    glVertex2f(500.0f, 500.0f);
    glVertex2f(500.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);

    glEnd();
}*/

void drawSky() {
    glBegin(GL_QUADS);

    // Top part of the sky (interpolating from dark blue to grayish)
    float topR = 0.1f + (0.3f * skyColorFactor);  // From dark blue (0.1) to grayish (0.4)
    float topG = 0.1f + (0.3f * skyColorFactor);  // From dark blue (0.1) to grayish (0.4)
    float topB = 0.4f - (0.3f * skyColorFactor);  // From blue (0.4) to gray (0.1)

    glColor3f(topR, topG, topB);  // Set the top part color
    glVertex2f(0.0f, 500.0f);     // Top-left corner
    glVertex2f(500.0f, 500.0f);   // Top-right corner

    // Bottom part of the sky (interpolating from light blue to grayish)
    float bottomR = 0.4f + (0.3f * skyColorFactor);  // From light blue (0.4) to grayish (0.7)
    float bottomG = 0.6f + (0.2f * skyColorFactor);  // From light blue (0.6) to grayish (0.8)
    float bottomB = 1.0f - (0.3f * skyColorFactor);  // From blue (1.0) to gray (0.7)

    glColor3f(bottomR, bottomG, bottomB);  // Set the bottom part color
    glVertex2f(500.0f, 0.0f);      // Bottom-right corner
    glVertex2f(0.0f, 0.0f);        // Bottom-left corner

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
void drawTree(float x, float y) {
    // Draw the trunk (a gradient-like brown color)
    glColor3f(0.55f, 0.27f, 0.07f);  // Main brown color for the trunk
    glBegin(GL_QUADS);
    glVertex2f(x - 5, y);  // Bottom-left
    glVertex2f(x + 5, y);  // Bottom-right
    glVertex2f(x + 5, y + 40);  // Top-right
    glVertex2f(x - 5, y + 40);  // Top-left
    glEnd();

    // Draw branches (lines extending from the trunk)
    glColor3f(0.6f, 0.3f, 0.1f);  // A darker brown for branches
    glBegin(GL_LINES);
    glVertex2f(x - 5, y + 30);  // Left branch base
    glVertex2f(x - 20, y + 50);  // Left branch end
    glVertex2f(x + 5, y + 30);   // Right branch base
    glVertex2f(x + 20, y + 50);  // Right branch end
    glEnd();

    // Draw the canopy (multiple circles of different shades of green for depth)
    glColor3f(0.0f, 0.5f, 0.0f);  // Dark green for the bottom part of the canopy
    drawCircle(x, y + 50, 25);  // Bottom circle (larger)

    glColor3f(0.0f, 0.6f, 0.0f);  // Medium green for the middle layer
    drawCircle(x - 15, y + 70, 20);  // Left circle
    drawCircle(x + 15, y + 70, 20);  // Right circle

    glColor3f(0.0f, 0.7f, 0.0f);  // Lighter green for the top part of the canopy
    drawCircle(x, y + 90, 15);  // Top circle (smallest)
}

 void drawCar(float x, float y, float scale) {
    // ---- Car Body ----
    glColor3f(1.0f, 0.55f, 0.0f);  // Orange color for the car body
    glBegin(GL_POLYGON);

     ///demo glVertex2f(x + .0f * scale, y + .0f * scale);
    glVertex2f(x + 82.850f * scale, y + 209.150f * scale);//n
    glVertex2f(x + 93.860f * scale, y + 192.0f * scale);   // c
    glVertex2f(x + 119.0f * scale, y + 185.0f * scale);//m
    glVertex2f(x + 172.0f * scale, y + 184.0f * scale);//k
    glVertex2f(x + 316.0f * scale, y + 183.0f * scale);//l
    glVertex2f(x + 367.0f * scale, y + 182.0f * scale);//j
    glVertex2f(x + 410.0f * scale, y + 184.0f * scale); // f
     glVertex2f(x + 412.0f * scale, y + 193.220f * scale);//0
     glVertex2f(x + 410.0f * scale, y + 200.0f * scale);//p
    glVertex2f(x + 412.0f * scale, y + 203.0f * scale);//q
    glVertex2f(x + 396.0f * scale, y + 213.810f * scale);//r
    glVertex2f(x + 373.50f * scale, y + 223.0f * scale);//s
    glVertex2f(x + 355.950f * scale, y + 229.510f * scale);//t

     glVertex2f(x + 344.0f * scale, y + 231.0f * scale); // i
    glVertex2f(x + 269.0f * scale, y + 253.0f * scale);  //h
    glVertex2f(x + 147.0f * scale, y + 245.0f * scale); // e
    glVertex2f(x + 89.0f * scale, y + 237.0f * scale); // d
    glEnd();


    // ---- Windows ----
    glColor3f(0.0f, 0.0f, 0.0f);  // Black windows
    glBegin(GL_POLYGON);  // Left window
    glVertex2f(x + 202.50f * scale, y + 243.0f * scale);//w
    glVertex2f(x + 214.0f * scale, y + 248.0f * scale);//z
     glVertex2f(x + 237.20f * scale, y + 250.50f * scale);//a1
      glVertex2f(x + 262.0f * scale, y + 251.0f * scale);//b1
       glVertex2f(x +290.50f * scale, y +245.0f * scale);//c1

    glVertex2f(x + 326.870f * scale, y + 231.630f * scale);//d1
     glVertex2f(x + 310.50f * scale, y + 227.60f * scale);//e1
    glVertex2f(x + 299.340f * scale, y + 226.50f * scale);//f1
     glVertex2f(x +244.20f * scale, y + 232.50f * scale);//g1
    glEnd();






    // ---- bar ----
    glColor3f(0.0f, 0.0f, 0.0f);  // Black windows
    glBegin(GL_POLYGON);
    glVertex2f(x + 202.50f * scale, y + 243.0f * scale);//u1
    glVertex2f(x + 214.0f * scale, y + 248.0f * scale);//v1
    glVertex2f(x + 237.20f * scale, y + 250.50f * scale);//w1
    glVertex2f(x + 262.0f * scale, y + 251.0f * scale);//z1
    glVertex2f(x +290.50f * scale, y +245.0f * scale);//a2
    glVertex2f(x + 326.870f * scale, y + 231.630f * scale);//s1
    glVertex2f(x + 310.50f * scale, y + 227.60f * scale);//t1

    glEnd();








     // ---- Headlight upper ----
    glColor3f(0.23f, 0.255f, 0.2f); // Darker grey, closer to headlight
    glBegin(GL_POLYGON);
    glVertex2f(x + 372.50f * scale, y + 219.50f * scale);//h1

    glVertex2f(x + 393.30f * scale, y + 206.10f * scale);//i1
    glVertex2f(x + 407.950f * scale, y + 203.690f * scale);//n1
     glVertex2f(x + 393.180f * scale, y + 213.850f * scale);//o

    glEnd();

    // ---- Headlight lower ----
    glColor3f(0.23f, 0.255f, 0.2f); // Darker grey, closer to headlight grey
    glBegin(GL_POLYGON);
    glVertex2f(x + 393.30f * scale, y + 206.10f * scale);//i1
    glVertex2f(x + 384.020f * scale, y + 192.250f * scale);//j1
    glVertex2f(x + 395.0f * scale, y + 185.0f * scale);//k1
    glVertex2f(x +407.950f * scale, y +186.60f * scale);//l1

    glVertex2f(x + 407.5870f * scale, y + 193.6630f * scale);//m1
    glVertex2f(x + 407.950f * scale, y + 203.690f * scale);//n1

    glEnd();



    glEnd();

    // ---- Wheels ----
    glColor3f(0.0f, 0.0f, 0.0f);  // Black for wheels
    //drawCircle(x + 80.0f * scale, y - 30.0f * scale, 30.0f * scale);
   drawCircle(x + 343.30f * scale, y + 198.0f * scale, 24.0f * scale);  // Right wheel
    drawCircle(x + 147.090f * scale, y + 199.90f * scale, 26.0f * scale);// Left wheel

    // ---- Wheel Rims ----
   glColor3f(0.1f, 0.1f, 0.1f); // Dark grey color, close to black
     drawCircle(x + 147.090f * scale, y + 199.90f * scale, 23.0f * scale);// Left wheel
      drawCircle(x + 343.30f * scale, y + 198.0f * scale, 21.0f * scale);  // Right wheel
}

// ---- Circle Helper Function ----
void drawCircle2(float x, float y, float radius) {
    int numSegments = 100;
    float angle;
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; i++) {
        angle = 2.0f * 3.1415926f * i / numSegments;
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();
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

    glPushMatrix();
    glTranslatef(carSpeed, 0.0f, 0.0f);
     drawCar(-05.10f, 70.0f, 0.3);  // Smaller car
    // drawCar(40.0f, 200.0f, 0.5f);  // Smaller car

    glPopMatrix();

     // Draw cars at different positions and sizes

   // drawCar(-05.10f, -10.0f, 0.75f);  // Smaller car


// Draw the tree at a specific position (e.g., (200, 150))
    drawTree(200.0f, 0.0f);
    drawTree(100.0f, 0.0f);
    drawTree(300.0f, 0.0f);
    drawTree(350.0f, 0.0f);
 // If it's raining, draw the rain
    if (isRaining) {
        drawRain();
    }
    glutSwapBuffers();


}
// Function to draw a cloud using multiple circles

void update(int value) {
/*
    if (skyColorFactor < 1.0f) {
        //skyColorFactor += 0.001f;  // Incrementally change the color
    }else if (!isRaining) {
       // initRain();  // Start raining once the sky is overcast
    }*/
    cloudX += 1.0f;  // Move cloud to the right

    carSpeed +=0.5f;

    // Reset position if cloud goes off the right edge
    if (cloudX > 500.5f) {
        cloudX = -200.5f;
    }
     if (carSpeed > 500.5f) {
        carSpeed = -200.5f;
    }
    updateRain();  // Update raindrop positions

    // Call the weather change function
   //k changeWeather(value);
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
    glutKeyboardFunc(handleKeyboard);
    glutTimerFunc(16, update, 0);  // Start timer
   //k glutTimerFunc(5000, changeWeather, 0);  // Start weather change timer

    glutMainLoop();

    return 0;
}
