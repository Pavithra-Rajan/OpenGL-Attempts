#include <stdio.h>
#include <GL/gl.h>
#include <GL/freeglut.h>

GLfloat r = 0.0, g = 0.0, b = 0.0, a = 0.0;
void renderFunction()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 1.0f);

    glPointSize(5);
    glFlush();
}

void setBG(GLfloat r, GLfloat b, GLfloat g, GLfloat a)
{
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();

}

void changeBG(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'r':
            r = 1.0, g = 0.0, b = 0.0, a = 1.0;
            setBG(r, g, b, a);
            break;
        case 'g':
            r = 0.0, g = 1.0, b = 0.0, a = 1.0;
            setBG(r, g, b, a);
            break;
        case 'y':
            r = 1.0, g = 1.0, b = 0.0, a = 1.0;
            setBG(r, g, b, a);
            break;
        default: break;

    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Background Color Change");
    glutKeyboardFunc(changeBG);
    glutDisplayFunc(renderFunction);
    glutMainLoop();
    return 0;
}
