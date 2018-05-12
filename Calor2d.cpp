#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

const double DX = 1;
const double DY = DX;
const double LX = 100;
const double LY = 100;
const int NX = LX/DX + 1;
const int NY = LY/DY + 1;
const double k =0.1;
const double lambda = k*DX/pow(DY,2);


void imprimir(const double malla[][NY]);
void fronteras(double malla[][NY]);
void propaguese(double malla[][NY]);
void gnuplot(void);


void propaguese(double malla[][NY])
{
  
  for(int ii = 1; ii <= NX-2; ++ii) {
    for(int jj = 1; jj <= NY-2; ++jj) {
      malla[ii][jj] = malla[ii][jj]+lambda*(malla[ii+1][jj]+malla[ii-1][jj]-4*malla[ii][jj]+malla[ii][jj+1]+malla[ii][jj-1]);
    }
  }
}



void fronteras(double  malla[][NY])
{
  
  for (int i=0; i<NY; ++i){  
				malla[i][0]=100;
				malla[i][NY-1]=100;
				malla[0][i]=100;
				malla[NY-1][i]=100;
			}
		}


void gnuplot(void)
{
  std::cout << "set terminal gif animate" << std::endl;
  std::cout << "set out 'calor.gif'" << std::endl;
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
	for (int j = 0; j < NY; ++j){
		grid[i][j]=5;
		grid[i][j]=5;
	}
}
  fronteras(grid);
  gnuplot();
  
  for (int n = 0; n < T; ++n) {
    propaguese(grid);
    fronteras(grid);
   // std::cout<<n<<"\t"<<grid[1][1]<<"\t"<<grid[25][25]<<"\t"<<grid[50][50]<<"\t"<<grid[75][75]<<"\t"<<grid
    //[NY-2][NY-2]<<std::endl;
    
    imprimir(grid); 
  }

  
  return 0;
}

