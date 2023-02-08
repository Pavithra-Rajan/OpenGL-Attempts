#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <iostream>
#include <vector>
using namespace std;

void renderFunction() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.5f, 0.5f);// RGB colours

	freopen("points.txt", "r", stdin);

	vector<pair<float, float>> points;
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++) 
	{
		float x, y;
		cin >> x >> y;
		points.push_back(make_pair(x, y));
	}

	for(int i = 0; i < points.size(); i++) 
	{
		for(int j = 0; j < points.size(); j++) 
		{
			if(i != j) 
			{
				glBegin(GL_LINES);
				glVertex2f(points[i].first, points[i].second);
				glVertex2f(points[j].first, points[j].second);
				glEnd();
			}
		}
	}

	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Diagonals");

	glutDisplayFunc(renderFunction);
	glutMainLoop();
	return 0;
}
