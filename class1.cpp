#include <iostream>
#include <iomanip>
using namespace std;

class vector3{
public:
	double elem[3];
	void set( const double e1, const double e2, const double e3 );
	void show();	
};

int main(){
	vector3 vec;
	vec.set( 1.0, 2.5, 3.0 );
	vec.show();

	return 0;
}

void vector3::set( const double e1, const double e2, const double e3 ){
	elem[0] = e1;
	elem[1] = e2;
	elem[2] = e3;
}

void vector3::show(){
	cout << scientific << setprecision(3);
	for( int i=0; i< 3; i++ ){
		cout << setw(5) << i << ": " << setw(12) << elem[i] << endl;
	}
}