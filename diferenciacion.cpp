#include<iostream>
#include <cmath>
#include <math.h>

double function(double x){
	double f;
	f = 2*pow(x,3)-9*x+12; //cos(x)*exp(x); 
	return f;
}



double forward (double a, double h){
	double derivada = 0;
	derivada = (function(a+h)-function(a))/h;


	return derivada;

}


double central (double a, double h){
	double derivada=0;
	derivada = (function(a+h/2)-function(a-h/2))/h;
	return derivada;
}


double centralmej (double a, double h){
	double derivada=0;
	derivada = (function(a+h/4)-function(a-h/4))/(h/2);
	return derivada;
}


double extended (double a, double h){
	double derivada = 0;
	derivada = (4*centralmej(a, h/2)-centralmej(a, h))/3;
	return derivada;
}



/*Segundas Derivadas*/


double second (double a, double h){
	double derivada=0;
	derivada = pow(h,-2)*(function(a+h)-2*function(a)+function(a-h));
	return derivada;
}


/*Newton Raphson*/

double NR(double x){
	double error = pow(10,-4);
	double h = pow(10,-3);
	double xnext = 0;
	
	do{

		x = x - (central(x,h)/second(x,h));
		xnext = x;
	}

	while(std::abs(xnext-x)>=error);
	
	return x;	
}








int main()
{	
	double t=1;
	double h=pow(10,-5);
	double real = -4.57471;
	//std::cout<<h<<"\t"<<std::abs(forward(t, h)-real)<<"\t"<<std::abs(central(t, h)-real)<<"\t"<<std::abs(extended(t, h)-real)<<std::endl;


	//Grillado
	//Reconstruir la derivada de la función en [0,1]  
	
	int puntos = 10000;
	
	for (int i=0;i<=puntos;i++){
		
		double ii = 0;
		
		ii+=2*i/(1.*puntos);

		
		//std::cout<<ii<<"\t"<<function(ii)<<"\t"<<extended(ii,h)<<"\t"<<second(ii,h)<<std::endl;
}	

	std::cout<<"Velocidad mínima para t = "<<NR(1.)<<std::endl;
	std::cout<<"Posición en t = "<<NR(1.)<<" ---> "<<function(NR(1.))<<std::endl;
	std::cout<<"Aceleración en t = "<<NR(1.)<<" ---> "<<second(NR(1.),h)<<std::endl;
	
	 	return 0;
	 	
}
