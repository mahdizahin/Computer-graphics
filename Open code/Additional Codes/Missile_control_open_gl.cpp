#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <GL/glut.h>


#pragma region



float posX = 0, posY = 0, posZ = 0;
float missileStartPosY = 0;

int x1 = 0;
int x2 = 0;
int y1 = 0;
int y2 = 100;

//plane Left collision points
int planeLeftX = 0;
int planeLeftY = 0;

int planeLeftBodyX = 0;
int planeLeftBodyY = 0;

int planeLeftWingUp1X = 0;
int planeLeftWingUp1Y = 0;

int planeLeftWingUp2X = 0;
int planeLeftWingUp2Y = 0;

int planeLeftWingDown1X = 0;
int planeLeftWingDown1Y = 0;

int planeLeftWingDown2X = 0;
int planeLeftWingDown2Y = 0;

//plane Left collision points

int planeRightX = 0;
int planeRightY = 0;

int planeRightBodyX = 0;
int planeRightBodyY = 0;

int planeRightWingUp1X = 0;
int planeRightWingUp1Y = 0;

int planeRightWingUp2X = 0;
int planeRightWingUp2Y = 0;

int planeRightWingDown1X = 0;
int planeRightWingDown1Y = 0;

int planeRightWingDown2X = 0;
int planeRightWingDown2Y = 0;


int missileLeftX = 0;
int missileLeftY = 0;


int missileRightX = 0;
int missileRightY = 0;

float move_unit = 15;

#pragma endregion Varriables

int colCountL = 0;
int colCountR = 0;


void keyboardown(int key, int x, int y)
{
	switch (key){
		//case GLUT_KEY_RIGHT:

		//	posX += move_unit;
		//	//	missilePosX += move_unit;
		//	break;

		//case GLUT_KEY_LEFT:
		//	posX -= move_unit;
		//	break;

	case GLUT_KEY_UP:
		y1 -= move_unit;
		glutPostRedisplay();

		break;

	case GLUT_KEY_DOWN:
		y1 += move_unit;
		glutPostRedisplay();
		break;

	default:
		break;


	}

}

void myMouse(int b, int s, int x, int y) {      // mouse click callback
	if (s == GLUT_DOWN) {


		if (b == GLUT_LEFT_BUTTON) {


			y2 += move_unit;
			glutPostRedisplay();
		}

		else if (b == GLUT_RIGHT_BUTTON){

			y2 -= move_unit;

		}
	}
}

float mouseChange = 3.5;

int  tempY = 0;

int planePos = 500;

void myMouseMove(int x, int y)
{


	if (tempY > y && tempY >= 0 && tempY <= 700)
	{
		//printf("%d \n", planePos);
		y2 -= mouseChange;
		planePos = planePos - mouseChange;
	}

	else if (tempY < y && tempY >= 0 && tempY <= 700)
	{
		y2 += mouseChange;
		//printf("\t \t %d \n", planePos);
		planePos = planePos + mouseChange;
	}

	tempY = y;

	glutPostRedisplay();
}


void drawHealthBarLeft(int x, float r ,float g ,float b)
{

	if (colCountL == 0)
	{


		glBegin(GL_QUADS);
		glColor3f(0 + r, .5 + g, 0 + b);
		glVertex2f(20, 25);
		glVertex2f(330 - x, 25);
		glVertex2f(330 - x, 45);
		glVertex2f(20, 45);
		glEnd();


	}



	else if (colCountL == 1)
	{
		//yellow
		glBegin(GL_QUADS);
		glColor3f(1, 1, 0);
		glVertex2f(20, 25);
		glVertex2f(225, 25);
		glVertex2f(225, 45);
		glVertex2f(20, 45);
		glEnd();
	}
		else if (colCountL == 2)
		{
			glBegin(GL_QUADS);
			glColor3f(1, 0, 0);
			glVertex2f(20, 25);
			glVertex2f(95, 25);
			glVertex2f(95, 45);
			glVertex2f(20, 45);
			glEnd();
		}






}


void drawHealthBarRight()
{
	if (colCountR == 0)
	{	//green
		glBegin(GL_QUADS);
		glColor3f(0, .5, 0);
		glVertex2f(550, 25);
		glVertex2f(860, 25);
		glVertex2f(860, 45);
		glVertex2f(550, 45);
		glEnd();
	}

	else if (colCountR == 1)
	{
		//yellow
		glBegin(GL_QUADS);
		glColor3f(1, 1, 0);
		glVertex2f(660, 25);
		glVertex2f(860, 25);
		glVertex2f(860, 45);
		glVertex2f(660, 45);
		glEnd();
	}


	else if (colCountR ==2)
	{
	//red
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glVertex2f( 790,  25);
	glVertex2f( 860,  25);
	glVertex2f( 860,  45);
	glVertex2f( 790,  45);
	glEnd();
	}

}



