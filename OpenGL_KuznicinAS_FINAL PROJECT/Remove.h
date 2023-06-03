#ifndef REMOVE_H
#define REMOVE_H


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
#endif // Remove_H
