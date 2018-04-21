#include <iostream>
#include <cmath>
#include <math.h>

const double Omega2 = 5.;
const double tf = 2.*M_PI;
const int puntos =200;
const double h = tf/puntos;

double RK4 (double x0, double y0, double h);
double funcion (double x, double t);
double Euler (double x0, double y0, double h);
double v[]={};
double x[]={};
double veuler[]={};
double xeuler[]={};

double funcion (double x, double t){
	double f;
	f = 3*x*Omega2 +  cos(10*t);
	return f;
}


double RK4 (double x0, double y0, double h){

	double yi, K1, K2, K3, K4;
	K1 = h*funcion(x0,y0);
	K2 = h*funcion(x0+h/2,y0+K1/2);
	K3 = h*funcion(x0+h/2,y0+K2/2);
	K4 = h*funcion(x0+h,y0+K3);
	yi = y0 + (K1+2*K2+2*K3+K4)/6;
	return yi;
}


double Euler (double x0, double y0, double h){
	
	double yi;
	yi = y0 + h*x0*Omega2;
	return yi;
}



int main (void){

  	double t0=0.;
  
for (int i=1; i<=puntos; i++){
	x[0]=-1.;	v[0]=0.;
	
	
	v[i]=RK4(-1.*x[i-1],v[i-1],h);
	x[i]=RK4(v[i],x[i-1],h);
	
	/*veuler[i]=Euler(-1.*x[i-1],v[i-1],h);
	xeuler[i]=Euler(v[i],x[i-1],h);*/
	
		std::cout<<i<<"\t"<<x[i]<<"\t"<</*xeuler[i]<<"\t"<<v[i]<<"\t"<<*/v[i]<<std::endl;
}	
  
  	
  return 0;
}
