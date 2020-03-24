#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> v1 = { 1, 2, 3 };
	v1[1] = 10;
	for( int i=0; i< v1.size(); i++ ){
		cout << i << ": " << v1[i] << endl;
	}
	v1.at(2) = 20;
	cout << "v1.at(2) = " << v1.at(2) << endl;

	return 0;
}