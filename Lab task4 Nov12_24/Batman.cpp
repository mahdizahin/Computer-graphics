#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <math.h>

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	glLineWidth(7.5);





	//rewrger 1
	glBegin(GL_POLYGON); // Draw an ellipse (wider than tall)
	for (int i = 0; i < 200; i++) {
		glColor3f(1.0f, 1.5f, 1.0f); // Orange color for the ellipse
		float pi = 3.1416;
		float A = (i * 2 * pi) / 200;
		float r = 0.55;
		float x = r * (cos(A) * 1.2)+0.6; // Scale x to make it wider
		float y = r * sin(A)-0.6;       // Keep y the same for height
		glVertex2f(x, y);
	}

	glEnd();
	//right 2
	glBegin(GL_POLYGON); // Draw an ellipse (wider than tall)
	for (int i = 0; i < 200; i++) {
		glColor3f(1.0f, 1.5f, 1.0f); // Orange color for the ellipse
		float pi = 3.1416;
		float A = (i * 2 * pi) / 200;
		float r = 0.55;
		float x = r * (cos(A) * 1.2)-0.6; // Scale x to make it wider
		float y = r * sin(A)-0.6;       // Keep y the same for height
		glVertex2f(x, y);
	}

	glEnd();

	//right 3
	glBegin(GL_POLYGON); // Draw an ellipse (wider than tall)
	for (int i = 0; i < 200; i++) {
		glColor3f(1.0f, 1.5f, 1.0f); // Orange color for the ellipse
		float pi = 3.1416;
		float A = (i * 2 * pi) / 200;
		float r = 0.55;
		float x = r * (cos(A) * 1.9)-1.5; // Scale x to make it wider
		float y = r * sin(A);       // Keep y the same for height
		glVertex2f(x, y);
	}

	glEnd();

	//left 4
	glBegin(GL_POLYGON); // Draw an ellipse (wider than tall)
	for (int i = 0; i < 200; i++) {
		glColor3f(1.0f, 1.5f, 1.0f); // Orange color for the ellipse
		float pi = 3.1416;
		float A = (i * 2 * pi) / 200;
		float r = 0.55;
		float x = r * (cos(A) * 1.9)+1.5; // Scale x to make it wider
		float y = r * sin(A);       // Keep y the same for height
		glVertex2f(x, y);
	}

	glEnd();


	//dsfd

	glBegin(GL_POLYGON); // Draw a rectangle
        glVertex2f(-2.1f, 0.2f); // Bottom-left corner
        glVertex2f(2.5f, 0.2f);  // Bottom-right corner
        glVertex2f(0.5f, 1.9f);   // Top-right corner
        glVertex2f(-0.5f, 1.9f);  // Top-left corner
    glEnd();

 glColor3f(1.0f, 1.5f, 1.0f); // Orange color for the ellipse
   glBegin(GL_POLYGON); // Draw a rectangle
    glVertex2f(-0.1f, -1.50f); // Bottom-left corner (moved lower by subtracting 0.7)
    glVertex2f(0.4f, -1.0f);  // Bottom-right corner (moved lower by subtracting 0.7)
    glVertex2f(0.55f, -.67f);   // Top-right corner (moved lower by subtractingmzmz 0.7)
    glVertex2f(-0.55f, -.66f);  // Top-left corner (moved lower by subtracting-mz 0.7)
glEnd();
	/*/below
	glBegin(GL_POLYGON); // Draw a circle
	for (int i = 0; i < 200; i++) {
		glColor3f(1.0, 1.0, 1.0); // White color for the circle
		float pi = 3.1416;
		float A = (i * 2 * pi) / 200;
		float r = 0.55;
		float x = r * cos(A);
		float y = r * sin(A) - 0.3; // Subtract 0.3 to move the circle downward
		glVertex2f(x, y);
	}

	glEnd();
	*/

	//5
	glColor3f(1.0f, 1.5f, 1.0f); // Orange color for the ellipse

    glBegin(GL_POLYGON); // Draw a vertical ellipse
    for (int i = 0; i < 200; i++) {
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;  // Angle in radians
        float r = 0.1;                // Base radius
        float x = r * (cos(A) * .4)-.07;   // Scale x down (make it narrower)
        float y = r * (sin(A) * 1.9)+.25;   // Scale y up (make it taller)
        glVertex2f(x, y);
    }
    glEnd();
//6
	glColor3f(1.0f, 1.5f, 1.0f); // Orange color for the ellipse

    glBegin(GL_POLYGON); // Draw a vertical ellipse
    for (int i = 0; i < 200; i++) {
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;  // Angle in radians
        float r = 0.1;                // Base radius
        float x = r * (cos(A) * .4)+.07;   // Scale x down (make it narrower)
        float y = r * (sin(A) * 1.9)+.25;   // Scale y up (make it taller)
        glVertex2f(x, y);
    }
    glEnd();
   //7
    glColor3f(1.0f, 1.5f, 1.0f); // Orange color for the ellipse

    glBegin(GL_POLYGON); // Draw a vertical ellipse
    for (int i = 0; i < 200; i++) {
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;  // Angle in radians
        float r = 0.1;                // Base radius
        float x = r * (cos(A) * .4);   // Scale x down (make it narrower)
        float y = r * (sin(A) * 1)+.25;   // Scale y up (make it taller)
        glVertex2f(x, y);
    }
    glEnd();


	glFlush(); // Render now
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
             // Initialize GLUT
	glutCreateWindow("Move Circle to Left"); // Create a window with the given title
	glutInitWindowSize(1000, 600);          // Set the window's initial width & height
	glutDisplayFunc(display);              // Register display callback handler for window re-paint
	glutMainLoop();                        // Enter the event-processing loop
	return 0;
}
