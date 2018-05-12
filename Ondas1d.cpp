#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

const double DX = 0.01;
const double DT = 0.01;
const double DY = DX;
const double LX = 1;
const double LY = 0;
const int NX = LX/DX + 1;
const int NY = LY/DY + 1;
const double v =0.5;
const double lambda = pow(v*DT/DX,2);


void imprimir(const double malla[][NY]);
void fronteras(double malla[][NY]);
void propaguese(double malla[][NY]);
void gnuplot(void);
double g(double x);


double g(double x){ /*Condición inicial de Newman en U(x,0)*/

return sin(x);

}

void propaguese(double malla[][NY])
{
  
  for(int ii = 1; ii <= NX-2; ++ii) {
    
      malla[ii][0] = 0.5*(pow(lambda,2)*malla[ii+1][0]+2*(1-pow(lambda,2))*malla[ii][0]+pow(lambda,2)*malla[ii-1][0])+DT*g(ii);
    }
  }



void fronteras(double  malla[][NY])
{
        malla[0][0]=0.1;
        malla[NX-1][0]=0.1;
      }
    


void gnuplot(void)
{
  std::cout << "set terminal gif animate" << std::endl;
  std::cout << "set out 'ondas.gif'" << std::endl;
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


int main (void)
{

  double T = 600;
  double grid[NX][NY] = {};
  for (int i = 0; i < NX; ++i){
    grid[i][0]=0;
  }

  fronteras(grid);
  gnuplot();
  
  for (int n = 0; n < T; ++n) {
    propaguese(grid);
    fronteras(grid);    
    imprimir(grid); 
  }

  
  return 0;
}

