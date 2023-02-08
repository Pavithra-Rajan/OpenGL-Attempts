#include<GL/freeglut.h>
#include<GL/gl.h>

GLfloat angle = 0;
int refresh = 1;

void timer(int value) 
{
    glutPostRedisplay();
    glutTimerFunc(refresh, timer, 0);
}

void drawTriangle() 
{
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.1,0.4);
        glVertex2f(0.5,0.4);
        glVertex2f(0.3,0.8);
    glEnd();
}

void rotateTriangle()
{
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(0.1,0.4,0);
    glRotatef(angle,0,0,1); 
    glTranslatef(-0.1,-0.4,0);
    drawTriangle();
    glPopMatrix();
    
    glutSwapBuffers();
    angle+=0.2;
}

void renderFunction() 
{
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);

    rotateTriangle();

    glFlush();
}

int main(int argc, char **argv) 
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("Rotating Triangle");

    glutDisplayFunc(renderFunction);
    glutTimerFunc(0,timer,0);
    glutMainLoop();
    return 0;
}