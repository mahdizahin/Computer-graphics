
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
