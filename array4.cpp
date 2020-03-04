#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  int i,j,k;
  double sum = 0.0;
  double A[3][3] = {1.0, 0.2, 0.5,
                    0.3, 2.0, 0.8,
                    0.4, 0.9, 1.0};
  double B[3][3] = { 2.0, -0.3, 0.3,
                     0.4,  1.0, 0.6,
                    -0.4,  0.8, 3.0};
  double C[3][3];

  //calculate [A]*[B]
  for( i=0; i<3; i++ ){
    for( j=0; j<3; j++ ){
      sum = 0.0;
      for( k=0; k<3; k++ ){
        sum += A[i][k]*B[k][j];
      }
      C[i][j] = sum;
    }
  }

  //output [C]
  cout << "[C] = " << endl;
  for( i=0; i<3; i++ ){
    for( j=0; j<3; j++ ){
      cout << setw(10) << fixed << setprecision(2) << C[i][j];
    }
    cout << endl;
  }

  return 0;
}
