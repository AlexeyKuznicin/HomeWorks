#include <GL/glut.h>
void renderScene(void);


int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("OpenGL Start Application");
    glutDisplayFunc(renderScene);
    glutMainLoop();
    return 0;
}


void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // эта функция должна быть первой в renderScene

    glBegin(GL_QUAD_STRIP);
    glColor3ub(25,25,112); // 1.ЗАДНИЙ ФОН
    glVertex2f(1, -1);
    glColor3ub(0,0,0);
    glVertex2f(-1, -1);
    glColor3ub(0,0,0);
    glVertex2f(1, 1);
    glColor3ub(75,0,130);
    glVertex2f(-1, 1);
    glEnd();

    glScalef(0.5,0.5,0);
    glTranslatef(-0.5,0,0);
    glBegin(GL_QUAD_STRIP);
    glColor3ub(112,128,144);   // 2.РАКЕТА
    glVertex2f(0.03, -0.13);
    glColor3ub(112,128,144);
    glVertex2f(-0.03, -0.13);
    glColor3ub(128,0,0);
    glVertex2f(0.03, 0.13);
    glColor3ub(128,0,0);
    glVertex2f(-0.03, 0.13);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(176,196,222);
    glVertex2f(0.03, -0.13);
    glVertex2f(-0.03, -0.13);
    glVertex2f(0.025, -0.18);
    glVertex2f(-0.025, -0.18);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(176,196,222);
    glVertex2f(0.015, -0.24);
    glColor3ub(112,128,144);
    glVertex2f(-0.015, -0.24);
    glColor3ub(112,128,144);
    glVertex2f(0.03, -0.13);
    glVertex2f(-0.03, -0.13);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glColor3ub(255,250,250);
    glVertex2f(-0.027, -0.13);
    glVertex2f(-0.07, -0.44);
    glVertex2f(0, -0.44);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glColor3ub(255,250,250);
    glVertex2f(0.027, -0.13);
    glColor3ub(255,250,250);
    glVertex2f(0.07, -0.44);
    glColor3ub(112,128,144);
    glVertex2f(0, -0.44);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glColor3ub(255,250,250);
    glVertex2f(0.027, -0.13);
    glColor3ub(255,235,215);
    glVertex2f(0.07, -0.44);
    glColor3ub(112,128,144);
    glVertex2f(0.06, -0.24);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glColor3ub(255,250,250);
    glVertex2f(-0.027, -0.13);
    glVertex2f(-0.07, -0.44);
    glColor3ub(112,128,144);
    glVertex2f(-0.06, -0.24);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(112,128,144);
    glVertex2f(0.07, -0.44);
    glColor3ub(112,128,144);
    glVertex2f(0.075, -0.5);
    glColor3ub(0,0,128);
    glVertex2f(-0.07, -0.44);
    glColor3ub(0,0,128);
    glVertex2f(-0.075, -0.5);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(255,140,0);
    glVertex2f(0.075, -0.5);
    glColor3ub(255,140,0);
    glVertex2f(0.08, -0.55);
    glColor3ub(128,0,0);
    glVertex2f(-0.075, -0.5);
    glColor3ub(128,0,0);
    glVertex2f(-0.08, -0.55);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0, -0.4);
    glVertex2f(0, -0.55);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(128,0,0);
    glVertex2f(0.037, 0.13);
    glVertex2f(-0.037, 0.13);
    glVertex2f(0.03, 0.07);
    glVertex2f(-0.03, 0.07);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glColor3ub(128,0,0);
    glVertex2f(-0.03, 0.07);
    glColor3ub(112,128,144);
    glVertex2f(-0.03, -0.18);
    glColor3ub(128,0,0);
    glVertex2f(-0.045, 0);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glColor3ub(128,0,0);
    glVertex2f(0.03, 0.07);
    glColor3ub(112,128,144);
    glVertex2f(0.03, -0.18);
    glColor3ub(128,0,0);
    glVertex2f(0.045, 0);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(255,250,250);
    glVertex2f(0.037, 0.13);
    glColor3ub(112,128,144);
    glVertex2f(-0.037, 0.13);
    glColor3ub(255,250,250);
    glVertex2f(0.037, 0.2);
    glColor3ub(112,128,144);
    glVertex2f(-0.037, 0.2);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(112,128,144);
    glVertex2f(0.037, 0.2);
    glColor3ub(112,128,144);
    glVertex2f(-0.037, 0.2);
    glColor3ub(0,0,0);
    glVertex2f(0.03, 0.24);
    glColor3ub(0,0,0);
    glVertex2f(-0.03, 0.24);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(255,250,250);
    glVertex2f(0.048, 0.24);
    glColor3ub(112,128,144);
    glVertex2f(-0.048, 0.24);
    glColor3ub(255,250,250);
    glVertex2f(0.048, 0.4);
    glColor3ub(112,128,144);
    glVertex2f(-0.048, 0.4);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(0,0,0);
    glVertex2f(0.035, 0.44);
    glColor3ub(0,0,0);
    glVertex2f(-0.035, 0.44);
    glColor3ub(169,169,169);
    glVertex2f(0.048, 0.4);
    glColor3ub(169,169,169);
    glVertex2f(-0.048, 0.4);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(105,105,105);
    glVertex2f(0.02, 0.47);
    glColor3ub(105,105,105);
    glVertex2f(-0.02, 0.47);
    glColor3ub(0,0,0);
    glVertex2f(0.035, 0.44);
    glColor3ub(0,0,0);
    glVertex2f(-0.035, 0.44);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(105,105,105);
    glVertex2f(0.02, 0.47);
    glVertex2f(-0.02, 0.47);
    glVertex2f(0, 0.5);
    glVertex2f(0, 0.5);
    glEnd();



    glScalef(0.8,0.8,0);
    glTranslatef(1,0,0);
    glBegin(GL_QUAD_STRIP);  // 3.МЕТЕОРИТ
    glColor3ub(112,128,144);
    glVertex2f(0, -0.2);
    glColor3ub(112,128,144);
    glVertex2f(-0.2, 0);
    glColor3ub(112,128,144);
    glVertex2f(0.2, 0);
    glColor3ub(112,128,144);
    glVertex2f(-0.05, 0.18);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(176,196,222);
    glVertex2f(0, -0.2);
    glColor3ub(112,128,144);
    glVertex2f(0.2, 0);
    glColor3ub(176,196,222);
    glVertex2f(-0.2, 0);
    glColor3ub(112,128,144);
    glVertex2f(0.05, 0.18);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(112,128,144);
    glVertex2f(0, 0.2);
    glColor3ub(119,136,153);
    glVertex2f(0.2, 0);
    glColor3ub(112,128,144);
    glVertex2f(-0.2, 0);
    glColor3ub(119,136,153);
    glVertex2f(0.05, -0.18);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(112,128,144);
    glVertex2f(0, 0.2);
    glColor3ub(176,196,222);
    glVertex2f(-0.2, 0);
    glColor3ub(176,196,222);
    glVertex2f(0.2, 0);
    glColor3ub(176,196,222);
    glVertex2f(-0.05, -0.18);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(112,128,144);
    glVertex2f(0.15, 0.14);
    glVertex2f(-0.2, 0);
    glVertex2f(0.2, 0);
    glVertex2f(-0.05, -0.18);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(176,196,222);
    glVertex2f(-0.15, 0.14);
    glVertex2f(0.2, 0);
    glColor3ub(112,128,144);
    glVertex2f(-0.2, 0);
    glVertex2f(0.05, -0.18);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(112,128,144);
    glVertex2f(-0.15, -0.14);
    glColor3ub(176,196,222);
    glVertex2f(0.2, 0);
    glColor3ub(112,128,144);
    glVertex2f(-0.2, 0);
    glColor3ub(176,196,222);
    glVertex2f(0.05, 0.18);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glColor3ub(0,0,0);
    glVertex2f(0, 0);
    glVertex2f(-0.2, 0.1);
    glVertex2f(-0.1, 0);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glColor3ub(0,0,0);
    glVertex2f(0, 0);
    glVertex2f(0.2, 0.1);
    glVertex2f(0.1, 0);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glColor3ub(220,20,60);
    glVertex2f(-0.1, -0.13);
    glVertex2f(0.05, -0.14);
    glVertex2f(0.1, -0.1);
    glEnd();
    glutSwapBuffers();
}
