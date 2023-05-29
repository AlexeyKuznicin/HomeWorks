#include "Remove.h"
#include <cmath>
#include <array>

Figure rocket = {{0,0}, false, 100};
const int n = 100;
std::array <Position, n> graph;

void plotGraph(){
    glPushMatrix();
    glScalef(.25,.25,1);
    glTranslatef(-3, 0, 0);

    plotAxes();

    glBegin(GL_LINE_STRIP);
    glColor3f(.25, .25, 1);
    for(int i = 0; i < graph.size(); i++)
      glVertex2f(graph[i].x, graph[i].y);
    glEnd();
    glPopMatrix();
}

void plotAxes(){
    glBegin(GL_LINES);
    glColor3f(1, 0, 0);
    glVertex2f(0,0);
    glVertex2f(3,0);

    glColor3f(0, 0, 1);
    glVertex2f(0,0);
    glVertex2f(0,3);
    glEnd();
}

void initGraph(){
    Position p;

    glScalef(0.1,0.1,1);
    float x = 0;
    float xf = 10* M_PI;
    float h = (xf - x) / n;
    int i = 0;
    while (x < xf) {
        p.x = 24.8 * (cos(x) + cos(6.2*x) / 6.2);
        p.y = 24.8 * (sin(x) - sin(6.2 * x) / 6.2);
        graph[i] = p;
        x = x + h;
        i++;
    }
}