void drawPlaneLeft(int planeX, int planeY)
{
	//collision
	planeLeftX = planeX + 120;
	planeLeftY = planeY + 450;

	planeLeftBodyX = planeX + 90;
	planeLeftBodyY = planeY + 450;

	planeLeftWingUp1X = planeX + 72;
	planeLeftWingUp1Y = planeY + 437;

	planeLeftWingUp2X = planeX + 57;
	planeLeftWingUp2Y = planeY + 422;

	planeLeftWingDown1X = planeX + 72;
	planeLeftWingDown1Y = planeY + 462;

	planeLeftWingDown2X = planeX + 57;
	planeLeftWingDown2Y = planeY + 477;



	//printf("%d %d\n", planeLeftX, planeLeftY);
	//drawing plane
	//plane head
	glBegin(GL_TRIANGLES);
	glColor3f(.8, .4, .1);
	glVertex2f(planeX + 700 - 580, planeY + 450);
	glVertex2f(planeX + 700 - 595, planeY + 445);
	glVertex2f(planeX + 700 - 595, planeY + 455);
	glEnd();
	//body
	glColor3f(1, 0, 0);
	glBegin(GL_QUADS);
	glVertex2f(planeX + 700 - 595, planeY + 445);
	glVertex2f(planeX + 700 - 595, planeY + 455);
	glVertex2f(planeX + 700 - 673, planeY + 455);
	glVertex2f(planeX + 700 - 673, planeY + 445);
	glEnd();
	//up wing
	glColor3f(.5, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(planeX + 700 - 625, planeY + 445);
	glVertex2f(planeX + 700 - 625, planeY + 440);
	glVertex2f(planeX + 700 - 655, planeY + 410);
	glVertex2f(planeX + 700 - 665, planeY + 410);
	glVertex2f(planeX + 700 - 650, planeY + 440);
	glVertex2f(planeX + 700 - 650, planeY + 445);
	glEnd();
	//down wing
	glColor3f(.5, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(planeX + 700 - 625, planeY + 900 - 445);
	glVertex2f(planeX + 700 - 625, planeY + 900 - 440);
	glVertex2f(planeX + 700 - 655, planeY + 900 - 410);
	glVertex2f(planeX + 700 - 665, planeY + 900 - 410);
	glVertex2f(planeX + 700 - 650, planeY + 900 - 440);
	glVertex2f(planeX + 700 - 650, planeY + 900 - 445);
	glEnd();
	//tail
	glColor3f(0, 1, .2);
	glBegin(GL_POLYGON);
	glVertex2f(planeX + 700 - 673, planeY + 455);
	glVertex2f(planeX + 700 - 673, planeY + 445);
	glVertex2f(planeX + 700 - 690, planeY + 430);
	glVertex2f(planeX + 700 - 680, planeY + 450);
	glVertex2f(planeX + 700 - 690, planeY + 470);
	glEnd();

}
void drawPlaneRight(int planeX, int planeY)
{
	//check plane collision
	planeRightX = planeX + 120;
	planeRightY = planeY + 450;

	planeRightBodyX = planeX + 90;
	planeRightBodyY = planeY + 450;

	planeRightWingUp1X = planeX + 72;
	planeRightWingUp1Y = planeY + 437;

	planeRightWingUp2X = planeX + 57;
	planeRightWingUp2Y = planeY + 422;

	planeRightWingDown1X = planeX + 72;
	planeRightWingDown1Y = planeY + 462;

	planeRightWingDown2X = planeX + 57;
	planeRightWingDown2Y = planeY + 477;


	// draw plane

	//plane head
	glBegin(GL_TRIANGLES);
	glColor3f(.9, .1, .8);
	glVertex2f(planeX + 200 + 580, planeY + 900 - 450);
	glVertex2f(planeX + 200 + 595, planeY + 900 - 445);
	glVertex2f(planeX + 200 + 595, planeY + 900 - 455);
	glEnd();
	//body
	glBegin(GL_QUADS);
	glColor3f(.2, .8, .9);
	glVertex2f(planeX + 200 + 595, planeY + 900 - 445);
	glVertex2f(planeX + 200 + 595, planeY + 900 - 455);
	glVertex2f(planeX + 200 + 673, planeY + 900 - 455);
	glVertex2f(planeX + 200 + 673, planeY + 900 - 445);
	glEnd();
	//down wing
	glBegin(GL_POLYGON);
	glColor3f(.5, .1, .5);
	glVertex2f(planeX + 200 + 625, planeY + 900 - 445);
	glVertex2f(planeX + 200 + 625, planeY + 900 - 440);
	glVertex2f(planeX + 200 + 655, planeY + 900 - 410);
	glVertex2f(planeX + 200 + 665, planeY + 900 - 410);
	glVertex2f(planeX + 200 + 650, planeY + 900 - 440);
	glVertex2f(planeX + 200 + 650, planeY + 900 - 445);
	glEnd();
	//up wing
	glBegin(GL_POLYGON);
	glColor3f(.5, .1, .5);
	glVertex2f(planeX + 200 + 625, planeY + 445);
	glVertex2f(planeX + 200 + 625, planeY + 440);
	glVertex2f(planeX + 200 + 655, planeY + 410);
	glVertex2f(planeX + 200 + 665, planeY + 410);
	glVertex2f(planeX + 200 + 650, planeY + 440);
	glVertex2f(planeX + 200 + 650, planeY + 445);
	glEnd();
	//tail
	glBegin(GL_POLYGON);
	glColor3f(.9, .1, .8);
	glVertex2f(planeX + 200 + 673, planeY + 900 - 455);
	glVertex2f(planeX + 200 + 673, planeY + 900 - 445);
	glVertex2f(planeX + 200 + 690, planeY + 900 - 430);
	glVertex2f(planeX + 200 + 680, planeY + 900 - 450);
	glVertex2f(planeX + 200 + 690, planeY + 900 - 470);
	glEnd();

}

void drawMissileLeft(int missileX, int missileY)

{
	missileLeftX = missileX + 700 - 550;
	missileLeftY = missileY + 450;

	//printf("%d %d \n",missileLeftX,missileLeftY);
	//missile head
	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0);
	glVertex2f(missileX + 700 - 550, missileY + 450);
	glVertex2f(missileX + 700 - 565, missileY + 447);
	glVertex2f(missileX + 700 - 565, missileY + 452);
	glEnd();

	//body
	glBegin(GL_QUADS);
	glColor3f(.8, .4, .1);
	glVertex2f(missileX + 700 - 565, missileY + 447);
	glVertex2f(missileX + 700 - 565, missileY + 452);
	glVertex2f(missileX + 700 - 560, missileY + 452);
	glVertex2f(missileX + 700 - 560, missileY + 447);
	glEnd();

	//tail
	glBegin(GL_POLYGON);
	glColor3f(0, .3, 0);
	glVertex2f(missileX + 700 - 560, missileY + 452);
	glVertex2f(missileX + 700 - 560, missileY + 447);
	glVertex2f(missileX + 700 - 580, missileY + 442);
	glVertex2f(missileX + 700 - 573, missileY + 450);
	glVertex2f(missileX + 700 - 580, missileY + 457);
	glEnd();


	//glFlush();


}

void drawMissileRight(int missileX, int missileY)
{

	missileRightX = missileX + 150;
	missileRightY = missileY + 450;

	//printf("%d %d \n", missileRightX, missileRightY);
	// missileX + 550, missileY + 450
	//missile head
	glBegin(GL_TRIANGLES);
	glColor3f(1, 1, 1);
	glVertex2f(missileX + 200 + 550, missileY + 450);
	glVertex2f(missileX + 200 + 565, missileY + 447);
	glVertex2f(missileX + 200 + 565, missileY + 452);
	glEnd();

	//body
	glBegin(GL_QUADS);
	glColor3f(.4, .6, .7);
	glVertex2f(missileX + 200 + 565, missileY + 447);
	glVertex2f(missileX + 200 + 565, missileY + 452);
	glVertex2f(missileX + 200 + 560, missileY + 452);
	glVertex2f(missileX + 200 + 560, missileY + 447);
	glEnd();

	//tail
	glBegin(GL_POLYGON);
	glColor3f(1, 0.5, 0);

	glVertex2f(missileX + 200 + 560, missileY + 452);
	glVertex2f(missileX + 200 + 560, missileY + 447);
	glVertex2f(missileX + 200 + 580, missileY + 442);
	glVertex2f(missileX + 200 + 573, missileY + 450);
	glVertex2f(missileX + 200 + 580, missileY + 457);
	glEnd();
}


void drawMissile(int x, int y)
{
	drawMissileLeft(posX, posY);
	drawMissileRight(0, 0);
}

int right2left = 0;
void fireMissileRight()
{
	right2left = right2left - 4;

	if (right2left <= -750)
	{
		right2left = 0;
		drawMissileRight(right2left, y2);
	}
	else
	{
		drawMissileRight(right2left, y2);
	}




}


int left2Right = 0;
void fireMissileLeft()
{
	left2Right = left2Right + 3;


	if (left2Right >= 750)
	{
		left2Right = 0;
		drawMissileLeft(left2Right, y1);
	}
	else
	{
		drawMissileLeft(left2Right, y1);
	}

}

void drawPlane()
{

	drawPlaneLeft(x1, y1);
	drawPlaneRight(x2, y2);
}


void fireMissile()
{
	fireMissileLeft();
	fireMissileRight();
}
void timer_func(int n)           // NEW FUNCTION
{
	// Update the object positions, etc.
	fireMissile();  // spin the square

	glutTimerFunc(n, timer_func, n); // recursively call timer_func
}

void myInit(void)
{
	glClearColor(0, .6, 1, 1);


	glColor3f(1, 1, 1);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 900, 750, 0.0);
}

