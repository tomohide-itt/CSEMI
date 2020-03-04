#include <iostream>
using namespace std;

void addvec( double*, double*, double* );

int main(){
  int i;
  double a[3] = {1.0, 2.0, 3.0};
  double b[3] = {1.5, 2.0, 2.5};
  double c[3];

  addvec( a, b, c );

  for( i=0; i<3; i++ ){
    cout << "c[" << i << "]=" << c[i] << endl;
  }
  return 0;
}

void addvec( double* v1, double* v2, double* res ){
  int i;
  for( i=0; i<3; i++ ){
    res[i] = v1[i] + v2[i];
  }
}
