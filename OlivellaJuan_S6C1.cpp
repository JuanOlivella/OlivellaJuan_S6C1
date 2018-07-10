#include <iostream>
#include <cstdlib>
#include <cmath>
#include <math.h>

#define G 9.8
#define L 1.0
#define M 1.0
#define FR 0.0
#define F 0.0

using std::cout;
using std::endl;


float pendulo_1(float t, float y1, float y2);
float pendulo_2(float t, float y1, float y2);


int main(){

  float maxt = 7.0;

  float mint = 0.0;

  int puntos = 10000;

  float h = (maxt - mint)/(puntos);

  float t[puntos];

  float y1[puntos];

  float y2[puntos];

  t[0] = mint;
  
  y1[0] = 1.0;

  y2[0] = 0.0;


  for(int i = 1; i < puntos; i++){

    float k1_1 = h * pendulo_1(t[i-1], y1[i-1], y2[i-1]);
    float k1_2 = h * pendulo_2(t[i-1], y1[i-1], y2[i-1]);

    float k2_1 = h * pendulo_1(t[i-1] + 0.5*h, y1[i-1] +0.5*k1_1, y2[i-1] +0.5*k1_1);
    float k2_2 = h * pendulo_2(t[i-1] + 0.5*h, y1[i-1] +0.5*k1_2, y2[i-1] +0.5*k1_2);

    float k3_1 = h * pendulo_1(t[i-1] + 0.5*h, y1[i-1] +0.5*k2_1, y2[i-1] +0.5*k2_1);
    float k3_2 = h * pendulo_2(t[i-1] + 0.5*h, y1[i-1] +0.5*k2_2, y2[i-1] +0.5*k2_2);

    float k4_1 = h * pendulo_1(t[i-1] + h, y1[i-1] + k3_1, y2[i-1] + k3_1);
    float k4_2 = h * pendulo_2(t[i-1] + h, y1[i-1] + k3_2, y2[i-1] + k3_2);

    float promedioK_1 = (k1_1 + 2*k2_1 + 2*k3_1 + k4_1)*(1.0/6.0);
    float promedioK_2 = (k1_2 + 2*k2_2 + 2*k3_2 + k4_2)*(1.0/6.0);

    t[i] = t[i-1] + h;

    y1[i] = y1[i-1] + promedioK_1;
    y2[i] = y2[i-1] + promedioK_2;


    cout << t[i] << "  " << y1[i] << "  " << y2[i] << endl;

  }


}


float pendulo_1(float tt, float yy1, float yy2){

  return yy2;

}

float pendulo_2(float tt, float yy1, float yy2){

  return (-1)*(G/L)*(sin(yy1));


}