void update(int value)
{
	fireMissile();
	drawMissile(0,0);
	glutPostRedisplay();
	glutTimerFunc(50, update, 0);
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1.0, 1.0, 3200);
	glMatrixMode(GL_MODELVIEW);
}


GLfloat UpwardsScrollVelocity = -10.0;
float view = 10.0;

char quote[6][80];
int numberOfQuotes = 0, i;


void timeTick(void)
{
	if (UpwardsScrollVelocity< -600)
		view -= 0.000011;
	if (view < 0) { view = 20; UpwardsScrollVelocity = -10.0; }
	//  exit(0);
	UpwardsScrollVelocity -= 0.1;
	glutPostRedisplay();

}

void RenderToDisplay()
{
	int l, lenghOfQuote, i;

	glTranslatef(0.0, -100, UpwardsScrollVelocity);
	glRotatef(-20, 1.0, 0.0, 0.0);
	glScalef(0.1, 0.1, 0.1);



	for (l = 0; l<numberOfQuotes; l++)
	{
		lenghOfQuote = (int)strlen(quote[l]);
		glPushMatrix();
		glTranslatef(-(lenghOfQuote * 37), -(l * 200), 0.0);
		for (i = 0; i < lenghOfQuote; i++)
		{
			glColor3f((UpwardsScrollVelocity / 10) + 300 + (l * 10), (UpwardsScrollVelocity / 10) + 300 + (l * 10), 0.0);
			glutStrokeCharacter(GLUT_STROKE_ROMAN, quote[l][i]);


		}
		glPopMatrix();
	}

}

