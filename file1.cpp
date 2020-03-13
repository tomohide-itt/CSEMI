#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream fin;
	double a, b;

	fin.open("input_file1.dat", ios::in );
	fin >> a;
	fin >> b;

	cout << a << " + " << b << " = " << a+b << endl;

	fin.close();

	return 0;
}