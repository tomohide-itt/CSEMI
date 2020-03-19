#include <iostream>
#include <iomanip>
#include <new>
using namespace std;

class vector3{
public:
	double elem[3];
	void set( double e1, double e2, double e3 );
	void show();	
};

int main(){
	vector3* vecs = new vector3[3];
	vecs[0].set( 1.0, 2.5, 3.0 );
	vecs[1].set( 2.0, 5.0, 6.0 );
	vecs[2].set( 3.0, 6.0, 7.0 );
	for( int i=0; i< 3; i++ ){
		cout << "vecs[" << i << "]=" << endl;
		vecs[i].show();
	}

	return 0;
}

void vector3::set( double e1, double e2, double e3 ){
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