void myDisplayFunction(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, 30.0, 100.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	RenderToDisplay();
	glutSwapBuffers();
}


int winner(char a)
{
	strcpy(quote[0], "Game Over");

	strcpy(quote[1], "Winner Is ");
	//	strcpy_s(quote[2], );
	strcpy(quote[2], "Player ");
	strcpy(quote[3], &a);
	numberOfQuotes = 5;

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	//glutInitWindowSize(1360, 750);
	glutCreateWindow("Game Result");
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glLineWidth(3);

	glutDisplayFunc(myDisplayFunction);
	glutReshapeFunc(reshape);
	glutIdleFunc(timeTick);
	glutMainLoop();

	return 0;
}

bool collisionLeft()
{


	//printf("pX= %d pY=%d mX= %d mY = %d \n",planeLeftX,planeLeftY,missileRightX,missileRightY);
	//printf("pX= %d pY=%d mX= %d mY = %d \n", planeRightX, planeRightY, missileLeftX, missileLeftY);

	if (planeLeftX - 5 < 600 + missileRightX && 600 + missileRightX < planeLeftX + 5 && planeLeftY - 10 < missileRightY && missileRightY <= planeLeftY + 10
		||
		planeLeftBodyX - 5 < 600 + missileRightX && 600 + missileRightX < planeLeftBodyX + 5 && planeLeftBodyY - 13 < missileRightY && missileRightY <= planeLeftBodyY + 13
		||
		planeLeftWingUp1X - 5 < 600 + missileRightX && 600 + missileRightX < planeLeftWingUp1X + 5 && planeLeftWingUp1Y - 10 < missileRightY && missileRightY <= planeLeftWingUp1Y + 10
		||
		planeLeftWingUp2X - 5 < 600 + missileRightX && 600 + missileRightX < planeLeftWingUp2X + 5 && planeLeftWingUp2Y - 10 < missileRightY && missileRightY <= planeLeftWingUp2Y + 10
		||
		planeLeftWingDown1X - 5 < 600 + missileRightX && 600 + missileRightX < planeLeftWingDown1X + 5 && planeLeftWingDown1Y - 10 < missileRightY && missileRightY <= planeLeftWingDown1Y + 10
		||
		planeLeftWingDown2X - 5 < 600 + missileRightX && 600 + missileRightX < planeLeftWingDown2X + 5 && planeLeftWingDown2Y - 10 < missileRightY && missileRightY <= planeLeftWingDown2Y + 10
		)

	{
		colCountL++;
		//printf("a");

		right2left = -750;
		fireMissileRight();
		//glFlush();
		/*printf("Collision 1");*/
		//scanf_s("%d", &a);
		return true;

	}

	else
		return false;
}

