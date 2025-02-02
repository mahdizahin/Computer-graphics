#include <GL/freeglut.h>
#include <cmath>

// Cloud position variable
float carSpeed = -10.5f;
float cloudX = -1.5f;  // Initial X position of the cloud
float skyColorFactor = 0.0f;  // This will control the transition

float sunY = 441.12f; // Initial Y position of the sun
bool isRising = false; // Flag for sun movement

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
void drawSnow() {
    glColor3f(1.0f, 1.0f, 1.0f);  // Set color to white for snow

    // Draw each snowflake
    for (int i = 0; i < numRaindrops; ++i) {
        glBegin(GL_POLYGON);
        for (int j = 0; j < 6; ++j) {  // Approximate snowflake shape
            float angle = j * 60.0f * 3.14159f / 180.0f;
            float xOffset = 2.0f * cos(angle);  // Small circular shape
            float yOffset = 2.0f * sin(angle);
            glVertex2f(rainX[i] + xOffset, rainY[i] + yOffset);
        }
        glEnd();
    }
}

void updateSnow() {
    if (isRaining) {  // Rename this to isSnowing if needed
        for (int i = 0; i < numRaindrops; ++i) {
            rainY[i] -= rainSpeed[i] * 0.5f;  // Slow snowfall
            rainX[i] += (rand() % 3 - 1) * 0.5f;  // Small random side drift

            // Reset snowflake to the top if it goes off the bottom
            if (rainY[i] < 0) {
                rainY[i] = 500.0f;  // Reposition at the top
                rainX[i] = rand() % 500;  // Random X position
            }
        }
    }
}


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



void drawSun() {
    glColor3f(1.0f, 0.9f, 0.2f);  // Sun color (yellow)
    drawCircle(438.26f, sunY, 27.5f);
}
void mouse(int button, int state, int x, int y) {
    if (state == GLUT_DOWN) {
        if (button == GLUT_LEFT_BUTTON) {
            sunY += 10.0f; // Move sun up
        } else if (button == GLUT_RIGHT_BUTTON) {
            sunY -= 10.0f; // Move sun down
        }
        glutPostRedisplay(); // Redraw scene
    }
}


