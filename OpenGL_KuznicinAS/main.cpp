#include <iostream>
#include <GL/glut.h>
#include <array>
#include <cmath>
#include <ctime>
#include "DrawGraphics.h"
#include <time.h>

clock_t time_appState;
clock_t time_animate;
clock_t time_Stars;
int Cont;
int cort;
Figure model = {{0.5, 0.}, false, 100, true};

Meteroits Danger = {0. , 0.};
float d = 0;

void GameOver(){
    glPushMatrix();
    std::string str = " GAME OVER";
    float x = -1.2;
    float y = -0.2;
    glColor3f(0.43, 0.65, 0.1);
    glRasterPos2f(x, y);
    int i = 0;
    while (str[i] != '\0')
    {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, str[i]);
        i++;
        glRasterPos2f(x + i*0.2, y);
    }
    glPopMatrix();
}

void Timer(int Result){
    std::string str1 = "Your Result:           ";
    std::string str2 = std::to_string (Result);
    str1.replace(13, 5, str2);
    float x = -1.7;
    float y = -0.4;
    glColor3f(0.43, 0.65, 0.1);
    glRasterPos2f(x, y);
    int i = 0;
    while (str1[i] != '\0')
    {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, str1[i]);
        i++;
        glRasterPos2f(x + i*0.2, y);
    }
    GameOver();
}


void TimerOil(){
    int remains = 0;
    clock_t Result = clock() / 1000;
    remains = 20 - Result;
    if(remains > 0){
    std::string str1 = "Oil:           ";
    std::string str2 = std::to_string(remains);
    str1.replace(13, 5, str2);
    float x = -1.7;
    float y = 2.8;
    glColor3f(0.43, 0.65, 0.1);
    glRasterPos2f(x, y);
    int i = 0;
    while (str1[i] != '\0')
    {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, str1[i]);
        i++;
        glRasterPos2f(x + i*0.2, y);
    }
       } else Timer(Cont);

    if((remains < 1) && (remains > -1)) Cont = Result;
  }
void ProcessKeys( unsigned char key, int x, int y);


void Stars(){

    glPushMatrix();
    if(clock() < 15000.){
     if(clock() > 8000.){
    for(int i = 0.; i < 3.; i++){
    glBegin(GL_POINTS);
     float r = rand()% 201 - 100.;
      float m = rand()% 201 - 100.;
       float rl = r / 100.;
        float ml = m / 100.;
    glVertex2f(rl, ml);
    glColor3ub(224., 255., 255.);
    }
    }
        if(clock() > 90000.){
    for(unsigned int i = 0.; i < 10.; i++){
    glBegin(GL_POINTS);
    float r = rand()% 201 - 100.;
    float m = rand()% 201 - 100.;
    float rl = r / 100.;
    float ml = m / 100.;
    glVertex2f(rl, ml);
    glColor3ub(224., 255., 255.);
    }
        }
    glEnd();
    glPopMatrix();
    }
}

void animateView(){
    clock_t mT = clock();
    float x, y;
    if(model.IsFly == true){
        if (mT < 1000.){
    x = 0.;
    y = 0.;
        } else
        { if (mT < 100000.){
    x = 0.;
    y = 0. - (1. - 0.) / (3000. - 1000.) * (mT - 1000.);
    }
        }
        glTranslatef(x, y, 0);
    }


}
void animate_earth(){
    clock_t mT = clock();
    float x, y, z;
    if(model.IsFly == true){
    if (mT < 1000.){
    x = 0.;
    y = 0.;
    } else
    { if (mT < 3000.){
        x = 0.;
        y = 0. - (1. - 0.) / (3000. - 1000.) * (mT - 1000.);
    } else{
        x = 0.;
        y = -2.;
      }
    }
    glTranslatef(x, y, 0);
   }
}


void earth(){
    glPushMatrix();
     animate_earth();
     glBegin(GL_QUAD_STRIP);
     glColor3ub(0,0,0);
     glVertex2f(-1, -1);
     glColor3ub(47, 79, 79);
     glVertex2f(-1, -0.90);
     glColor3ub(47, 79, 79);
     glVertex2f(1, -1);
     glColor3ub(47, 79, 79);
     glVertex2f(1, -0.85);

     glColor3ub(1,50,32);
     glVertex2f(-1, -1);
     glColor3ub(47, 79, 79);
     glVertex2f(0.9, -0.70);
     glColor3ub(47, 79, 79);
     glVertex2f(1, -1);
     glColor3ub(47, 79, 79);
     glVertex2f(-1, -0.85);
     glEnd();
    glPopMatrix();
  }

