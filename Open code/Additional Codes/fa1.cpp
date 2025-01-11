#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#define CTRL_COUNT 100

int ctrlPointsCount;
int ctrlPointsX[CTRL_COUNT], ctrlPointsY[CTRL_COUNT];
int X1[3]={20,25,20}, Y1[3]={5,24,38};
int X2[3]={30,25,30}, Y2[3]={5,24,38};
int X3[3]={22,0,18}, Y3[3]={30,38,45};
int X4[3]={28,50,32}, Y4[3]={30,38,45};
int X5[3]={18,25,32}, Y5[3]={45,60,45};

void initRendering() {
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

void myInit()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glColor3f(1.0,0.0,0.0);
    glPointSize(8.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,128.0,0.0,96.0);
}
//p(t)=(1-t)^3*p0+3t(1-t)^2*p1+3t^2(1-t)p2+t^3p3
float getNextBezierPointX(float t)
{
	float x=0.0;

	for(int i=0; i<ctrlPointsCount; i++)
	{
		int c;
		if(i==0 || i==ctrlPointsCount-1)
			c = 1;
		else
		{
			c = ctrlPointsCount-1;
		}
		x +=  c * pow(t, i) * pow(1-t, ctrlPointsCount-1-i) * ctrlPointsX[i];
	}


	return x;
}

float getNextBezierPointY(float t)
{
	float y=0.0;

	for(int i=0; i<ctrlPointsCount; i++)
	{
		int c;
		if(i==0 || i==ctrlPointsCount-1)
			c = 1;
		else
		{
			c = ctrlPointsCount-1;
		}
		y +=  c * pow(t, i) * pow(1-t, ctrlPointsCount-1-i) * ctrlPointsY[i];
	}



	return y;
}
void drawline()
{
	// draw control points using red color
	for(int i=0; i < 3; i++)
	{
		glBegin(GL_POINTS);
		glVertex2i(ctrlPointsX[i], ctrlPointsY[i]);
		glEnd();
		glFlush();
	}
	// draw bezier curve using control poitns by calculating next points using cubic bezier curve formula
	float oldX=ctrlPointsX[0], oldY=ctrlPointsY[0];
	for(double t = 0.0;t <= 1.0; t += 0.01) {

		float x = getNextBezierPointX(t);
		float y = getNextBezierPointY(t);
		glColor3f(1.0,t,1.0);
		glBegin(GL_LINES);
		glVertex2f(oldX, oldY);
		glVertex2f(x, y);
		glEnd();
		glFlush();

		oldX = x;
		oldY = y;
    }
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	ctrlPointsCount=3;
	for(int i=0;i<3;i++)
	{
		ctrlPointsX[i] = X1[i];
		ctrlPointsY[i] = Y1[i];
	}
	drawline();
	for(int i=0;i<3;i++)
	{
		ctrlPointsX[i] = X2[i];
		ctrlPointsY[i] = Y2[i];
	}
	drawline();
	//lines in the middle
	glBegin(GL_LINES);
		glVertex2f(20, 5);
		glVertex2f(30, 5);
		glEnd();

	glBegin(GL_LINES);
		glVertex2f(25, 5);
		glVertex2f(25, 30);
		glEnd();

	glBegin(GL_LINES);
		glVertex2f(25, 32);
		glVertex2f(28, 38);
		glEnd();

	glBegin(GL_LINES);
		glVertex2f(25, 32);
		glVertex2f(23, 38);
		glEnd();
	//leaves
	for(int i=0;i<3;i++)
	{
		ctrlPointsX[i] = X3[i];
		ctrlPointsY[i] = Y3[i];
	}
	drawline();

	for(int i=0;i<3;i++)
	{
		ctrlPointsX[i] = X4[i];
		ctrlPointsY[i] = Y4[i];
	}
	drawline();

	for(int i=0;i<3;i++)
	{
		ctrlPointsX[i] = X5[i];
		ctrlPointsY[i] = Y5[i];
	}
	drawline();


	glFlush();

}

void takeInput()
{
	int x, y;

	printf("How many control points do you want?\n");
	scanf("%d", &ctrlPointsCount);
	// for sine curve input points: (25,24),(35,44),(45,4),(55,24)
	printf("Enter %d points to draw bezier curve.\n", ctrlPointsCount);
	for(int i=0; i < ctrlPointsCount; i++)
	{
		printf("Enter point: ");
		scanf("%d %d", &x, &y);
		ctrlPointsX[i] = x;
		ctrlPointsY[i] = y;
	}
}

int main(int argc, char *argv[])
{
	//takeInput();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,150);
    glutCreateWindow("Bezier Curve");
    glutDisplayFunc(myDisplay);
    myInit();
    //glutReshapeFunc(handleResize);
    glutMainLoop();
    return 0;
}

