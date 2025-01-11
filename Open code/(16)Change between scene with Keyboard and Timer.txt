#include <windows.h>  // for MS Windows
#include <GL/glut.h>
void triangle();  // GLUT, include glu.h and gl.h
void display1(int a)
{
    glutDisplayFunc(triangle);
    glutPostRedisplay();
}
void rectangle()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f); // Red
	glVertex2f(0.0f, 0.0f);    // x, y
    glVertex2f(2.0f, 0.0f);
    glVertex2f(2.0f, 3.0f);
    glVertex2f(0.0f, 3.0f);
	glEnd();
	glFlush();
	glutTimerFunc(500,display1,0);
}

void triangle()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f); // Red
	glVertex2f(5.0f, 0.0f);    // x, y
    glVertex2f(8.0f, 0.0f);
    glVertex2f(5.0f, 3.0f);
    //glVertex2f(0.0f, 3.0f);
	glEnd();
	glFlush();
}
/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
	 // Set background color to black and opaque
	//         // Clear the color buffer (background)

	rectangle();
	//triangle();
	// Draw a Red 1x1 Square centered at origin
	  // Render now
}

void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
case 'a':
    glutDisplayFunc(rectangle);
    glutPostRedisplay();
    break;
case 'w':
    glutDisplayFunc(triangle);
    glutPostRedisplay();
    break;
	}}
/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
	glutInitWindowSize(320, 320);   // Set the window's initial width & height
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutKeyboardFunc(handleKeypress);
	gluOrtho2D(-10,10,-10,10);
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}

