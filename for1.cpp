#include <iostream>
using namespace std;

int main(){
  int sum, i;

  sum = 0;
  for( i=1; i<=1000; i++ ){
    sum += i;
  }

  cout << "sum=" << sum << endl;

  return 0;
}
