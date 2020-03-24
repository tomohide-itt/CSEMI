#include<iostream>
#include "file.h"
#include "tensor.h"

using namespace std;
using namespace tens;

int main(){

	ifstream fin;

	open_file_f( fin, "input.dat" );

	sym_tensor2 tens1, tens2;
	vector<string> vecstr;
	string ss;

	readline( fin, ss );
	vecstr = split( ss, ' ' );
	for( int i=0; i< 6; i++ ){
		tens1(i) = str_to_num<double>( vecstr[i] );
	}
	readline( fin, ss );
	vecstr = split( ss, ' ' );
	for( int i=0; i< 6; i++ ){
		tens2(i) = str_to_num<double>( vecstr[i] );
	}

	cout << "tens1:" << endl;
	tens1.show();
	cout << "tens2:" << endl;
	tens2.show();
	

	return 0;
}