bool collisionRight()
{

	if (planeRightX - 5 <   900 - missileLeftX && 900 - missileLeftX< planeRightX + 5 && planeRightY - 10 < missileLeftY && missileLeftY <= planeRightY + 10
		||
		planeRightBodyX - 5 <   900 - missileLeftX && 900 - missileLeftX< planeRightBodyX + 5 && planeRightBodyY - 13 < missileLeftY && missileLeftY <= planeRightBodyY + 13
		||
		planeRightWingUp1X - 5 <   900 - missileLeftX && 900 - missileLeftX< planeRightWingUp1X + 5 && planeRightWingUp1Y - 10 < missileLeftY && missileLeftY <= planeRightWingUp1Y + 10
		||
		planeRightWingUp2X - 5 <   900 - missileLeftX && 900 - missileLeftX< planeRightWingUp2X + 5 && planeRightWingUp2Y - 10 < missileLeftY && missileLeftY <= planeRightWingUp2Y + 10
		||
		planeRightWingDown1X - 5 <   900 - missileLeftX && 900 - missileLeftX< planeRightWingDown1X + 5 && planeRightWingDown1Y - 10 < missileLeftY && missileLeftY <= planeRightWingDown1Y + 10
		||
		planeRightWingDown2X - 5 <   900 - missileLeftX && 900 - missileLeftX< planeRightWingDown2X + 5 && planeRightWingDown2Y - 10 < missileLeftY && missileLeftY <= planeRightWingDown2Y + 10
		)
	{
		/*printf("pX= %d pY=%d bx = %d by = %d uw1x =%d uw1y=%d  uw2x = %d uw2y=%d  \n wd1x= %d wd1y=%d  wd2x = %d wd2y =%d  mX= %d mY = %d \n",
		planeRightX, planeRightY, planeRightBodyX, planeRightBodyY, planeRightWingUp1X, planeRightWingUp1Y, planeRightWingUp2X, planeRightWingUp2Y, planeRightWingDown1X, planeRightWingDown1Y
		, planeRightWingDown2X, planeRightWingDown2Y,missileLeftX, missileLeftY);

		printf("Collision 1");*/
		colCountR++;
		left2Right = 750;
		fireMissileRight();
		return true;
	}
	else

		return false;

}

void myDisplay(void)


{
	char a = '1';
	char b = '2';

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glPushMatrix();
	//glTranslatef(posX, posY, posZ);
	drawPlane();
	//glPopMatrix();
	/*drawHealthBarLeft(0, 0);
	drawHealthBarRight(0, 0);*/

	//glPushMatrix();
	//glTranslatef(missilePosX, 0, 0);
	fireMissileLeft();
	fireMissileRight();
	//glPopMatrix();

	drawHealthBarLeft(0, 0, 0, 0); //draw green
	drawHealthBarRight();

	collisionLeft();
	collisionRight();

	 if (colCountL == 3)
	{
		winner(a);

	}

		else if (colCountR == 3)
		{
			winner(b);
		}


	glFlush();
}


int main(int argc, char** argv)
{


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 768);
	glutInitWindowPosition(0, 0);


	glutCreateWindow("Plane");
	glutDisplayFunc(myDisplay);
	myInit();
	glutTimerFunc(60, update, 0); // timer
	timer_func(100);
	glutMouseFunc(myMouse);
	glutSpecialFunc(keyboardown);
	glutPassiveMotionFunc(myMouseMove);


	glutMainLoop();

	return 0;
}

