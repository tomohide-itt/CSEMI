#include <iostream>
#include <iomanip>
#include <initializer_list>
#include <cmath>
using namespace std;

template< typename T, int sz >
class mvector{
private:
	T elem[sz];
public:
	mvector();
	mvector( initializer_list<T> init );
	mvector( const mvector& vec );
	mvector& operator=( const mvector& vec );
	void show() const;
	T operator[]( const int i ) const;
	T& operator[]( const int i );
};

//コンストラクタ
template< typename T, int sz >
mvector<T,sz>::mvector(){
	for( int i=0; i< sz; i++ ) elem[i] = 0;
}

//メンバイニシャライザ
template< typename T, int sz >
mvector<T,sz>::mvector( initializer_list<T> init ){
	for( int i=0; i< sz; i++ ){
		elem[i] = *( init.begin() + i );
	}
}

//コピーコンストラクタ
template< typename T, int sz >
mvector<T,sz>::mvector( const mvector<T,sz>& vec ){
	for( int i=0; i< sz; i++ ) elem[i] = vec.elem[i];
}

//代入演算子のオーバーロード
template< typename T, int sz >
mvector<T,sz>& mvector<T,sz>::operator=( const mvector<T,sz>& vec ){
	for( int i=0; i< sz; i++ ) elem[i] = vec.elem[i];
	return *this;
}

//表示関数
template< typename T, int sz >
void mvector<T,sz>::show() const{
	cout << scientific << setprecision(3);
	for( int i=0; i< sz; i++ ){
		cout << setw(5) << i << ": " << setw(12) << elem[i] << endl;
	}
}

//[]を使った要素の値の取得
template< typename T, int sz >
T mvector<T,sz>::operator[]( const int i ) const{
	if( i < 0 || i >= sz ){
		cout << "mvector::[] : Access Violation (index = " << i << " )" << endl;
	}
	return elem[i];
}

//[]を使った要素の値の設定
template< typename T, int sz >
T& mvector<T,sz>::operator[]( const int i ){
	if( i < 0 || i >= sz ){
		cout << "mvector::[] : Access Violation (index = " << i << " )" << endl;
	}
	return elem[i];
}


//----- main --------------------------------------------------
int main(){
	mvector<int,2>    vec_i2 = {1, 2};
	mvector<double,4> vec_d4 = {0.5, 1.5, 2.5, 3.5};

	cout << "vec_i2:" << endl;
	vec_i2.show();
	cout << "vec_d4:" << endl;
	vec_d4.show();
	
	return 0;
}