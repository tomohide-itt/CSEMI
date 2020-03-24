#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void readline( ifstream& fp, string& str ){
	getline( fp, str );
	if( str[0] == '#' || str.empty() ){
		readline( fp, str );
	}
}

int main(){
	ifstream fin;
	fin.open( "input_string6.dat", ios::in );
	string ss;
	for( int i=0; i< 3; i++ ){
		readline( fin, ss );
		cout << ss << endl;
	}

	fin.close();

	return 0;
}