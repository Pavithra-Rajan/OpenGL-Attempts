#include <GL/freeglut.h>
#include <GL/gl.h>
#include <stdio.h>

struct Point
{
    GLfloat x, y;
};

struct Point points[1000];
int count = 0;

void readPoints()
{
    FILE *f = fopen("points.txt", "r");
    if(f)
    {
        while(fscanf(f, "%f %f", &(points[count].x), &(points[count].y)) != EOF)
        {
            count++;
        }
    }
    fclose(f);
}

void renderFunction()
{
    int i = 0;
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.5f, 0.5f);
    glPointSize(8);

    glBegin(GL_POINTS);
    while(i < count)
    {
        glVertex2f(points[i].x, points[i].y);
        i++;
    }
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    readPoints();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Plotting Points from File");
    glutDisplayFunc(renderFunction);
    glutMainLoop();
    return 0;
}
