#include <iostream>
#include <iomanip>
#include <initializer_list>
#include <cmath>
using namespace std;

template< typename T >
class vector3{
private:
	T elem[3];
public:
	vector3();
	vector3( initializer_list<T> init );
	vector3( const vector3& vec );
	vector3& operator=( const vector3& vec );
	void show() const;
	T operator[]( const int i ) const;
	T& operator[]( const int i );
};

//コンストラクタ
template< typename T >
vector3<T>::vector3(){
	for( int i=0; i<3; i++ ) elem[i] = 0.0;
}

//メンバイニシャライザ
template< typename T >
vector3<T>::vector3( initializer_list<T> init ){
	for( int i=0; i<3; i++ ){
		elem[i] = *( init.begin() + i );
	}
}

//コピーコンストラクタ
template< typename T >
vector3<T>::vector3( const vector3<T>& vec ){
	for( int i=0; i< 3; i++ ) elem[i] = vec.elem[i];
}

//代入演算子のオーバーロード
template< typename T >
vector3<T>& vector3<T>::operator=( const vector3<T>& vec ){
	for( int i=0; i< 3; i++ ) elem[i] = vec.elem[i];
	return *this;
}

template< typename T >
void vector3<T>::show() const{
	cout << scientific << setprecision(3);
	for( int i=0; i< 3; i++ ){
		cout << setw(5) << i << ": " << setw(12) << elem[i] << endl;
	}
}

//[]を使った要素の値の取得
template< typename T >
T vector3<T>::operator[]( const int i ) const{
	if( i < 0 || i >= 3 ){
		cout << "vector3::[] : Access Violation (index = " << i << " )" << endl;
	}
	return elem[i];
}

//[]を使った要素の値の設定
template< typename T >
T& vector3<T>::operator[]( const int i ){
	if( i < 0 || i >= 3 ){
		cout << "vector3::[] : Access Violation (index = " << i << " )" << endl;
	}
	return elem[i];
}

//----- main --------------------------------------------------
int main(){
	vector3<int> vec_i = { 1, 2, 3 };
	vector3<double> vec_d = { 1.5, 2.5, 3.5 };
	cout << "vec_i:" << endl;
	vec_i.show();
	cout << "vec_d:" << endl;
	vec_d.show();
	return 0;
}