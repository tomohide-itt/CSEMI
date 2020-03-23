#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class vector3{
public:
	double elem[3];
	vector3();	//コンストラクタ
	vector3( const double val ); //オーバーロードされたコンストラクタ2
	vector3( const vector3& vec );	//コピーコンストラクタ
	~vector3(){ cout << "vector3::destructor(" << this << ")" << endl; } //デストラクタ
	vector3& operator=( const vector3& vec );	//代入演算子のオーバーロード
	void set( const double e1, const double e2, const double e3 );
	void show();
};

vector3 operator+( const vector3& vec1, const vector3& vec2 );

int main(){
	vector3 vec1;
	vec1.set( 1.0, 2.0, 3.0 );
	vec1.elem[0] = 4.0;	//vec1の0番目要素に4.0を代入
	cout << vec1.elem[2] << endl;	//vec1の2番目の要素を出力
	return 0;
}

//コンストラクタの定義
vector3::vector3(){
	elem[0] = elem[1] = elem[2] = 0.0;	//要素を0で初期化
	cout << "vector3::constructor(" << this << ")" << endl;	//コンストラクタとしての機能として必要ないが呼び出されたことを確認するため
}

//コンストラクタ2の定義
vector3::vector3( const double val ){
	elem[0] = elem[1] = elem[2] = val;	//要素をvalで初期化
	cout << "vector3::constructor2(" << this << ")" << endl;
}

//コピーコンストラクタ
vector3::vector3( const vector3& vec ){
	for( int i=0; i< 3; i++ ) elem[i] = vec.elem[i];
	cout << "vector3::copy(" << &vec << ") -> (" << this << ")" << endl;
}

//代入演算子のオーバーロード
vector3& vector3::operator=( const vector3& vec ){
	for( int i=0; i< 3; i++ ) elem[i] = vec.elem[i];
	cout << "vector3::=(" << &vec << ") -> (" << this << ")" << endl;
	return *this;
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

//+演算子のオーバーロード
vector3 operator+( const vector3& vec1, const vector3& vec2 ){
	vector3 ret;
	for( int i=0; i< 3; i++ ){
		ret.elem[i] = vec1.elem[i] + vec2.elem[i];
	}
	return ret;
}