#include <iostream>
using namespace std;

int main(){
  double a;

  cout << "input a>";
  cin >> a;

  if( a >= 0 && a <= 10 ){
    cout << "a ranges from 0 to 10 inclusive" << endl;
  }else{
    cout << "a is out of range from 0 to 10" << endl;
  }

  return 0;
}
