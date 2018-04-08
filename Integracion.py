import numpy as np

def funcion (x):
	f = x**2
	return f

def Rectangulo (a, b, intervalos):
	delta = (b-a)/intervalos
	suma=0
	for i in range (intervalos):
		ii=i*delta
		suma+=funcion(ii)*delta
	return suma
	

def Punto_Medio (a, b, intervalos):
	delta = (b-a)/intervalos
	suma=0
	for i in range(intervalos):
		j=a+ i*delta - (delta/2)
		suma+=funcion(j)*delta
	return suma


def Simpson (a,b, intervalos):
	delta = (b-a)/intervalos
	suma=0
	for i in range (intervalos):
		ii=a+i*delta
		kk=a+(i+1)*delta
		jj=a+i*delta+(delta/2)
		delta1 = (kk-ii)/2	
		suma += (delta1/3)*(funcion(ii)+4*funcion(jj)+funcion(kk))
	return suma

intervalos = 10**3
#print (np.abs(Rectangulo(0,1,intervalos)-1./3), "\t", np.abs(Punto_Medio(0,1,intervalos)-1./3))
print(np.abs(Simpson(0,1,intervalos)))