void addoil(float x, float y, float z){
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(x, y, z);
    glBegin(GL_QUAD_STRIP);
    glColor3ub(160, 82, 45);

    glVertex2f(0.2, 0.2);
    glVertex2f(0.15, 0.2);
    glColor3ub(244, 164, 96);
    glVertex2f(0.2, 0.1);
    glVertex2f(0.15, 0.1);

    glEnd();
    glPopMatrix();
}

void MechanicOil(){
    glPushMatrix();
    float x, y, z = 0, abr, bbr ;
    x = 0.5;
    y = 0.5;
    if(cort == 0){
    addoil(x, y, z);
    for(float i = -15; i < 60000; i ++){
      abr = y + (i/29000);
      bbr = x + (i/30000);
      if(rocket.pos.y == abr && rocket.pos.x == bbr){
            cort += 1;
      }
    }
  }
    std::cout << rocket.pos.y << "      " << abr << std::endl;
    std::cout << rocket.pos.x << "      " << bbr << std::endl << std::endl;
    glPopMatrix();
}

void drawRocket(Figure & f){
    glPushMatrix();
    glTranslatef( 0, -3. , 0);
    glTranslatef(f.pos.x, f.pos.y, 0);
    if(f.pos.r > 80) f.pos.r = 0;
    if(f.pos.r < -80) f.pos.r = 0;
    glRotatef(f.pos.r, 0, 0, 1);
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

//    glBegin(GL_QUAD_STRIP);
//    glColor3ub(128, 0, 0);
//    glVertex2f(0, -0.22);
//    glColor3ub(160, 82, 45);
//    glVertex2f(-1, -0.18);
//    glColor3ub(128, 0, 0);
//    glVertex2f(1.2, -0.22);
//    glColor3ub(160, 82, 45);
//    glVertex2f(0.8, -0.21);
    glEnd();
    glPopMatrix();
}

void view (){

    glPushMatrix();
    animateView();
    glScalef(2,2,0);
    glBegin(GL_QUAD_STRIP);
//    glColor3ub(2, 25, 1); // 3.ЗАДНИЙ ФОН
//    glVertex2f(1, -1);
//    glColor3ub(0,0,0);
//    glVertex2f(-1, 2);
//    glColor3ub(0,0,0);
//    glVertex2f(1, 2);
//    glColor3ub(1, 0 ,2);
//    glVertex2f(-1, 1);

    glBegin(GL_QUAD_STRIP);
    glColor3ub(1, 0 ,5); // 2.ЗАДНИЙ ФОН
    glVertex2f(1, 6);
    glColor3ub(1, 0 ,5);
    glVertex2f(-1, 6);
    glColor3ub(25, 25, 112);
    glVertex2f(1, 2);
    glColor3ub(1, 0 ,5);
    glVertex2f(-1, 2);

    glColor3ub(25, 25, 112); // 1.ЗАДНИЙ ФОН
    glVertex2f(1, -1);
    glColor3ub(0,0,0);
    glVertex2f(-1, -1);
    glColor3ub(25, 25, 112);
    glVertex2f(1, 2);
    glColor3ub(1, 0 ,5);
    glVertex2f(-1, 2);
    glEnd();
    glPopMatrix();
}
//void Meteorits(){
//    Meteroits x, y;
//    for(int i = 0; i < 10; i++){
//    Danger.pos.x = (rand() % 400 - 200)/100;
//    Danger.pos.y = (rand() % 400 - 200)/100;

//    std::cout << Danger.pos.x << "  " << Danger.pos.y << "  " << std::endl;
//    }
//}
//void meteorit (float x, float y, float f){
//    glPushMatrix();
//    Meteorits();
//    glTranslatef(x, y, 0);
//    glScalef(f,f,0); // f +- = 0.8
//    glBegin(GL_QUAD_STRIP);  // 3.МЕТЕОРИТ
//    glColor3ub(112,128,144);
//    glVertex2f(0, -0.2);
//    glColor3ub(112,128,144);
//    glVertex2f(-0.2, 0);
//    glColor3ub(112,128,144);
//    glVertex2f(0.2, 0);
//    glColor3ub(112,128,144);
//    glVertex2f(-0.05, 0.18);
//    glEnd();

//    glBegin(GL_QUAD_STRIP);
//    glColor3ub(176,196,222);
//    glVertex2f(0, -0.2);
//    glColor3ub(112,128,144);
//    glVertex2f(0.2, 0);
//    glColor3ub(176,196,222);
//    glVertex2f(-0.2, 0);
//    glColor3ub(112,128,144);
//    glVertex2f(0.05, 0.18);
//    glEnd();

