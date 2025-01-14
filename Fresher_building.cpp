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


//calling
// Draw building
   drawBuilding(100.0f, 100.0f, 10);  // Building 1
    drawBuilding(250.0f, 100.0f, 1);  // Building 2
    drawBuilding(400.0f, 100.0f, 1);  // Building 3

