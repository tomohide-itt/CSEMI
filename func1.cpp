#include <iostream>
using namespace std;

double sum( double x, double y );

int main(){
  double a, b, c;

  a = 1.5;
  b = 2.3;
  c = sum( a, b );

  cout << a << " + " << b << " = " << c << endl;
  return 0;
}

double sum( double x, double y ){
  double z;
  z = x + y;
  return z;
}
