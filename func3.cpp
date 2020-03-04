#include <iostream>
using namespace std;

double sum( double, double );
void show( int );
void show( double );

int main(){
  int a = 123;
  double b;

  b = sum(123.0, 0.456);
  show( a );
  show( b );
  return 0;
}

double sum( double x, double y ){
  return x+y;
}

void show(int i){
  cout << i << endl;
}

void show(double d){
  cout << d << endl;
}
