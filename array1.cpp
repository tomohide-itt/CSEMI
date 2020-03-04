#include <iostream>
using namespace std;

int main(){
  int i;
  double v[3] = {1.0, 2.5, 3.2};
  char ss[4] = "abc";

  for( i=0; i<3; i++ ){
    cout << "v[" << i << "] = " << v[i] << endl;
  }
  cout << "ss = " << ss << endl;

  return 0;
}
