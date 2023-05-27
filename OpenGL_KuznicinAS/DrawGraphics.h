#ifndef DRAWGRAPHICS_H
#define DRAWGRAPHICS_H


#include <GL/glut.h>

struct Position{
    GLfloat x,y,r;
};

struct Meteroits{
    GLfloat health;
    Position pos;
};

struct Figure{
    Position pos;
    bool isRight;
    GLfloat health;
    bool IsFly;
};

extern Figure rocket;

void initGraph();
void plotGraph();
void plotAxes();
void renderScene(void);
void SceneStastic(void);
#endif // DRAWGRAPHICS_H
