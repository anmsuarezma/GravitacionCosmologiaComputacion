#include <iostream>
#include <cmath>
#include <Eigen/Dense>
using Eigen::MatrixXd;


int main() {
	int m, n;
	m=10;	n=10;
	

//-----Matriz tridiagonal------
   MatrixXd T(m, n);
   double sup,inf,diag, lambda;
   
   diag = 1;  inf =-2;	sup=-2;	 
	for (int row = 0; row < m; ++row)
	{
   	for (int col = 0; col < n; ++col)
   		{
        	if (row==col)
        		T(row,col) = diag;
       		 if (row+1==col)
        		T(row,col)=sup;
         	if (row-1==col)
        		T(row,col)=inf;
   		}
	}

	MatrixXd TInv(m,n);
	TInv = T.inverse();
std::cout<<""<<std::endl;
std::cout<<"Tridiagonal"<<std::endl;
std::cout<<""<<std::endl;	
std::cout<<T<<std::endl;
std::cout<<""<<std::endl;
std::cout<<"Inversa"<<std::endl;
std::cout<<""<<std::endl;
std::cout<<TInv<<std::endl;
//------------------------------------
	

return 0;
}