#include <iostream>
#include <new>
using namespace std;

int main(){
	int* a = new int[4];
	double* b = new double[5];

	for( int i=0; i< 4; i++ ) a[i] = i+1;
	for( int i=0; i< 5; i++ ) b[i] = 1.1 + double(i);

	for( int i=0; i< 4; i++ ){
		cout << "a[" << i << "]=" << a[i] << endl;
	}
	for( int i=0; i< 5; i++ ){
		cout << "b[" << i << "]=" << b[i] << endl;
	}

	delete[] a;
	delete[] b;

	return 0;
}