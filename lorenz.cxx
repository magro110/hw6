#include <iostream>
#include <cmath>

using namespace std;

void func(double* const k, const int a, const int b, const double c, const double x, const double y, const double z);
  
  int main(){
    
    const double dt=0.001;
    const int tEnd=100, N = tEnd/dt;
    double t, k1[3], k2[3], k3[3], k4[3], x, y, z;
    double xtemp1, xtemp2, xtemp3;
    double ytemp1, ytemp2, ytemp3;
    double ztemp1, ztemp2, ztemp3;
    const int a=10, b=28;
    const double c=8.0/3.0;
    
    x=1;
    y=1;
    z=1;
    t=0;
    
    for(int i=0; i<N; i++){
      
      t+=dt;
      
      func(k1, a, b, c, x, y, z);
      
      xtemp1=x+dt/2*k1[0];
      ytemp1=y+dt/2*k1[1];
      ztemp1=z+dt/2*k1[2];
      func(k2,a,b,c,xtemp1,ytemp1,ztemp1);
      
      xtemp2=x+dt/2*k2[0];
      ytemp2=y+dt/2*k2[1];
      ztemp2=z+dt/2*k2[2];
      func(k3,a,b,c,xtemp2,ytemp2, ztemp2);
      
      xtemp3=x+dt*k3[0];
      ytemp3=y+dt*k3[1];
      ztemp3=z+dt*k3[2];
      func(k4,a,b,c,xtemp3,ytemp3,ztemp3);
      
      x+=(dt/6)*(k1[0]+2*k2[0]+2*k3[0]+k4[0]);
      y+=(dt/6)*(k1[1]+2*k2[1]+2*k3[1]+k4[1]);
      z+=(dt/6)*(k1[2]+2*k2[2]+2*k3[3]+k4[4]);
      
      cout << t << "\t" << x << "\t" << y << "\t" << z << endl;
      
      
      
      
    }
    
    
    return 0;
    
  }
  
  void func(double* const k,const int a, const int b, const double c, const double x, const double y, const double z){
    
    k[0] = a*(y-x);
    
    k[1] = x*(b-z)-y;
    
    k[2] = x*y-c*z;
    
  }
      
    
    