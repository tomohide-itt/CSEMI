#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  int i,j;
  double A[3][3] = {1.0, 0.2, 0.5,
                    0.3, 2.0, 0.8,
                    0.4, 0.9, 1.0};

  cout << "[A] = " << endl;
  for( i=0; i<3; i++ ){
    for( j=0; j<3; j++ ){
      cout << setw(10) << fixed << setprecision(2) << A[i][j];
    }
    cout << endl;
  }

  return 0;
}
