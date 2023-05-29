#include "main.h"
#include <iostream>
#include <GL/glut.h>
#include <array>
#include <cmath>
#include <ctime>
#include "DrawGraphics.h"
#include <time.h>
#include <fstream>

bool Keybord = true;
bool gameover = true;

clock_t time_appState;
clock_t time_animate;

Figure model = {{0.5, 0}, false, 100, true};

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
    Keybord = false;
    glPopMatrix();
}

void Timer(int Result){
    if(gameover == true){
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
    std::fstream inFile;
    inFile.open("Result.txt", std::ios_base::out);
    inFile << str1;


    GameOver();
}
}


void TimerOil(){
 if(gameover == true){
    clock_t Result = clock() / 1000;
    int remains = 0;
    remains = 20 - Result + Add;
    if(remains > 0){
    std::string str1 = "Oil:           ";
    std::string str2 = std::to_string(remains);
    str1.replace(13, 5, str2);
    float x = -2;
    float y = 3;
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
}
//void ProcessKeys( unsigned char key, int x, int y);

  void animateView(){

    clock_t mT = clock();
    float x, y;
    if(model.IsFly == true){
    if (mT < 1000.){
        x = 0.;
        y = 0.;
    } else
    { if (mT < 10000.){
            x = 0.;
            y = 0. - (1. - 0.) / (3000. - 1000.) * (mT - 1000.);
        }
    }
    glTranslatef(x, y, 0);
    }

  }

  void animateStars(){
    clock_t pT = clock();
    float x, y;

    if (pT < 1000.){
    x = 0.;
    y = 0.;
    } else
    { if (pT < 15000.){
            x = 0.;
            y = 0. - (1. - 0.) / (3000. - 1000.) * (pT - 1000.);
     }
    }

    if (pT > 14000.){
     x = -54.0;
     y = -43.0;
    }

    glTranslatef(x, y, 0);

  }

void Stars(){
    glPushMatrix();
    if(clock() < 30000.){
     if(clock() > 14000.){
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
     if(clock() > 14000.){
     if(clock() < 90000.){
    for(unsigned int i = 0.; i < 5.; i++){
    glBegin(GL_POINTS);
    float r = rand()% 201 - 100.;
    float m = rand()% 201 - 100.;
    float rl = r / 100.;
    float ml = m / 100.;
    glVertex2f(rl, ml);
    glColor3ub(224., 255., 255.);
    }
      }
     }
    glEnd();
        animateStars()  ;
    glBegin(GL_POINTS);
    glColor3ub(224., 255., 255.);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.37, 0.21);
    glVertex2f(1.1, 1.4);
    glVertex2f(-0.35, 0.5);
    glVertex2f(-0.16, 0.44);
    glVertex2f(-0.33, 0.19);
    glVertex2f(-0.5, 0.5);
    glVertex2f(-0.56, -0.1);
    glVertex2f(-0.43, -0.1);
    glVertex2f(0.5, 0.5);
    glVertex2f(-0.45, 2.5);
    glVertex2f(-0.25, 0.5);
    glVertex2f(0.15, 0.52);
    glVertex2f(0.37, 0.21);
    glVertex2f(1.1, 1.4);
    glVertex2f(-0.35, 2.5);
    glVertex2f(-0.16, 1.44);
    glVertex2f(-0.13, 3.19);
    glVertex2f(-0.5, 2.5);
    glVertex2f(-0.16, 4.1);
    glVertex2f(-0.43, 4.1);
    glVertex2f(0.25, 3.5);
    glVertex2f(0.45, 3.7);
    glVertex2f(0.15, 3.53);
    glEnd();
    glPopMatrix();
}
}

void animate_earth(){
    clock_t mT = clock();
    float x, y;
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
    glLoadIdentity();
    glOrtho(0.0, 1600.0, 0, 1025, -100.0, 100.0);
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


    glBegin(GL_QUAD_STRIP);
    glColor3ub(160, 82, 45);
    glVertex2f(0.18, 0.18);
    glVertex2f(0.13, 0.18);

    glColor3ub(244, 164, 96);
    glVertex2f(0.18, 0.08);
    glVertex2f(0.13, 0.08);

    glColor3ub(244, 164, 96);
    glVertex2f(0.18, 0.08);
    glVertex2f(0.2, 0.1);
    glVertex2f(0.17, 0.12);
    glVertex2f(0.17, 0.12);

    glEnd();

    glBegin(GL_LINES);
    glColor3ub(160, 82, 45);
    glVertex2f(0.15, 0.2);
    glVertex2f(0.13, 0.18);


    glColor3ub(0, 0, 0);
    glVertex2f(0.2, 0.1);
    glVertex2f(0.13, 0.18);

    glColor3ub(0, 0, 0);
    glVertex2f(0.2, 0.2);
    glVertex2f(0.13, 0.08);
     glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(0,0,0);
    glVertex2f(0.145, 0.16);
    glVertex2f(0.145, 0.11);
    glVertex2f(0.185, 0.11);
    glVertex2f(0.185, 0.16);

    glEnd();
    glPopMatrix();
}

void MechanicOil1(){
    if(Mechanic == 0){
    glPushMatrix();
    float x, y, z = 0;
    int x1, y1, x2, y2;
    x = 0.3;
    y = 0.5;
    x1 = x * 50;
    y1 = y * 80;
    x2 = rocket.pos.x * 10;
    y2 = rocket.pos.y * 10;
    if(cort == 0){
    addoil(x, y, z);
    for (int i = -2; i < 4; i++){
      for (int w = -2; w < 4; w++){
      if(y2 == y1 + i && x2 == x1 + w){
            cort += 1;
             Add += 5;
              Mechanic += 1;
      }
     }
    }
   }
    glPopMatrix();
}
}

void MechanicOil2(){
if(Mechanic == 1){
    glPushMatrix();
    float x, y, z = 0;
    int x1, y1, x2, y2;
    x = -0.1;
    y = -0.68;
    x1 = x ;
    y1 = y ;
    x2 = rocket.pos.x * 10;
    y2 = rocket.pos.y * 20;
    if(cort == 1){
    addoil(x, y, z);
    for (int i = -4; i < 8; i++){
     for (int w = -4; w < 8; w++){
      if(y2 == y1 + i && x2 == x1 + w){
          cort += 1;
          Add += 5;
          Mechanic += 1;
       }
      }
     }
    }
    glPopMatrix();
 }
}

void MechanicOil3(){
 if(Mechanic == 2){
    glPushMatrix();
    float x, y, z = 0;
    int x1, y1, x2, y2;
    x = - 0.56;
    y = 0.77;
    x1 = x * 50;
    y1 = y * 75;
    x2 = rocket.pos.x * 20;
    y2 = rocket.pos.y * 10;
    if(cort == 2){
     addoil(x, y, z);
     for (int i = -4; i < 8; i++){
      for (int w = -4; w < 8; w++){
       if(y2 == y1 + i && x2 == x1 + w){
          cort += 1;
          Add += 5;
          Mechanic += 1;
       }
      }
     }
    }
    glPopMatrix();
 }
}

void MechanicOil4(){
 if(Mechanic == 3){
    glPushMatrix();
    float x, y, z = 0;
    int x1, y1, x2, y2;
    x = 0.55;
    y = 0.58;
    x1 = x * 100;
    y1 = y * 80;
    x2 = rocket.pos.x * 20;
    y2 = rocket.pos.y * 10;
    if(cort == 3){
     addoil(x, y, z);
     for (int i = -4; i < 8; i++){
      for (int w = -4; w < 8; w++){
       if(y2 == y1 + i && x2 == x1 + w){
          cort += 1;
          Add += 5;
          Mechanic += 1;
       }
      }
     }
    }
    glPopMatrix();
 }
}

void MechanicOil5(){
 if(Mechanic == 4){
    glPushMatrix();
    float x, y, z = 0;
    int x1, y1, x2, y2;
    x = 0.75;
    y = -0.58;
    x1 = x * 100;
    y1 = y;
    x2 = rocket.pos.x * 20;
    y2 = rocket.pos.y * 10;
    if(cort == 4){
     addoil(x, y, z);
     for (int i = -4; i < 8; i++){
      for (int w = -4; w < 8; w++){
       if(y2 == y1 + i && x2 == x1 + w){
          cort += 1;
          Add += 5;
          Mechanic += 1;
       }
      }
     }
    }

    glPopMatrix();
 }
}

void MechanicOil6(){
 if(Mechanic == 5){
    glPushMatrix();
    float x, y, z = 0;
    int x1, y1, x2, y2;
    x = -0.1;
    y = -0.2;
    x1 = -x * 83;
    y1 = -y * 83;
    x2 = rocket.pos.x * 20;
    y2 = rocket.pos.y * 10;
    if(cort == 5){
     addoil(x, y, z);
     for (int i = -4; i < 10; i++){
      for (int w = -4; w < 10; w++){
       if(y2 == y1 + i && x2 == x1 + w){
          cort += 1;
          Add += 5;
          Mechanic += 1;
       }
      }
     }
    }

    glPopMatrix();
 }
}

void MechanicOil7(){
 if(Mechanic == 6){
    glPushMatrix();
    float x, y, z = 0;
    int x1, y1, x2, y2;
    x = -0.19;
    y = 0.76;
    x1 = 0;
    y1 = y * 73;
    x2 = rocket.pos.x * 20;
    y2 = rocket.pos.y * 10;
    if(cort == 6){
     addoil(x, y, z);
     for (int i = -2; i < 10; i++){
      for (int w = -2; w < 10; w++){
       if(y2 == y1 + i && x2 == x1 + w){
          cort += 1;
          Add += 5;
          Mechanic += 1;
       }
      }
     }
    }
    glPopMatrix();
 }
}


void drawRocket(Figure & f){
    glPushMatrix();
    glTranslatef( 0, -3. , 0);
    glTranslatef(f.pos.x, f.pos.y, 0);
    if(f.pos.r > 80){
    gameover = false;
    GameOver();
    }

    if(f.pos.r < -80){
    gameover = false;
    GameOver();
    }

    if (Mechanic == 7)
    if(rocket.pos.y > -0.6){
    rocket.pos.y -= 0.006;
    }


    if (Mechanic == 7){

    if (rocket.pos.x < 1){
    rocket.pos.x += 0.1;
    }

    if (rocket.pos.x > -1){
    rocket.pos.x -= 0.1;
    }

    if (rocket.pos.r < 1){
    rocket.pos.r += 0.1;
    }

    if (rocket.pos.r > -1){
    rocket.pos.r -= 0.1;
    }
    Keybord = false;
    }
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


void Moon (){
    glPushMatrix();
    float x = 0;
    glTranslatef(0, -1, 0);
    if( Mechanic == 7 ){
    if( Rx < 1){
      Rx = Rx + 0.001;
    }
    glTranslatef(x, Rx, 0);
    }
    glBegin(GL_QUAD_STRIP);
    glColor3ub(112, 128, 144);
    glVertex2f(1, -1);
    glColor3ub(112, 128, 144);
    glVertex2f(-1, -1);
    glColor3ub(176, 196, 222);
    glVertex2f(0.4, -0.6);
    glColor3ub(112, 128, 144);
    glVertex2f(-0.4, -0.7);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(112, 128, 144);
    glVertex2f(-1, -1);
    glColor3ub(112, 128, 144);
    glVertex2f(1, -1);
    glColor3ub(176, 196, 222);
    glVertex2f(-0.5, -0.6);
    glColor3ub(112, 128, 144);
    glVertex2f(0.4, -0.7);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(112, 128, 144);
    glVertex2f(-1, -1);
    glColor3ub(105, 105, 105);
    glVertex2f(1, -1);
    glColor3ub(128, 128, 128);
    glVertex2f(-0.8, -0.7);
    glColor3ub(112, 128, 144);
    glVertex2f(0.4, -0.7);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(105, 105, 105);
    glVertex2f(1, -1);
    glColor3ub(112, 128, 144);
    glVertex2f(-1, -1);
    glColor3ub(105, 105, 105);
    glVertex2f(0.9, -0.9);
    glColor3ub(128, 128, 128);
    glVertex2f(0.8, -0.7);
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

void meteoritsobject(float x, float y, float z){
    glPushMatrix();
//    x1 = -x * 83;
//    y1 = -Yx * 83;
//    x2 = rocket.pos.x * 20;
//    y2 = rocket.pos.y * 10;
//    if(cort == 5){
//       addoil(x, Yx, 0);
//       for (int i = -2; i < 10; i++){
//      for (int w = -2; w < 10; w++){
//       if(y2 == y1 + i && x2 == x1 + w){
//          cort += 1;
//          Add += 5;
//          Mechanic += 1;
//       }
//      }
//       }
//    }
//    std::cout << x1 << "      " << y1 << std::endl;
//    std::cout << x2 << "      " << y2 << std::endl << std::endl;


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
    glPopMatrix();
}

void meteorits1(){
    glPushMatrix();
    float x = 0.3, y, z = 0;
    int x1, y1, x2, y2;
    glTranslatef(-0.2, 1.5, 0);
    time_t fkdl = clock();
    if( fkdl > 3000 ){
    if( fkdl > 3000){
       Yx = Yx - 0.001;
    }

    glRotatef(-29, 0, 0, 1);
    glTranslatef(x, Yx, 0);

    }



    meteoritsobject(x, Yx, 0);

    glPopMatrix();
}

void meteorits2(){
    glPushMatrix();
    float x = 0.3, y, z = 0;
    int x1, y1, x2, y2;
    glTranslatef(-0.2, 1.5, 0);
    time_t ftdl = clock();
    if( ftdl > 13000 ){
    if( ftdl > 13000){
       glTranslatef(0, -2, 0);
       Yx = Yx - 0.01;
    }

//    glRotatef(9, 0, 0, 1);
    glTranslatef(x, Yx, 0);

    }



    meteoritsobject(x, Yx, 0);

    glPopMatrix();
}

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
    glPushMatrix();
    view();
    meteorits1();
    meteorits2();
    earth();
    Moon();
    MechanicOil1();
    MechanicOil2();
    MechanicOil3();
    MechanicOil4();
    MechanicOil5();
    MechanicOil6();
    MechanicOil7();
    Stars();
    glPopMatrix();
    glPushMatrix();
    glScalef(0.25, 0.25, 1);
    TimerOil();

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

    if(Keybord == true){
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
}
