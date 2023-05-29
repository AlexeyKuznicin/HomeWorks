#ifndef MAIN_H
#define MAIN_H

#include <GL/glut.h>

int Mechanic = 0;
int Add = 0;
int Cont;
int cort = 0;
float d = 0, Rx = 0, Tr = 0, Yx = 0, Ad = 0;

void initGraph();
void GameOver();
void Timer(int Result);

void TimerOil();

void ProcessKeys( unsigned char key, int x, int y);

void animateView();

void animateStars();

void Stars();

void animate_earth();

void earth();

void addoil(float x, float y, float z);

void MechanicOil1();
void MechanicOil2();
void MechanicOil3();
void MechanicOil4();
void MechanicOil5();
void MechanicOil6();
void MechanicOil7();

void Moon ();

void view ();

void meteoritsobject(float x, float y, float z);

void meteorits1();

void meteorits2();


#endif // MAIN_H
