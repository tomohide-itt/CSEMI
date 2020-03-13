#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

void open_file_m( ifstream& fp, const string message, ios_base::openmode mode = ios_base::in );
void open_file_m( ofstream& fp, const string message, ios_base::openmode mode = ios_base::out );

int main(){
	ifstream fin;
	ofstream fout;
	double a, b;

	open_file_m( fin, "input file name>> ", ios::in );
	open_file_m( fout, "output file name>> ", ios::out );
	fin >> a;
	fin >> b;

	fout << a << " + " << b << " = " << a+b << endl;

	fin.close();
	fout.close();

	return 0;
}

void open_file_m( ifstream& fp, const string message, ios_base::openmode mode ){
	string fname;
	cout << message << endl;
	cin >> fname;
	fp.open( fname, mode );
	if( !fp ){
		cout << fname << "was not opened." << endl;
	}
}

void open_file_m( ofstream& fp, const string message, ios_base::openmode mode ){
	string fname;
	cout << message << endl;
	cin >> fname;
	fp.open( fname, mode );
	if( !fp ){
		cout << fname << "was not opened." << endl;
	}
}