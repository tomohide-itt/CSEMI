#include <iostream>
#include <math.h>
using namespace std;

int main(){
  int i;
  double sum = 0.0;
  double v[3] = {1.0, 2.5, 3.2};

  for( i=0; i<3; i++ ){
    sum += v[i]*v[i];
  }
  sum = sqrt(sum);

  for( i=0; i<3; i++ ){
    cout << "v[" << i << "] = " << v[i] << endl;
  }
  cout << "|v| = " << sum << endl;

  return 0;
}