// Function to draw a cloud using multiple circles
/*
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

}*/
void drawCloud(float offsetX, float offsetY, float scale) {
    glColor3f(1.0f, 1.0f, 1.0f);  // Cloud color (white)

    // Cloud_ID_1
    drawCircle(offsetX + scale * 288.75f, offsetY + scale * 369.81f, scale * 18.54f);
    drawCircle(offsetX + scale * 295.29f, offsetY + scale * 339.22f, scale * 23.34f);
    drawCircle(offsetX + scale * 313.16f, offsetY + scale * 359.84f, scale * 18.0f);
    drawCircle(offsetX + scale * 251.2f, offsetY + scale * 354.2f, scale * 24.1f);
    drawCircle(offsetX + scale * 213.2f, offsetY + scale * 344.2f, scale * 14.0f);
    drawCircle(offsetX + scale * 232.2f, offsetY + scale * 344.28f, scale * 15.71f);
    drawCircle(offsetX + scale * 276.64f, offsetY + scale * 341.56f, scale * 15.1f);

    // Cloud_ID_2 (Smaller Cloud)
    drawCircle(offsetX + scale * 140.0f, offsetY + scale * 368.0f, scale * 4.6f);
    drawCircle(offsetX + scale * 147.0f, offsetY + scale * 366.0f, scale * 3.66f);
    drawCircle(offsetX + scale * 153.0f, offsetY + scale * 361.0f, scale * 6.22f);
    drawCircle(offsetX + scale * 140.34f, offsetY + scale * 359.3f, scale * 8.59f);
    drawCircle(offsetX + scale * 148.21f, offsetY + scale * 357.88f, scale * 5.32f);
    drawCircle(offsetX + scale * 129.13f, offsetY + scale * 356.87f, scale * 5.16f);
    drawCircle(offsetX + scale * 135.15f, offsetY + scale * 361.89f, scale * 4.85f);

    // Cloud_ID_3
    drawCircle(offsetX + scale * 281.24f, offsetY + scale * 441.43f, scale * 7.34f);
    drawCircle(offsetX + scale * 286.18f, offsetY + scale * 427.74f, scale * 12.51f);
    drawCircle(offsetX + scale * 258.9f, offsetY + scale * 434.37f, scale * 10.85f);
    drawCircle(offsetX + scale * 269.8f, offsetY + scale * 441.99f, scale * 7.5f);
    drawCircle(offsetX + scale * 271.36f, offsetY + scale * 427.31f, scale * 10.7f);
    drawCircle(offsetX + scale * 256.25f, offsetY + scale * 427.74f, scale * 11.85f);
    drawCircle(offsetX + scale * 243.13f, offsetY + scale * 426.46f, scale * 7.29f);

    // Cloud_ID_4
    drawCircle(offsetX + scale * 187.06f, offsetY + scale * 393.48f, scale * 20.0f);
    drawCircle(offsetX + scale * 207.06f, offsetY + scale * 383.48f, scale * 10.0f);
    drawCircle(offsetX + scale * 168.06f, offsetY + scale * 375.48f, scale * 12.0f);
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


void drawBuilding(float x, float y, int stories) {
    float buildingWidth = 100.0f;
    float storyHeight = 40.0f;

    // Draw building base (rectangle)
    glColor3f(0.6f, 0.4f, 0.2f); // Brown color
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + buildingWidth, y);
    glVertex2f(x + buildingWidth, y + stories * storyHeight);
    glVertex2f(x, y + stories * storyHeight);
    glEnd();

    // Draw building roof (triangle)
    glColor3f(0.5f, 0.1f, 0.1f); // Dark red color
    glBegin(GL_TRIANGLES);
    glVertex2f(x - 10.0f, y + stories * storyHeight);  // Left corner
    glVertex2f(x + buildingWidth + 10.0f, y + stories * storyHeight);  // Right corner
    glVertex2f(x + buildingWidth / 2.0f, y + stories * storyHeight + 40.0f);  // Top point
    glEnd();

    // Draw windows for each story
    for (int i = 0; i < stories; ++i) {
        float windowY = y + i * storyHeight + 10.0f;

        // Left window
        glColor3f(0.7f, 0.9f, 1.0f); // Light blue color
        glBegin(GL_POLYGON);
        glVertex2f(x + 15.0f, windowY);
        glVertex2f(x + 35.0f, windowY);
        glVertex2f(x + 35.0f, windowY + 20.0f);
        glVertex2f(x + 15.0f, windowY + 20.0f);
        glEnd();

        // Right window
        glBegin(GL_POLYGON);
        glVertex2f(x + 65.0f, windowY);
        glVertex2f(x + 85.0f, windowY);
        glVertex2f(x + 85.0f, windowY + 20.0f);
        glVertex2f(x + 65.0f, windowY + 20.0f);
        glEnd();
    }

    // Draw door
    glColor3f(0.3f, 0.2f, 0.1f); // Dark brown color
    glBegin(GL_POLYGON);
    glVertex2f(x + 40.0f, y);
    glVertex2f(x + 60.0f, y);
    glVertex2f(x + 60.0f, y + 30.0f);
    glVertex2f(x + 40.0f, y + 30.0f);
    glEnd();
}

float laneMarkerWidth = 20.0f; // Width of each lane marker
float laneMarkerGap = 15.0f;  // Gap between lane markers
float laneMarkerY = 75.0f;   // Y position of the lane markers (center of the road)

void drawRoad() {
    // Draw the road base
    glColor3f(0.2f, 0.2f, 0.2f);  // Gray color for the road
    glBegin(GL_QUADS);
    glVertex2f(0.0f, 50.0f);
    glVertex2f(500.0f, 50.0f);
    glVertex2f(500.0f, 100.0f);
    glVertex2f(0.0f, 100.0f);
    glEnd();

    // Draw lane markers
    glColor3f(1.0f, 1.0f, 1.0f);  // White color for lane markers
    for (float x = 0.0f; x < 500.0f; x += laneMarkerWidth + laneMarkerGap) {
        glBegin(GL_QUADS);
        glVertex2f(x, laneMarkerY - 1.0f);
        glVertex2f(x + laneMarkerWidth, laneMarkerY - 1.0f);
        glVertex2f(x + laneMarkerWidth, laneMarkerY + 1.0f);
        glVertex2f(x, laneMarkerY + 1.0f);
        glEnd();
    }
}

