#include <iostream>
#include <cmath>
#include <math.h>


double funcion(double x){
	double f;
	f = sin(x);
	return f;

	}

double rectangulo(double a, double b, int divisiones){

	double delta = (b-a)/divisiones;
		double ii;
		 
		double suma=0;
	for (int i=0; i<=divisiones;i++){
		ii = i*delta ;
		suma += funcion(ii)*delta;
	}
	return suma;

}

double punto_medio(double c, double d, int divisiones1){

	double sum;
	double delta = (d-c)/divisiones1;
	double ii;
	
	for (int i=0; i<=divisiones1;i++){
		ii = c+i*delta - delta/2; //(a+b)/2
		sum += funcion(ii)*delta;
	}
	return sum;

}

double simpson (double a, double b, int intervalos){
	double suma = 0;
	double delta = (b-a)/intervalos;
	double ii=0, jj=0, kk=0;
	for (int i=0; i<intervalos; i++){

		ii=a+i*delta;	kk=a+(i+1)*delta;
		jj=a+i*delta+(delta/2);
		double delta1 = (kk-ii)/2;
		suma += (delta1/3)*(funcion(ii)+4*funcion(jj)+funcion(kk));
	} 
	return suma;
}




int main()
{	
	double a,b;
	a=0;	b=M_PI;
	int divisiones=10;
	double Rectangulo;
	double Punto_medio;
	double Simpson;
	Punto_medio = punto_medio(a,b, divisiones);
	Rectangulo = rectangulo(a,b, divisiones); 
	Simpson = simpson(a,b,divisiones);
	//std::cout<<std::abs(Rectangulo-1./3)<<"\t"<< std::abs(Punto_medio-1./3)<<"\t"<<divisiones<<std::endl;
	std::cout<< Simpson<<std::endl;

	return 0;
}