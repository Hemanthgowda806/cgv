#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
typedef float point[3];
GLfloat v[3][2] = {{0.0, 0.0}, {500.0, 0.0}, {250.0, 500.0}};
int n;
void triangle(point a, point b, point c)
{
    glBegin(GL_POLYGON);
    glVertex2fv(a);
    glVertex2fv(b);
    glVertex2fv(c);
    glEnd();
}
void divide_tri(GLfloat *a, GLfloat *b, GLfloat *c, int m)
{
    GLfloat v0[2], v1[2], v2[2];
    int j;
    if (m > 0)
    {
        for (j = 0; j < 2; j++)
            v0[j] = (a[j] + b[j]) / 2.0;
        for (j = 0; j < 2; j++)
            v1[j] = (a[j] + c[j]) / 2.0;
        for (j = 0; j < 2; j++)
            v2[j] = (b[j] + c[j]) / 2.0;
        divide_tri(a, v0, v1, m - 1);
        divide_tri(c, v1, v2, m - 1);
        divide_tri(b, v2, v0, m - 1);
    }
    else
        triangle(a, b, c);
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    divide_tri(v[0], v[1], v[2], n);
    glFlush();
}
void myinit()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(1.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    printf("Number of subdivisions\n");
    scanf("%d", &n);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0.0, 0.0);
    glutInitWindowSize(500.0, 500.0);
    glutCreateWindow("2D Gasket");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
}