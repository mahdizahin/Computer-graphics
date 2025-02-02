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