//    glBegin(GL_QUAD_STRIP);
//    glColor3ub(112,128,144);
//    glVertex2f(0, 0.2);
//    glColor3ub(119,136,153);
//    glVertex2f(0.2, 0);
//    glColor3ub(112,128,144);
//    glVertex2f(-0.2, 0);
//    glColor3ub(119,136,153);
//    glVertex2f(0.05, -0.18);
//    glEnd();

//    glBegin(GL_QUAD_STRIP);
//    glColor3ub(112,128,144);
//    glVertex2f(0, 0.2);
//    glColor3ub(176,196,222);
//    glVertex2f(-0.2, 0);
//    glColor3ub(176,196,222);
//    glVertex2f(0.2, 0);
//    glColor3ub(176,196,222);
//    glVertex2f(-0.05, -0.18);
//    glEnd();

//    glBegin(GL_QUAD_STRIP);
//    glColor3ub(112,128,144);
//    glVertex2f(0.15, 0.14);
//    glVertex2f(-0.2, 0);
//    glVertex2f(0.2, 0);
//    glVertex2f(-0.05, -0.18);
//    glEnd();

//    glBegin(GL_QUAD_STRIP);
//    glColor3ub(176,196,222);
//    glVertex2f(-0.15, 0.14);
//    glVertex2f(0.2, 0);
//    glColor3ub(112,128,144);
//    glVertex2f(-0.2, 0);
//    glVertex2f(0.05, -0.18);
//    glEnd();

//    glBegin(GL_QUAD_STRIP);
//    glColor3ub(112,128,144);
//    glVertex2f(-0.15, -0.14);
//    glColor3ub(176,196,222);
//    glVertex2f(0.2, 0);
//    glColor3ub(112,128,144);
//    glVertex2f(-0.2, 0);
//    glColor3ub(176,196,222);
//    glVertex2f(0.05, 0.18);
//    glEnd();
//    glPopMatrix();
//}
//void RandMeteroits(){
//    clock_t rT = clock();

//    float x, y, Fx, Fy;

//}

void animate(int value){
    glutPostRedisplay();
    glutTimerFunc(1000/ 200, animate, 1);
}



void drowAnimate(){
            clock_t cT = clock();
    float x, y;
        if (cT < 1000.){
        x = 0.;
        y = 0.;
    } else
    { if (cT < 3000.){
            x = 0.;
           y = 0. + (1. - 0.) / (3000. - 1000.) * (cT - 1000.);
         } else {
           x = 0.;
            y = 0.994;
        }
    }
//    std::cout << y << " " << x << std::endl;
    glTranslatef(x, y, 0);
}

int main(int argc, char* argv[])
{
    srand( time(0) );
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("OpenGL Start Application");
    glutDisplayFunc(renderScene);
    glutKeyboardFunc(ProcessKeys);
    glutTimerFunc(1000/60, animate, 1); // 1000 / 60 - это время через которое будет запущена функция, переданная вторым параметром
    time_appState = clock();
    time_animate = clock();
    glutMainLoop();
    return 0;
}
// u = (S1 - S0) / ( t1 - t0);
// S(T) = S0 + u * T;
// Базовая формула для анимации и синхронизации;
//

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // эта функция должна быть первой в renderScene
//     фон
    glPushMatrix();
    view();
    earth();
    MechanicOil();
    Stars();
    glPopMatrix();
    glPushMatrix();
    glScalef(0.25, 0.25, 1);
    // ракета
    TimerOil();
    model.pos.x = -0.3;
    model.pos.y = 0.3;
    glPushMatrix();
    drowAnimate();
    drawRocket(rocket);
    glPopMatrix();
//    RandMeteroits();
//    initGraph();
//    plotGraph();
//    plotAxes();

    glPopMatrix();
    glutSwapBuffers();
}

void ProcessKeys( unsigned char key, int x, int y){
    if(key == 'w'){
        rocket.pos.y += 0.04;
        rocket.isRight = true;
        rocket.pos.x += d;
    };
    if(key == 'a'){
        d = d - 0.002;
        rocket.isRight = true;
        rocket.pos.r += 1;
    };
    if(key == 's'){
        rocket.pos.y -= 0.04;
        rocket.isRight = true;
        rocket.pos.x -= d;
    };
    if(key == 'd'){
        rocket.isRight = true;
        rocket.pos.r -= 1;
        d = d + 0.002;
    };
    glutPostRedisplay();
}
