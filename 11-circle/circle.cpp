#include <GL/freeglut.h>
#include <GL/gl.h>
#include <random>

void renderFunction() 
{
    glClearColor(0, 0, 0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);

    glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) 
        {
            float degree_rad = i * 3.14 / 180;
            glVertex2f(cos(degree_rad) * 0.5, sin(degree_rad) * 0.5);
        }
    glEnd();

    glLineWidth(3.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 360; i++) 
        {
            float degree_rad = i * 3.14 / 180;
            glVertex2f(cos(degree_rad) * 0.5, sin(degree_rad) * 0.5);
        }
    glEnd();
    glFlush();
}

int main (int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Circle");
    glutDisplayFunc(renderFunction);
    glutMainLoop();
    return 0;
}