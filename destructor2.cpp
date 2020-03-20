#include <iostream>
#include <iomanip>
using namespace std;

class vector3{
public:
	double elem[3];
	vector3();	//コンストラクタ
	vector3( double val ); //オーバーロードされたコンストラクタ2
	~vector3(){ cout << "vector3::destructor(" << this << ")" << endl; } //デストラクタ
	void set( double e1, double e2, double e3 );
	void show();	
};

int main(){
	vector3 vec1;
	cout << "vec1" << endl;
	vec1.show();

	vector3 vec2( 3.0 );
	cout << "vec2" << endl;
	vec2.show();

	return 0;
}

//コンストラクタの定義
vector3::vector3(){
	elem[0] = elem[1] = elem[2] = 0.0;	//要素を0で初期化
	cout << "vector3::constructor(" << this << ")" << endl;	//コンストラクタとしての機能として必要ないが呼び出されたことを確認するため
}

//コンストラクタ2の定義
vector3::vector3( double val ){
	elem[0] = elem[1] = elem[2] = val;	//要素をvalで初期化
	cout << "vector3::constructor2(" << this << ")" << endl;
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