#include <iostream>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
using namespace std;
struct RGB
{
    int red;
    int green;
    int blue;
};

unsigned long long lastFrameTime = 0;
RGB skyTop = {147, 236, 244};
RGB skyBottom = {243, 240, 189};

float birdX = 0, birdY=900, birdWingY = -1, birdDirection=1;

void polygon(vector<pair<float, float>> coord, RGB rgb = {255, 255, 255}, float Tx = 0, float Ty = 0, float s = 1)
{
    glColor3ub(rgb.red, rgb.green, rgb.blue);
    glBegin(GL_POLYGON);
    for (int i = 0; i < coord.size(); i++)
        glVertex2d(Tx + s * coord[i].first, Ty + s * coord[i].second);
    glEnd();
}

void bird(float Tx, float Ty, float direction, float birdWingY, RGB rgb = {0,0,0}, float s = 1)
{
    polygon({
        {28.65 * direction, 2.99},
        {31.98 * direction, 1.74},
        {31.6 * direction, 0.23},
        {31.93 * direction, -1.29},
        {30.43 * direction, -0.38},
        {28.77 * direction, -1.12},
        {24.29 * direction, -4.59},
        {16.47 * direction, -5.28},
        {10.7 * direction, -4.96},
        {2.95 * direction, -10.29},
        {8.55 * direction, -3.22},
        {0.18 * direction, 1.29},
        {9.57 * direction, -0.31},
        {11.02 * direction, 0.27},
        {22.82 * direction, 1.86},
        {28.65 * direction, 2.99}
    }, rgb, Tx, Ty, s);

    polygon({
        {22.82 * direction, birdWingY * 1.86},
        {23.38 * direction, birdWingY * 8.57},
        {9.98 * direction, birdWingY * 25.45},
        {11.02 * direction, birdWingY * 0.27}
    }, rgb, Tx, Ty, s);
}

void background()
{
    //sky
    glBegin(GL_QUADS);
    glColor3ub(skyBottom.red, skyBottom.green, skyBottom.blue);
    glVertex2f(0, 0);
    glVertex2f(1920, 0);
    glColor3ub(skyTop.red, skyTop.green, skyTop.blue);
    glVertex2f(1920, 1080);
    glVertex2f(0, 1080);
    glEnd();
}

void display()
{
    background();
    //birds
    bird(birdX-10, birdY-100, birdDirection, birdWingY,{0,0,0},2.5);
    bird(birdX-20, birdY-200, birdDirection, -birdWingY,{0,0,0},2);
    bird(birdX-30, birdY-300, birdDirection, birdWingY,{0,0,0},1.5);
    bird(birdX-40, birdY-400, birdDirection, birdWingY,{0,0,0},1);
    bird(birdX-50, birdY-500, birdDirection, birdWingY,{0,0,0},0.5);
    glFlush();
    glutSwapBuffers();
}


void birdAnimation()
{
    birdX += 7*birdDirection;
    birdWingY += 0.5;
    if (birdWingY > 1) birdWingY = -1;
    if(birdX>3000) birdDirection=-1;
    if(birdX<-1500) birdDirection=1;
}

void animation()
{
    float frameTime = 1000 / 60.0, currentTime = GetTickCount();
    if (currentTime - lastFrameTime >= frameTime)
    {
        lastFrameTime = currentTime;
        birdAnimation();
    }
    glutPostRedisplay();
}

void init(void)
{
    glClearColor(0.0F, 0.0F, 0.0F, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1920, 0, 1080);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_MULTISAMPLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1920, 1080);
    glutCreateWindow("Bird Anomation");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(animation);
    glutMainLoop();
}
