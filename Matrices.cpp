#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

int aleatorio(double a, double b){
	return a + (rand()*(b - a))/RAND_MAX;
}

double **crearMatriz(int m, int n){
	double **matriz;
	matriz = new double *[m];
	if(matriz == NULL){
		return NULL;
	}
	for(int fila = 0; fila < m; fila++){
		matriz[fila] = new double [n];
		if(matriz[fila] == NULL){
			return NULL;
		}
	}
	return matriz;
}

void borrarMatriz(double **a, int m){
	for(int iteracion = 0; iteracion < m; iteracion++){
		delete a[iteracion];
	}
	delete a;
}

void leerMatriz(double **matriz, int m, int n){
	int op;
	do{
		cout<<"\nDesea ingresar los elementos de la matriz...\n\n";
		cout<<"1. Aleatoriamente seleccionando un intervalo.\n2. Manualmente.\n\n";
		cin>>op;
		if(op < 1 || op > 2){
			cout<<"\n...Argumentos no validos... vuelva a intentarlo.\n";
		}
	}while(op < 1 || op > 2);
	if(op == 1){
		int a1, b1;
		cout<<"\nel minimo del intervalo: ";
		cin>>a1;
		cout<<"\nel maximo del intervalo: ";
		cin>>b1;
		cout<<"\n";
		for(int fil = 0; fil < m; fil++){
			for(int col = 0; col < n; col++){
				*(*(matriz + fil) + col) = aleatorio(a1 , b1);
				cout<<"coordenada ["<<(fil + 1)<<"]["<<(col + 1)<<"] = "<<matriz[fil][col];
				cout<<"\n";
			}
		}
	}
	if(op == 2){
		for(int fil = 0; fil < m; fil++){
			for(int col = 0; col < n; col++){
				cout<<"coordenada ["<<(fil + 1)<<"]["<<(col + 1)<<"] = ";
				cin>>*(*(matriz + fil) + col);
				cout<<"\n";
			}
		}
	}
}

void mostrarMatriz(double **matriz, int m, int n){
	for(int i = 0; i < m; i++){
		cout<<"\t|| ";
		for(int j = 0; j < n; j++){
			cout<<*(*(matriz + i) + j)<<" ";
		}
		cout<<"||\n";
	}
}

void sumarMatriz(double **matriz1, double **matriz2, int fil, int col){
	for(int i = 0; i < fil; i++){
		for(int j = 0; j < col; j++){
			*(*(matriz1 + i) + j) += *(*(matriz2 + i) + j);
		}
	}
	cout<<"la suma entre las matrices dadas, corresponde a la matriz:\n";
	mostrarMatriz(matriz1 , fil , col);
}

void restarMatriz(double **matriz1, double **matriz2, int fil, int col){
	for(int i = 0; i < fil; i++){
		for(int j = 0; j < col; j++){
			*(*(matriz1 + i) + j) -= *(*(matriz2 + i) + j);
		}
	}
	cout<<"la suma entre las matrices dadas, corresponde a la matriz:\n";
	mostrarMatriz(matriz1 , fil , col);
}

void escalarMatriz(double **matriz, int fil, int col){
	int k;
	cout<<"\nIngresar el escalar a complificar: ";
	cin>>k;
	for(int i = 0; i < fil; i++){
		for(int j = 0; j < col; j++){
			*(*(matriz + i) + j) = *(*(matriz + i) + j)*k;
		}
	}
	cout<<"El producto escalar con el valor "<<k<<" de la matrices dada, corresponde a la matriz:\n";
	mostrarMatriz(matriz , fil , col);
}

void transpuestaMatriz(double **matrizInicio, int fil, int col){
	double **matrizFinal;
	matrizFinal = crearMatriz(fil , col);
	for(int i = 0; i < fil; i++){
		for(int j = 0; j < col; j++){
			*(*(matrizFinal + j) + i) = *(*(matrizInicio + i) + j);
		}
	}
	cout<<"\nLa transpuesta de la matriz es:\n\n";
	mostrarMatriz(matrizFinal , fil , col);
	borrarMatriz(matrizFinal , fil);
}

int simetricaMatriz(double **matriz , int m){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			if(*(*(matriz + i) + j) != *(*(matriz + j) + i)){
				return 0;
			}
		}	
	}
	return 1;
}

void productoMatriz(double **matriz1, double **matriz2, int fil1, int col1fil2, int col2){
	double **m;
	m = crearMatriz(fil1 , col2);
	for(int i = 0; i < fil1; i++){
		for(int j = 0; j < col2; j++){
			for(int k = 0; k < col1fil2; k++){
				*(*(m + i) + j) += *(*(matriz1 + i) + k) * *(*(matriz2 + k) + j);
			}
		}
	}
	mostrarMatriz(m , fil1 , col2);
	borrarMatriz(m , fil1);
}


int main(){
	char a;
	do{
		int opcion, columnas, filas;
		do{
			opcion = 0;
			columnas = 0;
			cout<<"\n En que dimension de filas desea trabajar (mayor o igual que 1) \n";
			cin>>filas;
			cout<<"\n En que dimension de columnas desea trabajar (mayor o igual que 1) \n";
			cin>>columnas;
			if(columnas == 1 || filas == 1){
				cout<<"\n\n(Vectores) Escoga una accion a realizar: \n\n";
				cout<<"1. Suma de Vectores \n2. Resta de Vectores \n3. Producto escalar con un Vector \n4. Producto Interno entre Vectores \n\n";
				cin>>opcion;
			}
			if(columnas > 1 && filas > 1){
				cout<<"(Matrices) Escoga una accion a realizar: \n\n";
				cout<<"1. Suma de Matrices \n2. Resta de Matrices \n3. Producto escalar con una Matriz \n4. Producto entre Matrices \n\n";
				cin>>opcion;
			}
			if(opcion < 1 || opcion > 4 || columnas <= 0 || filas <= 0){
				cout<<"\n...Argumentos no validos... vuelva a intentarlo.\n";
			}
		}while(opcion < 1 || opcion > 4 || columnas <= 0 || filas <= 0);

		double **r, **s;
		r = crearMatriz(filas , columnas);
		leerMatriz(r , filas , columnas);
		switch (opcion){
			case 1:
			s = crearMatriz(filas , columnas);
			leerMatriz(s , filas , columnas);
			sumarMatriz(r , s , filas , columnas);
			borrarMatriz(s , filas);
			break;
			case 2:
			s = crearMatriz(filas , columnas);
			leerMatriz(s , filas , columnas);
			restarMatriz(r , s , filas , columnas);
			borrarMatriz(s , filas);
			break;
			case 3:
			escalarMatriz(r , filas , columnas);
			break;
			case 4:
			int columnas2;
			do{
				cout<<"\n Dimension de columnas segunda matriz (mayor o igual que 1) \n";
				cin>>columnas2;
				if(columnas2 <= 0){
					cout<<"\n...Argumentos no validos... vuelva a intentarlo.\n";
				}
			}while(columnas2 <= 0);
			s = crearMatriz(columnas , columnas2);
			leerMatriz(s , columnas , columnas2);
			productoMatriz(r , s , filas , columnas , columnas2);
			borrarMatriz(s , columnas);
			break;
			case 5:
			transpuestaMatriz(r , filas , columnas);
			break;
		}
		borrarMatriz(r , filas);

		cout<<"¿Desea continuar?. \n SI es asi, pulse la tecla 0 \n en caso contrario, pulse cualquier tecla:";
		cin>>a;
		cout<<"\n\n";
	}while(a == '0');
	return 0;
}