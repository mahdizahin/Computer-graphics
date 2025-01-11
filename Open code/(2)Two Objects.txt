#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
float _move = 0.0f;
float _move1 = 0.0f;
void object1()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_move, 0.0f, 0.0f);
    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f); // Red
	glVertex2f(0.0f,0.0f);
	glVertex2f(1.0f,0.0f);
	glVertex2f(1.0f,1.0f);
	glVertex2f(0.0f,1.0f);  // x, y
	glEnd();
	glPopMatrix();
}

void object2()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_move1, 0.0f, 0.0f);
    glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 1.0f, 0.0f); // Red
	glVertex2f(0.0f,0.0f);
	glVertex2f(1.0f,0.0f);
	glVertex2f(1.0f,-1.0f);
	glVertex2f(0.0f,-1.0f);  // x, y
	glEnd();
	glPopMatrix();
}
/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	object1();
	object2();
	glutSwapBuffers();
	glFlush();

	//glutSwapBuffers(); // Render now
}

void update(int value) {
 _move += .02;
 if(_move > 2.5)
{
_move = -3.0;
}
glutPostRedisplay();
glutTimerFunc(20, update, 0);
}

void update1(int value) {
 _move1 -= .02;
 if(_move1 < -2.5)
{
_move1 = 3.0;
}
glutPostRedisplay();
glutTimerFunc(20, update1, 0);
}
/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
	glutInitWindowSize(320, 320);
	gluOrtho2D(-3,3,-3,3);  // Set the window's initial width & height
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutTimerFunc(20, update, 0);
	glutTimerFunc(20, update1, 0);
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
