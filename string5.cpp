#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	ifstream fin;
	fin.open( "input_string5.dat", ios::in );
	string ss;
	for( int i=0; i< 3; i++ ){
		getline( fin, ss );
		cout << ss << endl;
	}

	fin.close();

	return 0;
}