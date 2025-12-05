#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
}
void drawsquare()
{
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 30.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(30.0, 0.0);
    glVertex2f(30.0, 30.0);
    glEnd();
    glFlush();
}
void mymouse(int btb, int state, int x, int y)
{
    if (btb == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        drawsquare();
    if (btb == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        exit(0);
}
void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50.0, 50.0, -50.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("square");
    myinit();
    glutDisplayFunc(myDisplay);
    glutMouseFunc(mymouse);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutMainLoop();
}