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

float m_laneMarkerWidth = 20.0f; // Width of each lane marker
float m_laneMarkerGap = 15.0f;  // Gap between lane markers
float m_laneMarkerY = 75.0f;   // Y position of the lane markers (center of the road)

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
void m_changeWeather() {
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




void drawSky() {
    glBegin(GL_QUADS);

    // Top part of the sky (interpolating from dark blue to grayish)
    float topR = 0.105f - (0.05f * skyColorFactor);  // From dark blue (0.05) to black (0.0)
    float topG = 0.105f - (0.05f * skyColorFactor);  // From dark blue (0.05) to black (0.0)
    float topB = 0.42f - (0.2f * skyColorFactor);    // From dark blue (0.2) to black (0.0)


    glColor3f(topR, topG, topB);  // Set the top part color
    glVertex2f(0.0f, 500.0f);     // Top-left corner
    glVertex2f(500.0f, 500.0f);   // Top-right corner

    // Bottom part of the sky (interpolating from light blue to grayish)
   float bottomR = 0.1f - (0.1f * skyColorFactor);  // From dark blue (0.1) to black (0.0)
    float bottomG = 0.15f - (0.15f * skyColorFactor); // From dark blue (0.15) to black (0.0)
    float bottomB = 0.3f - (0.3f * skyColorFactor);  // From dark blue (0.3) to black (0.0)

    glColor3f(bottomR, bottomG, bottomB);  // Set the bottom part color
    glVertex2f(500.0f, 0.0f);      // Bottom-right corner
    glVertex2f(0.0f, 0.0f);        // Bottom-left corner
    glEnd();
}



void drawSun() {
   glColor3f(0.988f, 0.910f, 0.572f);  // Light morning sun (soft warm yellow)


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



void handleKeyboard(unsigned char key, int x, int y) {
    if (key == '1') {
        currentWeather = CLEAR;
    } else if (key == '2') {
        currentWeather = OVERCAST;
    } else if (key == '3') {
        currentWeather = RAIN;
    }
    m_changeWeather();
}

void m_drawCloud(float offsetX, float offsetY, float scale) {
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




 void m_drawCar(float x, float y, float scale) {
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


void m_drawRoad() {
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
    for (float x = 0.0f; x < 500.0f; x += m_laneMarkerWidth + m_laneMarkerGap) {
        glBegin(GL_QUADS);
        glVertex2f(x, m_laneMarkerY - 1.0f);
        glVertex2f(x + m_laneMarkerWidth, m_laneMarkerY - 1.0f);
        glVertex2f(x + m_laneMarkerWidth, m_laneMarkerY + 1.0f);
        glVertex2f(x, m_laneMarkerY + 1.0f);
        glEnd();
    }
}

void m_drawAirplane(float x, float y, float scaleX, float scaleY) {
    glPushMatrix(); // Save the current transformation state
    // Apply transformations
    glTranslatef(x, y, 0.0f);  // Move to position (x, y)
    glScalef(scaleX, scaleY, 1.0f); // Scale the Grounf

    glColor3f(0.129f, 0.549f, 0.714f); // #218CB6
    glBegin(GL_POLYGON);
    glVertex2f(71.31f, 370.42f); // C
    glVertex2f(187.63f, 370.68f); // D
    glVertex2f(187.12f, 366.64f); // E
    glVertex2f(184.04f, 364.21f); // F
    glVertex2f(178.09f, 362.03f); // G
    glVertex2f(173.93f, 361.23f); // H
    glVertex2f(156.09f, 360.44f); // I
    glVertex2f(124.56f, 360.44f); // J
    glVertex2f(90.0f, 360.0f);    // K
    glVertex2f(81.74f, 362.62f);  // L
    glVertex2f(74.6f, 366.39f);   // M
    glEnd();

    glColor3f(0.686f, 0.816f, 0.843f); // #AFD0D7
    glBegin(GL_POLYGON);
    glVertex2f(71.31f, 370.42f); // C
    glVertex2f(187.63f, 370.68f); // D
    glVertex2f(182.86f, 376.34f); // O
    glVertex2f(175.73f, 381.23f); // P
    glVertex2f(167.92f, 384.21f); // Q
    glVertex2f(163.08f, 385.7f);  // R
    glVertex2f(140.21f, 386.07f); // S
    glVertex2f(78.29f, 386.44f);  // T
    glVertex2f(59.51f, 403.55f);  // U
    glVertex2f(49.09f, 403.0f);   // V
    glVertex2f(64.15f, 377.51f);  // W
    glVertex2f(66.76f, 374.17f);  // Z
    glEnd();

    glColor3f(0.592f, 0.592f, 0.698f); // #9797B2
    glBegin(GL_POLYGON);
    glVertex2f(124.56f, 360.44f); // J
    glVertex2f(108.44f, 360.47f); // A1
    glVertex2f(103.72f, 352.30f); // B1
    glVertex2f(112.74f, 352.19f); // C1
    glEnd();

    glColor3f(0.592f, 0.592f, 0.698f); // #9797B2
    glBegin(GL_POLYGON);
    glVertex2f(109.34f, 386.55f); // D1
    glVertex2f(101.47f, 399.29f); // E1
    glVertex2f(108.25f, 399.7f);  // F1
    glVertex2f(123.16f, 386.0f); // G1
    glEnd();


    glColor3f(0.592f, 0.592f, 0.698f); // #9797B2
    glBegin(GL_POLYGON);
    glVertex2f(63.77f, 378.31f);  // G1
    glVertex2f(68.46f, 372.45f);  // H1
    glVertex2f(64.22f, 369.00f);  // I1
    glVertex2f(57.74f, 369.25f);  // J1
    glEnd();

    glColor3f(0.176f, 0.184f, 0.373f); // #2D2F5F
    glBegin(GL_POLYGON);
    glVertex2f(173.95f, 382.14f); // K1
    glVertex2f(177.62f, 380.21f); // L1
    glVertex2f(180.79f, 377.91f); // M1
    glVertex2f(185.64f, 374.12f); // N1
    glVertex2f(170.53f, 373.81f); // O1
    glVertex2f(168.35f, 374.99f); // P1
    glVertex2f(166.99f, 376.55f); // Q1
    glVertex2f(166.3f, 378.29f);  // R1
    glVertex2f(166.11f, 380.03f); // S1
    glVertex2f(167.11f, 381.71f); // T1
    glVertex2f(168.54f, 382.33f); // U1
    glEnd();

    glPopMatrix(); // Restore the previous transformation state
}

// Function to draw a Ground with position and size control
void m_building(float x, float y, float scaleX, float scaleY) {
    glPushMatrix(); // Save the current transformation state
    // Apply transformations
    glTranslatef(x, y, 0.0f);  // Move to position (x, y)
    glScalef(scaleX, scaleY, 1.0f); // Scale the Grounf

    glColor3f(0.918f, 0.796f, 0.474f);  // Warm morning sun (golden yellow)
    glBegin(GL_POLYGON);
    glVertex2f(148.39f, 39.15f);  // C
    glVertex2f(147.81f, 169.45f); // D
    glVertex2f(194.15f, 169.58f); // E
    glVertex2f(194.73f, 39.82f);  // F
    glEnd();

    glColor3f(0.612f, 0.529f, 0.373f);  // Muted morning sun (warm earthy tone)
    glBegin(GL_POLYGON);
    glVertex2f(146.36f, 169.67f); // G
    glVertex2f(195.42f, 169.16f); // H
    glVertex2f(195.42f, 166.3f);  // J
    glVertex2f(146.45f, 166.38f); // I
    glEnd();

    glColor3f(0.612f, 0.529f, 0.373f);  // Muted morning sun (warm earthy tone)
    glBegin(GL_POLYGON);
    glVertex2f(146.45f, 138.36f); // K
    glVertex2f(195.42f, 138.61f); // L
    glVertex2f(195.0f, 135.0f);   // N
    glVertex2f(146.36f, 135.25f); // M
    glEnd();

    glColor3f(0.612f, 0.529f, 0.373f);  // Muted morning sun (warm earthy tone)
    glBegin(GL_POLYGON);
    glVertex2f(146.61f, 107.31f); // O
    glVertex2f(195.51f, 107.39f); // P
    glVertex2f(195.59f, 104.2f);  // R
    glVertex2f(146.53f, 104.11f); // Q
    glEnd();

    glColor3f(0.612f, 0.529f, 0.373f);  // Muted morning sun (warm earthy tone)
    glBegin(GL_POLYGON);
    glVertex2f(146.33f, 76.14f);  // S
    glVertex2f(195.59f, 76.26f);  // T
    glVertex2f(195.71f, 72.83f);  // V
    glVertex2f(146.57f, 72.95f);  // U
    glEnd();

    glColor3f(0.612f, 0.529f, 0.373f);  // Muted morning sun (warm earthy tone)
    glBegin(GL_POLYGON);
    glVertex2f(146.33f, 45.26f);  // W
    glVertex2f(195.59f, 44.77f);   // Z
    glVertex2f(194.73f, 39.82f);  // F
    glVertex2f(146.33f, 39.01f);   // A1
    glEnd();

    glColor3f(0.541f, 0.820f, 0.898f);  // Light blue-cyan tone
    glBegin(GL_POLYGON);
    glVertex2f(157.17f, 69.44f);  // B1
    glVertex2f(184.89f, 69.7f);    // K1
    glVertex2f(185.02f, 48.3f);    // P1
    glVertex2f(157.82f, 47.91f);   // A2
    glEnd();

    glColor3f(0.541f, 0.820f, 0.898f);  // Light blue-cyan tone
    glBegin(GL_POLYGON);
    glVertex2f(156.95f, 132.02f); // B2
    glVertex2f(184.92f, 131.67f); // C2
    glVertex2f(184.4f, 110.74f);  // D2
    glVertex2f(157.47f, 109.88f); // E2
    glEnd();

    glColor3f(0.541f, 0.820f, 0.898f);  // Light blue-cyan tone
    glBegin(GL_POLYGON);
    glVertex2f(157.29f, 100.45f); // F2
    glVertex2f(184.57f, 100.1f);  // G2
    glVertex2f(184.4f, 79.35f);   // H2
    glVertex2f(157.81f, 79.0f);   // I2
    glEnd();

    glColor3f(0.541f, 0.820f, 0.898f);  // Light blue-cyan tone
    glBegin(GL_POLYGON);
    glVertex2f(157.98f, 162.55f); // J2
    glVertex2f(184.74f, 162.55f); // K2
    glVertex2f(184.92f, 141.28f); // L2
    glVertex2f(157.47f, 140.94f); // M2
    glEnd();
    glPopMatrix(); // Restore the previous transformation state
}


// Function to draw a Ground with position and size control
void m_christmasTree(float x, float y, float scaleX, float scaleY) {
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
void m_drawGround(float x, float y, float scaleX, float scaleY) {
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
void m_drawMountain(float x, float y, float scaleX, float scaleY) {
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
    m_drawCloud(0.0f, 0.0f, 1.0f);    // Normal size at (0,0)
    m_drawCloud(0.0f, 300.0f, 0.3f);  // Bigger cloud (1.5x scale)
    glPopMatrix();
    // Draw the road
    m_drawRoad();

    glPushMatrix();
    glTranslatef(carSpeed, 0.0f, 0.0f);
    m_drawCar(-095.10f, 10.0f, 0.3);  // Smaller
    m_drawCar(20.10f, 2.0f, 0.3);  // Smaller car

     m_drawAirplane (0.0f, 40.0f, 0.50f, 0.50f); // Move left and increase size
     m_drawAirplane (-300.0f, 140.0f, 0.50f, 0.50f); // Move left and increase size

    glPopMatrix();



    m_drawMountain(-50.0f, -10.0f, 0.60f, 0.80f); // Move left and increase size
    m_drawMountain(90.0f, -10.0f, 0.60f, 0.80f); // Move left and increase size
    m_drawMountain(90.0f, -60.0f, 0.90f, 1.10f); // Move left and increase size
    m_drawMountain(300.0f, -10.0f, 0.60f, 0.80f); // Move left and increase size

    m_drawGround(-50.0f, -7.0f, 0.60f, 0.80f); // Move left and increase size
    m_drawGround(110.0f, -7.0f, 0.60f, 0.80f); // Move left and increase size
    m_drawGround(300.0f, -7.0f, 0.60f, 0.80f); // Move left and increase size
    m_drawGround(-50.0f, -20.0f, 0.60f, 0.80f); // Move left and increase size
    m_drawGround(110.0f, -20.0f, 0.60f, 0.80f); // Move left and increase size
    m_drawGround(300.0f, -20.0f, 0.60f, 0.80f); // Move left and increase size
    m_drawGround(-50.0f, -90.0f, 0.60f, 0.80f); // Move left and increase size
    m_drawGround(110.0f, -90.0f, 0.60f, 0.80f); // Move left and increase size
    m_drawGround(300.0f, -90.0f, 0.60f, 0.80f); // Move left and increase size
    m_drawGround(-50.0f, -110.0f, 0.60f, 0.80f); // Move left and increase size
    m_drawGround(110.0f, -110.0f, 0.60f, 0.80f); // Move left and increase size
    m_drawGround(300.0f, -110.0f, 0.60f, 0.80f); // Move left and increase size
    m_drawGround(-50.0f, -130.0f, 0.60f, 0.80f); // Move left and increase size
    m_drawGround(110.0f, -130.0f, 0.60f, 0.80f); // Move left and increase size
    m_drawGround(300.0f, -130.0f, 0.60f, 0.80f); // Move left and increase size


    m_christmasTree(420.0f, 55.0f, 0.70f, 0.70f); // Move left and increase size
    m_christmasTree(420.0f, 55.0f, 0.70f, 0.70f);
    m_christmasTree(400.0f, 55.0f, 0.70f, 0.70f);
    m_christmasTree(380.0f, 55.0f, 0.70f, 0.70f);
    m_christmasTree(360.0f, 55.0f, 0.70f, 0.70f);
    m_christmasTree(340.0f, 55.0f, 0.70f, 0.70f);
    m_christmasTree(320.0f, 55.0f, 0.70f, 0.70f);
    m_christmasTree(300.0f, 55.0f, 0.70f, 0.70f);
    m_christmasTree(420.0f, 55.0f, 0.80f, 0.80f); // Larger tree
    m_christmasTree(400.0f, 62.0f, 0.65f, 0.65f); // Smaller tree (y +7)
    m_christmasTree(380.0f, 55.0f, 0.75f, 0.75f); // Medium tree
    m_christmasTree(360.0f, 55.0f, 0.90f, 0.90f); // Bigger tree
    m_christmasTree(340.0f, 62.0f, 0.60f, 0.60f); // Smaller tree (y +7)
    m_christmasTree(320.0f, 55.0f, 0.85f, 0.85f); // Larger tree
    m_christmasTree(300.0f, 55.0f, 0.70f, 0.70f); // Medium tree
    m_christmasTree(280.0f, 55.0f, 0.95f, 0.95f); // Tall tree
    m_christmasTree(260.0f, 62.0f, 0.55f, 0.55f); // Smallest tree (y +7)
    m_christmasTree(240.0f, 55.0f, 0.88f, 0.88f); // Large tree
    m_christmasTree(220.0f, 55.0f, 0.72f, 0.72f); // Medium tree
    m_christmasTree(200.0f, 62.0f, 0.60f, 0.60f); // Smaller tree (y +7)
    m_christmasTree(200.0f, 62.0f, 0.60f, 0.60f); // Smaller tree (y +7)
    m_christmasTree(180.0f, 55.0f, 0.95f, 0.95f); // Bigger tree
    m_christmasTree(160.0f, 62.0f, 0.50f, 0.50f); // Small tree (y +7)
    m_christmasTree(140.0f, 55.0f, 0.78f, 0.78f); // Medium-large tree
    m_christmasTree(120.0f, 62.0f, 0.68f, 0.68f); // Smaller tree (y +7)
    m_christmasTree(100.0f, 55.0f, 0.85f, 0.85f); // Tall tree
    m_christmasTree(80.0f, 55.0f, 0.90f, 0.90f);  // Big tree
    m_christmasTree(60.0f, 62.0f, 0.55f, 0.55f);  // Small tree (y +7)
    m_christmasTree(40.0f, 55.0f, 0.80f, 0.80f);  // Medium tree
    m_christmasTree(20.0f, 62.0f, 0.60f, 0.60f);  // Smallest tree (y +7)
    m_christmasTree(0.0f, 55.0f, 1.0f, 1.0f);     // Tallest tree
    m_christmasTree(10.0f, 62.0f, 0.55f, 0.55f);  // Small tree (y +7)
    m_christmasTree(-10.0f, 55.0f, 0.80f, 0.80f); // Medium tree
    m_christmasTree(-30.0f, 62.0f, 0.60f, 0.60f); // Smallest tree (y +7)
    m_christmasTree(-50.0f, 55.0f, 1.0f, 1.0f);   // Tallest tree
    m_christmasTree(-70.0f, 55.0f, 0.75f, 0.75f); // Medium tree
    m_christmasTree(-90.0f, 55.0f, 0.85f, 0.85f); // Large tree
    m_christmasTree(-110.0f, 62.0f, 0.50f, 0.50f); // Smaller tree (y +7)



     m_building(-10.0f, -10.0f, 0.50f, 0.50f); //small
     m_building(20.0f, -10.0f, 0.50f, 0.50f); //small
     m_building(50.0f, -10.0f, 0.50f, 0.50f); //small
     m_building(400.0f, -10.0f, 0.50f, 0.50f); //small
     m_building(110.0f, -10.0f, 0.50f, 0.50f); //small
     m_building(140.0f, -10.0f, 0.50f, 0.50f); //small
     m_building(170.0f, -10.0f, 0.50f, 0.50f); //small
     m_building(200.0f, 0.0f, 0.60f, 0.60f); // Smal
     m_building(-10.0f, 90.0f, 0.50f, 0.50f); //small
     m_building(20.0f, 90.0f, 0.50f, 0.50f); //small
     m_building(50.0f, 90.0f, 0.50f, 0.50f); //small
     m_building(400.0f, 90.0f, 0.50f, 0.50f); //small
     m_building(110.0f, 80.0f, 0.50f, 0.50f); //small
     m_building(140.0f, 80.0f, 0.50f, 0.50f); //small
     m_building(170.0f, 90.0f, 0.50f, 0.50f); //small
     m_building(200.0f, 90.0f, 0.60f, 0.60f); // Smal

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