// Function to draw a Ground with position and size control
void christmasTree(float x, float y, float scaleX, float scaleY) {
    glPushMatrix(); // Save the current transformation state
    // Apply transformations
    glTranslatef(x, y, 0.0f);  // Move to position (x, y)
    glScalef(scaleX, scaleY, 1.0f); // Scale the Grounf
    //---------------------------------------
   glColor3f(0.255f, 0.690f, 0.333f); // #41B054
    glBegin(GL_POLYGON);
    glVertex2f(80.0f, 65.0f);    // A
    glVertex2f(79.78f, 69.11f);  // B
    glVertex2f(62.92f, 68.1f);   // E
    glVertex2f(73.82f, 78.54f);  // F
    glVertex2f(65.24f, 77.69f);  // G
    glVertex2f(76.22f, 88.83f);  // H
    glVertex2f(68.33f, 87.9f);   // I
    glVertex2f(78.46f, 98.42f);  // J
    glVertex2f(72.59f, 97.1f);   // K
    glVertex2f(80.24f, 106.93f); // L
    glVertex2f(76.3f, 106.0f);   // M
    glVertex2f(82.18f, 115.74f); // N
    glVertex2f(88.05f, 105.84f); // O
    glVertex2f(84.03f, 107.0f);  // P
    glVertex2f(91.92f, 96.95f);  // Q
    glVertex2f(85.81f, 98.26f);  // R
    glVertex2f(95.79f, 87.75f);  // S
    glVertex2f(88.21f, 88.83f);  // T
    glVertex2f(98.8f, 77.77f);   // U
    glVertex2f(90.3f, 78.62f);   // V
    glVertex2f(101.28f, 68.41f); // W
    glVertex2f(84.42f, 69.26f);  // Z
    glVertex2f(85.0f, 65.0f);    // A1
    glEnd();
    //-------------------------------------
    glPopMatrix(); // Restore the previous transformation state
}

// Function to draw a Ground with position and size control
void drawGround(float x, float y, float scaleX, float scaleY) {
    glPushMatrix(); // Save the current transformation state

    // Apply transformations
    glTranslatef(x, y, 0.0f);  // Move to position (x, y)
    glScalef(scaleX, scaleY, 1.0f); // Scale the Grounf
    //------------------------------------
   glColor3f(0.376f, 0.753f, 0.604f); // #60C09A
    glBegin(GL_POLYGON);
    glVertex2f(63.98f, 174.42f);  // C
    glVertex2f(116.83f, 184.5f);  // D
    glVertex2f(178.96f, 182.59f); // E
    glVertex2f(239.72f, 175.23f); // F
    glVertex2f(298.03f, 171.42f); // G
    glVertex2f(344.89f, 171.15f); // H
    glVertex2f(389.58f, 177.69f); // I
    glVertex2f(389.03f, 168.15f); // J
    glVertex2f(304.57f, 157.25f); // K
    glVertex2f(274.32f, 159.98f); // L
    glVertex2f(239.72f, 170.87f); // M
    glVertex2f(217.92f, 166.79f); // N
    glVertex2f(196.4f, 169.51f);  // O
    glVertex2f(179.42f, 177.47f); // P
    glVertex2f(158.71f, 170.57f); // Q
    glVertex2f(137.21f, 171.69f); // R
    glVertex2f(118.43f, 178.91f); // S
    glVertex2f(99.54f, 171.65f);  // T
    glVertex2f(83.20f, 167.37f);   // U
    glVertex2f(64.58f, 168.63f);   // V
    glEnd();
    //----------------------------------
    glColor3f(0.133f, 0.663f, 0.435f); // #22A96F
    glBegin(GL_POLYGON);
    glVertex2f(304.57f, 157.25f); // K
    glVertex2f(274.32f, 159.98f); // L
    glVertex2f(239.72f, 170.87f); // M
    glVertex2f(217.92f, 166.79f); // N
    glVertex2f(196.4f, 169.51f);  // O
    glVertex2f(179.42f, 177.47f); // P
    glVertex2f(158.71f, 170.57f); // Q
    glVertex2f(137.21f, 171.69f); // R
    glVertex2f(118.43f, 178.91f); // S
    glVertex2f(99.54f, 171.65f);  // T
    glVertex2f(83.20f, 167.37f);   // U
    glVertex2f(140.0f, 160.0f);   // W
    glVertex2f(148.97f, 162.39f); // Z
    glVertex2f(190.56f, 149.97f); // A1
    glVertex2f(276.33f, 149.1f);  // B1
    glEnd();
  //----------------------------------
    glColor3f(0.024f, 0.471f, 0.231f); // #06783B
    glBegin(GL_POLYGON);
    glVertex2f(64.58f, 168.63f);   // V
    glVertex2f(83.20f, 167.37f);   // U
    glVertex2f(140.0f, 160.0f);   // W
    glVertex2f(148.97f, 162.39f); // Z
    glVertex2f(190.56f, 149.97f); // A1
    glVertex2f(63.9f, 149.5f); // C1
    glEnd();
     //----------------------------------
   glColor3f(0.024f, 0.471f, 0.231f); // #06783B
    glBegin(GL_POLYGON);
    glVertex2f(276.33f, 149.1f);  // B1
    glVertex2f(304.57f, 157.25f); // K
    glVertex2f(389.03f, 168.15f); // J
    glVertex2f(389.65f, 149.33f); // E₁
    glEnd();

    glPopMatrix(); // Restore the previous transformation state
}


