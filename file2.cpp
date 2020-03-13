#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(){
	ifstream fin;
	double a, b;

	fin.open("input_file1.dat", ios::in );
	if( !fin ){
		cout << "file-input_file1.dat was not opened." << endl;
		exit(1);
	}
	fin >> a;
	fin >> b;

	cout << a << " + " << b << " = " << a+b << endl;

	fin.close();

	return 0;
}