#include <GL/glut.h>
#include <array>
#include <cmath>

struct Position{
    GLfloat x,y;
};

struct Figure{
    Position pos;
    bool isRight;
    GLfloat health;
};

Figure rocket = {{0,0}, false, 100};

const int n = 100;
std::array <Position, n> graph;

void renderScene(void);
void initGraph();
void plotGraph();
void plotAxes();

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

void plotGraph(){
    glPushMatrix();
    glScalef(.02,.02,1);
    glTranslatef(-3, 0, 0);

    plotAxes();

    glBegin(GL_LINE_STRIP);
    glColor3f(1, 1, 1);
    for(int i = 0; i < graph.size(); i++)
      glVertex2f(graph[i].x, graph[i].y);

    glEnd();
    glPopMatrix();
}

//// График 1. Кариоида
//void initGraph(){
//    Position p;

//    float x = 0.0;
//    float xf = 2 * 3.14;
//    float h = (xf - x) / n;
//    int i = 0;
//    while (x<xf) {
//        p.x = (1 + cos(x)) * cos(x);
//      p.y = (1 + cos(x)) * sin(x);
//        graph[i] = p;
//        x = x + h;
//        i++;
//    }
//}

// График 2. Гипоциклоиды
void initGraph(){
    Position p;

    float x = 0.0;
    float xf = 10 * 3.14;
    float h = (xf - x) / n;
    int i = 0;
    while (x < xf) {
      p.x = 24.8 * (cos(x) + (cos(6.2 * x) / 6.2));
        p.y = 24.8 * (sin(x) - (sin(6.2 * x) / 6.2));
        graph[i] = p;
        x = x + h;
        i++;
    }
}
void ProcessKeys( unsigned char key, int x, int y);

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("OpenGL Start Application");
    glutDisplayFunc(renderScene);
    glutKeyboardFunc(ProcessKeys);
    glutMainLoop();
    return 0;
}

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // эта функция должна быть первой в renderScene
    // фон
//    view();
//    earth();
//    glPushMatrix();
//    glScalef(0.5,0.5, 1);
//    // ракета
//    Figure f = {0.5, 0, false, 100};
//    drawRocket(f);
//    f.pos.x = -0.3;
//    f.pos.y = 0.3;
//    drawRocket(f);
//    drawRocket(rocket);

//    meteorit();
    initGraph();
    plotGraph();
    plotAxes();

    glPopMatrix();
    glutSwapBuffers();
}

void ProcessKeys( unsigned char key, int x, int y){
    if(key == 'w'){
        rocket.pos.y += 0.04;
        rocket.isRight = true;
    };
    if(key == 'a'){
        rocket.pos.x -= 0.04;
        rocket.isRight = true;
    };
    if(key == 's'){
        rocket.pos.y -= 0.04;
        rocket.isRight = true;
    };
    if(key == 'd'){
        rocket.pos.x += 0.04;
        rocket.isRight = true;
    };
    glutPostRedisplay();
}
