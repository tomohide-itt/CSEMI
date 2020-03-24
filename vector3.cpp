#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> v1 = { 1, 2, 3 };
	cout << "size of v1 = " << v1.size() << endl;
	v1.push_back( 10 );
	cout << "size of v1 = " << v1.size() << endl;
	v1.push_back( 20 );
	v1.push_back( 30 );
	cout << "size of v1 = " << v1.size() << endl;
	for( int i=0; i< v1.size(); i++ ){
		cout << i << ": " << v1[i] << endl;
	}

	return 0;
}