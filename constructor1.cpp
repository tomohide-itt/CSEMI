#include <iostream>
#include <iomanip>
using namespace std;

class vector3{
public:
	double elem[3];
	vector3();	//コンストラクタ
	void set( const double e1, const double e2, const double e3 );
	void show();	
};

int main(){
	vector3 vec; //この時点でコンストラクタが呼ばれる．
	vec.show();
	vec.set( 1.0, 2.0, 3.0 );
	cout << "after setting the elements of vector" << endl;
	vec.show();

	return 0;
}

//コンストラクタの定義
vector3::vector3(){
	elem[0] = elem[1] = elem[2] = 0.0;	//要素を0で初期化
	cout << "vector3::constructor" << endl;	//コンストラクタとしての機能として必要ないが呼び出されたことを確認するため
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