// Function to draw a mountain with position and size control
void drawMountain(float x, float y, float scaleX, float scaleY) {
    glPushMatrix(); // Save the current transformation state

    // Apply transformations
    glTranslatef(x, y, 0.0f);  // Move to position (x, y)
    glScalef(scaleX, scaleY, 1.0f); // Scale the mountain
    ///-----------------------------------------------------------
    /*
    glColor3f(01.0f, 0.5f, 01.3f); // Deep Green Color
    glBegin(GL_POLYGON);
    glVertex2f(131.24f, 216.8237f); // h
    glVertex2f(130.93f, 206.37f); // i
    glVertex2f(125.93f, 201.37f); // j
    glVertex2f(123.93f, 194.37f); // k
    glVertex2f(125.924f, 195.8237f); // p
    glVertex2f(140.93f, 210.37f); // o
    glVertex2f(142.93f, 210.37f); // n
    glVertex2f(142.93f, 219.37f); // m
    glVertex2f(155.24f, 237.337f); // l
    glVertex2f(150.93f, 220.37f); // q
    glVertex2f(153.24f, 213.337f); // r
    glVertex2f(170.0f, 225.0f); // s
    glVertex2f(152.0f, 185.0f); // t

    glVertex2f(161.64f, 202.31f); // u
    glVertex2f(164.05f, 219.220f); // v
    glVertex2f(157.0f, 214.0f); // w
    glVertex2f(229.16f, 198.12f); // I1
     glVertex2f(267.25f, 227.49f); // Z1
    glVertex2f(265.33f, 216.34f); // A2
    glVertex2f(260.66f, 211.45f); // B2
    glVertex2f(259.70f, 207.09f); // C2
    glVertex2f(254.01f, 204.70f); // D2
    glVertex2f(236.34f, 195.28f); // E2
    glVertex2f(272.97f, 211.6f);  // F2
    glVertex2f(276.36f, 219.15f); // G2
    glVertex2f(275.65f, 227.97f); // H2
    glVertex2f(289.15f, 245.57f); // I2
    glVertex2f(285.57f, 227.76f); // J2
    glVertex2f(288.82f, 221.54f); // K2
    glVertex2f(288.75f, 214.85f); // L2
    glVertex2f(285.64f, 216.24f); // M2
    glVertex2f(309.28f, 202.88f); // N2

    glVertex2f(202.25f, 211.57f); // J1
    glVertex2f(206.66f, 196.85f); // C3
    glVertex2f(189.86f, 181.65f); // D3
    glVertex2f(205.69f, 179.58f); // F3

    glVertex2f(277.11f, 199.19f); // G3
    glVertex2f(260.54f, 187.2f);  // H3
    glVertex2f(259.6f, 173.33f);   // I3
     glVertex2f(337.42f, 172.98f);   // J3
glVertex2f(381.04f, 176.64f); // k3

*/
//-----------------------------------------
    glColor3f(0.043f, 0.267f, 0.333f); // #0B4455
    glBegin(GL_POLYGON);
    glVertex2f(337.42f, 172.98f);   // J3
    glVertex2f(326.04f, 213.87f); // O2
    glVertex2f(381.04f, 176.64f); // k3
    glEnd();

//-----------------------------------------
    glColor3f(0.039f, 0.204f, 0.267f); // #0A3444
    glBegin(GL_POLYGON);
    glVertex2f(337.42f, 172.98f);   // J3
    glVertex2f(309.28f, 202.88f); // N2
  glVertex2f(326.04f, 213.87f); // O2
    glEnd();

//--------------------------
    glColor3f(0.043f, 0.267f, 0.333f); // #0B4455
    glBegin(GL_POLYGON);
    glVertex2f(277.11f, 199.19f); // G3
    glVertex2f(260.54f, 187.2f);  // H3
    glVertex2f(259.6f, 173.33f);   // I3
    glVertex2f(337.42f, 172.98f);   // J3
    glVertex2f(309.28f, 202.88f); // N2
    glVertex2f(285.64f, 216.24f); // M2
    glEnd();

//--------------------------

    glColor3f(0.039f, 0.204f, 0.267f); // #0A3444
    glBegin(GL_POLYGON);
    glVertex2f(277.11f, 199.19f); // G3
    glVertex2f(260.54f, 187.2f);  // H3
    glVertex2f(259.6f, 173.33f);   // I3
    glVertex2f(205.69f, 179.58f); // F3
    glVertex2f(236.34f, 195.28f); // E2
    glVertex2f(254.01f, 204.70f); // D2
    glVertex2f(259.70f, 207.09f); // C2
    glVertex2f(272.97f, 211.6f);  // F2
    glVertex2f(285.64f, 216.24f); // M2
    glEnd();

//-------------------------------

    glColor3f(0.043f, 0.267f, 0.333f); // #0B4455
    glBegin(GL_POLYGON);
    glVertex2f(202.25f, 211.57f); // J1
    glVertex2f(206.66f, 196.85f); // C3
    glVertex2f(189.86f, 181.65f); // D3
    glVertex2f(205.69f, 179.58f); // F3
    glVertex2f(236.34f, 195.28f); // E2
    glEnd();
//-----------------------------

    glColor3f(0.039f, 0.204f, 0.267f); // #0A3444
    glBegin(GL_POLYGON);
    glVertex2f(206.66f, 196.85f); // C3
    glVertex2f(189.86f, 181.65f); // D3
    glVertex2f(150.75f, 184.99f); // E3
    glVertex2f(174.3f, 195.78f);  // W1
    glVertex2f(197.890f, 209.4f); // c1
    glVertex2f(202.25f, 211.57f); // J1
    glEnd();
    //---------------
    glColor3f(0.573f, 0.875f, 0.882f); // #93DEE1
    glBegin(GL_POLYGON);
    glVertex2f(289.15f, 245.57f); // I2
    glVertex2f(285.57f, 227.76f); // J2
    glVertex2f(288.82f, 221.54f); // K2
    glVertex2f(288.75f, 214.85f); // L2
    glVertex2f(309.28f, 202.88f); // N2
    glVertex2f(326.04f, 213.87f); // O2
    glEnd();

    //---------------
    glColor3f(0.376f, 0.753f, 0.604f); // #60C09A
    glBegin(GL_POLYGON);
    glVertex2f(316.37f, 207.37f); // Q2
    glVertex2f(310.35f, 211.48f); // R2
    glVertex2f(305.63f, 220.2f);  // S2
    glVertex2f(298.15f, 223.12f); // T2
    glVertex2f(292.75f, 229.98f); // U2
    glVertex2f(295.16f, 219.01f); // V2
    glVertex2f(303.15f, 213.67f); // W2
    glVertex2f(303.94f, 210.69f); // Z2
    glVertex2f(310.69f, 203.94f); // A3
    glEnd();

    //---------------
    glColor3f(0.365f, 0.761f, 0.596f); // #5DC298
    glBegin(GL_POLYGON);
    glVertex2f(272.97f, 211.6f);  // F2
    glVertex2f(276.36f, 219.15f); // G2
    glVertex2f(275.65f, 227.97f); // H2
    glVertex2f(289.15f, 245.57f); // I2
    glVertex2f(285.57f, 227.76f); // J2
    glVertex2f(288.82f, 221.54f); // K2
    glVertex2f(288.75f, 214.85f); // L2
    glVertex2f(285.64f, 216.24f); // M2
    glEnd();
    //-------------------
    glColor3f(0.053f, 0.588f, 0.522f); // #0D9685
    glBegin(GL_POLYGON);
    glVertex2f(272.87f, 232.69f); // K1
    glVertex2f(267.25f, 227.49f); // Z1
    glVertex2f(265.33f, 216.34f); // A2
    glVertex2f(260.66f, 211.45f); // B2
    glVertex2f(259.70f, 207.09f); // C2
    glVertex2f(272.97f, 211.6f);  // F2
    glVertex2f(276.36f, 219.15f); // G2
    glVertex2f(275.65f, 227.97f); // H2
    glVertex2f(289.15f, 245.57f); // I2

    glEnd();
    //-------------------
    glColor3f(0.038f, 0.443f, 0.439f); // #097170
    glBegin(GL_POLYGON);
    glVertex2f(267.25f, 227.49f); // Z1
    glVertex2f(265.33f, 216.34f); // A2
    glVertex2f(260.66f, 211.45f); // B2
    glVertex2f(259.70f, 207.09f); // C2
    glVertex2f(254.01f, 204.70f); // D2
    glVertex2f(236.34f, 195.28f); // E2
    glVertex2f(229.16f, 198.12f); // I1
    glEnd();
    //---------------------------------
    glColor3f(0.053f, 0.588f, 0.522f); // #0D9685
    glBegin(GL_POLYGON);
    glVertex2f(226.0f, 273.50f); // z
    glVertex2f(204.88f, 244.31f); // a1
    glVertex2f(207.05f, 229.220f); // b1
    glVertex2f(197.890f, 209.4f); // c1
    glVertex2f(174.3f, 195.78f);  // W1
    glVertex2f(180.63f, 208.45f); // Vi
    glVertex2f(178.96f, 216.84f); // U1
    glVertex2f(189.58f, 224.86f); // T1
    glVertex2f(190.51f, 242.75f); // S1
    glEnd();
    //-----------------------------------------------------
    glColor3f(0.576f, 0.871f, 0.882f); // #93DEE1
    glBegin(GL_POLYGON);
    glVertex2f(226.0f, 273.50f); // z
    glVertex2f(219.66f, 247.33f); // D1
    glVertex2f(224.16f, 238.32f); // E1
    glVertex2f(224.16f, 225.98f); // F1
    glVertex2f(236.93f, 217.62f); // G1
    glVertex2f(241.75f, 207.96f); // H1
    glVertex2f(229.16f, 198.12f); // I1
    glVertex2f(272.87f, 232.69f); // K1

    glEnd();
    //----------------------------
    glColor3f(0.376f, 0.753f, 0.596f); // #60C098
    glBegin(GL_POLYGON);
    glVertex2f(253.15f, 216.73f); // L1
    glVertex2f(244.49f, 227.04f); // M1
    glVertex2f(234.89f, 233.41f); // N1
    glVertex2f(231.11f, 250.34f); // O1
    glVertex2f(237.88f, 241.44f); // P1
    glVertex2f(251.5f, 235.85f);  // Q1
    glVertex2f(259.21f, 221.76f); // R1
    glEnd();

//-----------------------------------------------------
    glColor3f(0.376f, 0.753f, 0.596f); // #60C098
    glBegin(GL_POLYGON);
    glVertex2f(197.890f, 209.4f); // c1
    glVertex2f(207.05f, 229.220f); // b1
    glVertex2f(204.88f, 244.31f); // a1
    glVertex2f(226.0f, 273.50f); // z
    glVertex2f(219.66f, 247.33f); // D1
    glVertex2f(224.16f, 238.32f); // E1
    glVertex2f(224.16f, 225.98f); // F1
    glVertex2f(236.93f, 217.62f); // G1
    glVertex2f(241.75f, 207.96f); // H1
    glVertex2f(229.16f, 198.12f); // I1
    glVertex2f(202.25f, 211.57f); // J1
    glEnd();

    //---------------------------
    glColor3f(0.038f, 0.443f, 0.439f); // #097170
    glBegin(GL_POLYGON);
    glVertex2f(152.0f, 185.0f); // t
    glVertex2f(161.64f, 202.31f); // u
    glVertex2f(164.05f, 219.220f); // v
    glVertex2f(170.0f, 225.0f); // s
    glVertex2f(190.51f, 242.75f); // S1
    glVertex2f(189.58f, 224.86f); // T1
    glVertex2f(178.96f, 216.84f); // U1
    glVertex2f(180.63f, 208.45f); // Vi
    glVertex2f(174.3f, 195.78f);  // W1
    glEnd();

    //-----------------------------------------------
    glColor3f(0.039f, 0.204f, 0.267f); // #0A3444
    glBegin(GL_POLYGON);
    glVertex2f(89.94f, 180.71f); // e
    glVertex2f(110.73f, 190.421f); // g
    glVertex2f(123.93f, 194.37f); // k
    glVertex2f(125.924f, 195.8237f); // p
    glVertex2f(140.93f, 210.37f); // o
    glVertex2f(142.93f, 210.37f); // n
    glVertex2f(153.24f, 213.337f); // r
    glVertex2f(157.0f, 214.0f); // w
    glVertex2f(164.05f, 219.220f); // v
     glVertex2f(161.64f, 202.31f); // u
    glVertex2f(152.0f, 185.0f); // t
    glEnd();

//--------------------------
    // Draw the mountain (a simple triangular shape)1
    glColor3f(0.039f, 0.204f, 0.267f); // #0A3444
    glBegin(GL_TRIANGLES);
    glVertex2f(71.340f, 176.60f); // c
    glVertex2f(103.340f, 202.040f);  // d
    glVertex2f(89.94f, 180.71f); // e
    glEnd();
//-----------------------
    glColor3f(0.043f, 0.267f, 0.333f); // #0B4455
    glBegin(GL_POLYGON);
    glVertex2f(103.340f, 202.040f);  // d
    glVertex2f(89.94f, 180.71f); // e
    glVertex2f(110.73f, 190.421f); // g
     glVertex2f(115.93f, 204.37f); // f
    glEnd();
//--------------------------
   glColor3f(0.035f, 0.400f, 0.427f); // #09666D
    glBegin(GL_POLYGON);
    glVertex2f(110.73f, 190.421f); // g
    glVertex2f(115.93f, 204.37f); // f
    glVertex2f(131.24f, 216.8237f); // h
    glVertex2f(130.93f, 206.37f); // i
    glVertex2f(125.93f, 201.37f); // j
    glVertex2f(123.93f, 194.37f); // k
    glEnd();
//-------------------------------------------------------



//---------------------------------------------------------
    glColor3f(0.035f, 0.400f, 0.427f); // #09666D
    glBegin(GL_POLYGON);
    glVertex2f(131.24f, 216.8237f); // h
    glVertex2f(155.24f, 237.337f); // l
    glVertex2f(142.93f, 210.37f); // m
    glVertex2f(142.93f, 210.37f); // n
     glVertex2f(140.93f, 210.37f); // o
     glVertex2f(125.924f, 195.8237f); // p
     glVertex2f(123.93f, 194.37f); // k
     glVertex2f(125.93f, 201.37f); // j
     glVertex2f(130.93f, 206.37f); // i
    glEnd();

//-------------------------------------------
    glColor3f(0.376f, 0.749f, 0.600f); // #60BF99
    glBegin(GL_POLYGON);
    glVertex2f(141.93f, 219.37f); // m
    glVertex2f(155.24f, 237.337f); // l
    glVertex2f(150.93f, 220.37f); // q
    glVertex2f(153.24f, 213.337f); // r
    glVertex2f(142.93f, 210.37f); // n
    glVertex2f(140.93f, 210.37f); // o
    glEnd();



//-----------------------------------------------
glColor3f(0.573f, 0.875f, 0.882f); // #92DFE1
    glBegin(GL_POLYGON);
    glVertex2f(155.24f, 237.337f); // l
    glVertex2f(150.93f, 220.37f); // q
    glVertex2f(153.24f, 213.337f); // r
    glVertex2f(157.0f, 214.0f); // w
    glVertex2f(164.05f, 219.220f); // v
    glVertex2f(170.0f, 225.0f); // s
    glEnd();
//---------------------------------------------


//-----------------------------------------
    glPopMatrix(); // Restore the previous transformation state
}
void update(int value) {
    cloudX += 0.30f;  // Move cloud to the right
    carSpeed +=0.5f;
    // Reset position if cloud goes off the right edge
    if (cloudX > 500.5f) {
        cloudX = -200.5f;
    }if (carSpeed > 500.5f) {
        carSpeed = -200.5f;
    }
    updateSnow();  // Update raindrop positions
    glutPostRedisplay();  // Request display update
    glutTimerFunc(16, update, 0);  // Call update function again after 16 ms
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
    drawCloud(0.0f, 0.0f, 1.0f);    // Normal size at (0,0)
    drawCloud(0.0f, 300.0f, 0.3f);  // Bigger cloud (1.5x scale)
    glPopMatrix();
    // Draw the road
    drawRoad();

    glPushMatrix();
    glTranslatef(carSpeed, 0.0f, 0.0f);
    drawCar(-095.10f, 10.0f, 0.3);  // Smaller
    drawCar(20.10f, 2.0f, 0.3);  // Smaller car
    glPopMatrix();



    drawMountain(-50.0f, -10.0f, 0.60f, 0.80f); // Move left and increase size
    drawMountain(90.0f, -10.0f, 0.60f, 0.80f); // Move left and increase size
    drawMountain(90.0f, -60.0f, 0.90f, 1.10f); // Move left and increase size
    drawMountain(300.0f, -10.0f, 0.60f, 0.80f); // Move left and increase size

    drawGround(-50.0f, -7.0f, 0.60f, 0.80f); // Move left and increase size
    drawGround(110.0f, -7.0f, 0.60f, 0.80f); // Move left and increase size
    drawGround(300.0f, -7.0f, 0.60f, 0.80f); // Move left and increase size

    christmasTree(420.0f, 55.0f, 0.70f, 0.70f); // Move left and increase size
    christmasTree(420.0f, 55.0f, 0.70f, 0.70f);
    christmasTree(400.0f, 55.0f, 0.70f, 0.70f);
    christmasTree(380.0f, 55.0f, 0.70f, 0.70f);
    christmasTree(360.0f, 55.0f, 0.70f, 0.70f);
    christmasTree(340.0f, 55.0f, 0.70f, 0.70f);
    christmasTree(320.0f, 55.0f, 0.70f, 0.70f);
    christmasTree(300.0f, 55.0f, 0.70f, 0.70f);
 christmasTree(420.0f, 55.0f, 0.80f, 0.80f); // Larger tree
christmasTree(400.0f, 62.0f, 0.65f, 0.65f); // Smaller tree (y +7)
christmasTree(380.0f, 55.0f, 0.75f, 0.75f); // Medium tree
christmasTree(360.0f, 55.0f, 0.90f, 0.90f); // Bigger tree
christmasTree(340.0f, 62.0f, 0.60f, 0.60f); // Smaller tree (y +7)
christmasTree(320.0f, 55.0f, 0.85f, 0.85f); // Larger tree
christmasTree(300.0f, 55.0f, 0.70f, 0.70f); // Medium tree
christmasTree(280.0f, 55.0f, 0.95f, 0.95f); // Tall tree
christmasTree(260.0f, 62.0f, 0.55f, 0.55f); // Smallest tree (y +7)
christmasTree(240.0f, 55.0f, 0.88f, 0.88f); // Large tree
christmasTree(220.0f, 55.0f, 0.72f, 0.72f); // Medium tree
christmasTree(200.0f, 62.0f, 0.60f, 0.60f); // Smaller tree (y +7)
christmasTree(200.0f, 62.0f, 0.60f, 0.60f); // Smaller tree (y +7)
christmasTree(180.0f, 55.0f, 0.95f, 0.95f); // Bigger tree
christmasTree(160.0f, 62.0f, 0.50f, 0.50f); // Small tree (y +7)
christmasTree(140.0f, 55.0f, 0.78f, 0.78f); // Medium-large tree
christmasTree(120.0f, 62.0f, 0.68f, 0.68f); // Smaller tree (y +7)
christmasTree(100.0f, 55.0f, 0.85f, 0.85f); // Tall tree
christmasTree(80.0f, 55.0f, 0.90f, 0.90f);  // Big tree
christmasTree(60.0f, 62.0f, 0.55f, 0.55f);  // Small tree (y +7)
christmasTree(40.0f, 55.0f, 0.80f, 0.80f);  // Medium tree
christmasTree(20.0f, 62.0f, 0.60f, 0.60f);  // Smallest tree (y +7)
christmasTree(0.0f, 55.0f, 1.0f, 1.0f);     // Tallest tree
christmasTree(10.0f, 62.0f, 0.55f, 0.55f);  // Small tree (y +7)
christmasTree(-10.0f, 55.0f, 0.80f, 0.80f); // Medium tree
christmasTree(-30.0f, 62.0f, 0.60f, 0.60f); // Smallest tree (y +7)
christmasTree(-50.0f, 55.0f, 1.0f, 1.0f);   // Tallest tree
christmasTree(-70.0f, 55.0f, 0.75f, 0.75f); // Medium tree
christmasTree(-90.0f, 55.0f, 0.85f, 0.85f); // Large tree
christmasTree(-110.0f, 62.0f, 0.50f, 0.50f); // Smaller tree (y +7)




    //drawTree(200.0f, 0.0f);
    if (isRaining) {// If it's raining, draw the rain
        drawSnow();
    }
    glutSwapBuffers();
}



// Function to draw a cloud using multiple circles



// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1080, 1080);
    glutCreateWindow("Cloud with Dark Blue Sky");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Black background
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(handleKeyboard);
    glutTimerFunc(16, update, 0);  // Start timer
   //k glutTimerFunc(5000, changeWeather, 0);  // Start weather change timer

    glutMainLoop();

    return 0;
}
