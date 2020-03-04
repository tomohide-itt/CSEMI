#include <iostream>
using namespace std;

double sum( double, double );

int main(){

  cout << "4.2 + 1.5 = " << sum(4.2, 1.5) << endl; //こんな使い方もできる
  return 0;
}

double sum( double x, double y ){
  return x+y;
}
