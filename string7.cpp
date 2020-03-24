#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void readline( ifstream& fp, string& str ){
	getline( fp, str );
	size_t slash_pos = str.find("//");
	if( slash_pos != std::string::npos ){
		str.erase( slash_pos );
	}
	if( str[0] == '#' || str.empty() ){
		readline( fp, str );
	}
}

int main(){
	ifstream fin;
	fin.open( "input_string7.dat", ios::in );
	string ss;
	for( int i=0; i< 3; i++ ){
		readline( fin, ss );
		cout << ss << endl;
	}

	fin.close();

	return 0;
}