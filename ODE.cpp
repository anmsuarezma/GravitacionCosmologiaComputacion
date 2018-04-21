#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>


double function (double x, double y){
	
	double function;
	function = 2*pow(x,2)-4*x+y;
	return function;
}

/*Método de Euler*/

double Euler (double x0, double y0, double h){
	
	double yi;
	yi = y0 + h*function(x0,y0);
	return yi;
}

/*Método RK2*/

double PM (double x0, double y0, double h){

	double yi, K1, K2;
	K1 = h*function(x0,y0);
	K2 = h*function(x0+h/2,y0+K1/2);
	yi = y0 + K2;

	return yi;

}

/*Método de RK4o*/

double RK4 (double x0, double y0, double h){

	double yi, K1, K2, K3, K4;
	K1 = h*function(x0,y0);
	K2 = h*function(x0+h/2,y0+K1/2);
	K3 = h*function(x0+h/2,y0+K2/2);
	K4 = h*function(x0+h,y0+K3);
	yi = y0 + (K1+2*K2+2*K3+K4)/6;

	return yi;

}






int main (){

	double h, puntos, y0, y01, y02;
	int a, b;
	h=pow(10, -2);	
	a=1;	b=10;
	y0 = 0.7182818;
	y01 = 0.7182818;
	y02 = 0.7182818;

	for (double i=a; i<=b; i+=h){
		
		/*double ErrorEuler, ErrorPM, ErrorRK;
		ErrorEuler = std::abs(Euler(i, y0, h)-exp(i)+2*pow(i,2));
		ErrorPM = std::abs(PM(i, y01, h)-exp(i)+2*pow(i,2));
		ErrorRK = std::abs(RK4(i, y02, h)-exp(i)+2*pow(i,2));
		std::cout<<i<<"\t"<<ErrorEuler<<"\t"<<ErrorPM<<"\t"<<ErrorRK<<std::endl;*/
		std::cout<<i<<"\t"<<Euler(i, y0, h)<<"\t"<<PM(i, y01, h)<<"\t"<<RK4(i, y02, h)<<"\t"<<exp(i)-2*pow(i,2)<<std::endl;
		y0=Euler(i, y0, h);	y01=PM(i, y01, h);	y02=RK4(i, y02, h);
	}


	
	return 0;
}




