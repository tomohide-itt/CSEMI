#include <iostream>
using namespace std;

void swap( double, double );

int main(){
  double a, b;

  a = 1.5;
  b = 2.3;
  swap( a, b );

  cout << "a = " << a << ", b = " << b << endl;
  return 0;
}

void swap( double x, double y ){
  double z;
  z = x;
  x = y;
  y = z;
}
