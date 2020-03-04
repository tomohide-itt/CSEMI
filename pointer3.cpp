#include <iostream>
using namespace std;

void cal( double, double, double*, double* );

int main(){
  double a, b, c, d;

  a = 1.5;
  b = 2.3;
  cal( a, b, &c, &d );

  cout << a << " + " << b << " = " << c << endl;
  cout << a << " - " << b << " = " << d << endl;
  return 0;
}

void cal( double x, double y, double* sum, double* dif ){
  *sum = x+y;
  *dif = x-y;
}
