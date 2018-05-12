#include <iostream>
#include <vector>

const double DX = 0.1;
const double DY = DX;
const double LX = 1.234;
const double LY = 1.4356;
const int NX = LX/DX + 1;
const int NY = LY/DY + 1;

void imprimir(const double malla[][NY]);
void fronteras(double malla[][NY]);
void propaguese(double malla[][NY]);
void gnuplot(void);

int main (void)
{
  double grid[NX][NY] = {0.0};
  fronteras(grid);
  gnuplot();
  
  for (int n = 0; n < 100; ++n) {
    propaguese(grid);
    imprimir(grid); 
  }

  
  return 0;
}

void propaguese(double malla[][NY])
{

  for(int ii = 1; ii <= NX-2; ++ii) {
    for(int jj = 1; jj <= NY-2; ++jj) {
      malla[ii][jj] = (malla[ii+1][jj] + malla[ii-1][jj] + 
		       malla[ii][jj+1] + malla[ii][jj-1])/4;
    }
  }
}

void gnuplot(void)
{
  std::cout << "set terminal gif animate" << std::endl;
  std::cout << "set out 'laplace.gif'" << std::endl;
  std::cout << "set contour base" << std::endl;
  std::cout << "set pm3d" << std::endl;
}

void imprimir(const double malla[][NY])
{
  std::cout << "splot '-' w l lw 2 " << std::endl;
  double x, y;
  for (int ii = 0; ii < NX; ++ii){
    x = ii*DX;
    for (int jj = 0; jj < NY; ++jj){
      y = jj*DY;
      std::cout << x << "  " << y << "  " <<  malla[ii][jj] << std::endl;
    }
    std::cout << std::endl;
  }
  std::cout << "e" << std::endl;
}

void fronteras(double  malla[][NY])
{
  int ii, jj;
  
  //Abajo
  ii = 0;
  for(jj = 0; jj < NY; ++jj) {
    malla[ii][jj] = 0.0;
  }

  //Arriba
  ii = NX-1;
  for(jj = 0; jj < NY; ++jj) {
    malla[ii][jj] = 100.0;
  }

  //Izquierda
  jj = 0;
  for(ii = 0; ii < NX; ++ii) {
    malla[ii][jj] = 0.0;
  }
  
  //Derecha
  jj = NY-1;
  for(ii = 0; ii < NX; ++ii) {
    malla[ii][jj] = 0.0;
  }
}
