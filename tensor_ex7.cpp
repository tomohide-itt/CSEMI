#include <iostream>
#include <iomanip>
#include <initializer_list>
using namespace std;

class sym_tensor2{
private:
	double elem[6];
public:
	sym_tensor2(){};	//コンストラクタ：何もしない
	sym_tensor2( std::initializer_list<double> init );	//メンバイニシャライザ
	sym_tensor2( const sym_tensor2& t );	//コピーコンストラクタ
	sym_tensor2& operator=( const sym_tensor2& t );	//=演算子
	double operator()( const int i ) const;	//取得用()演算子
	double& operator()( const int i );	//設定用()演算子
	void show( std::ostream& stream=std::cout, int width=15, int dec=5 ) const;
	static sym_tensor2 delta();

	sym_tensor2& operator+=( const sym_tensor2& t );
	sym_tensor2& operator+=( const double s );
	sym_tensor2& operator-=( const sym_tensor2& t );
	sym_tensor2& operator-=( const double s );
	sym_tensor2& operator*=( const double s );
	sym_tensor2& operator/=( const double s );
	sym_tensor2 operator-() const;
	bool operator ==( const sym_tensor2& t ) const;
	bool operator !=( const sym_tensor2& t ) const;

};

//コピーコンストラクタ
sym_tensor2::sym_tensor2( const sym_tensor2& t ){
	for( int i=0; i< 6; i++ ) elem[i] = t.elem[i];
}

//メンバイニシャライザ
sym_tensor2::sym_tensor2( std::initializer_list<double> init ){
	for( int i=0; i< 6; i++ ){
		elem[i] = *( init.begin() + i );
	}
}

//=演算子
sym_tensor2& sym_tensor2::operator=( const sym_tensor2& t ){
	for( int i=0; i< 6; i++ ) elem[i] = t.elem[i];
	return *this;
}

//()演算子
double sym_tensor2::operator()( const int i ) const{
	if( i < 0 || i >= 6 ) cout << "sym_tensor2::() :Access violation ( " << i << ")" << endl;
	return elem[i];
}

double& sym_tensor2::operator()( const int i ){
	if( i < 0 || i >= 6 ) cout << "sym_tensor2::() :Access violation ( " << i << ")" << endl;
	return elem[i];	
}

//show関数
void sym_tensor2::show( std::ostream& stream, int width, int dec ) const{
	stream << scientific << setprecision( dec );
	stream << "0: " << setw(width) << elem[0] << std::endl;
	stream << "1: " << setw(width) << elem[1] << std::endl;
	stream << "2: " << setw(width) << elem[2] << std::endl;
	stream << "3: " << setw(width) << elem[3] << std::endl;
	stream << "4: " << setw(width) << elem[4] << std::endl;
	stream << "5: " << setw(width) << elem[5] << std::endl;
	stream.unsetf( std::ios::scientific );
}

sym_tensor2 sym_tensor2::delta(){
	sym_tensor2 del;
	del(0) = del(1) = del(2) = 1.0;
	del(3) = del(4) = del(5) = 0.0;
	return del;
}

sym_tensor2& sym_tensor2::operator+=( const sym_tensor2& t ){
	for( int i=0; i< 6; i++ ) elem[i] += t(i);
	return *this;
}

sym_tensor2& sym_tensor2::operator+=( const double s ){
	for( int i=0; i< 6; i++ ) elem[i] += s;
	return *this;
}

sym_tensor2& sym_tensor2::operator-=( const sym_tensor2& t ){
	for( int i=0; i< 6; i++ ) elem[i] -= t(i);
	return *this;
}

sym_tensor2& sym_tensor2::operator-=( const double s ){
	for( int i=0; i< 6; i++ ) elem[i] -= s;
	return *this;
}

sym_tensor2& sym_tensor2::operator*=( const double s ){
	for( int i=0; i< 6; i++ ) elem[i] *= s;
	return *this;
}

sym_tensor2& sym_tensor2::operator/=( const double s ){
	for( int i=0; i< 6; i++ ) elem[i] /= s;
	return *this;
}

sym_tensor2 sym_tensor2::operator-() const{
	sym_tensor2 ret;
	for( int i=0; i< 6; i++ ) ret(i) = -elem[i];
	return ret;
}

bool sym_tensor2::operator ==( const sym_tensor2& t ) const{
	bool ret = true;
	for( int i=0; i< 6; i++ ){
		if( elem[i] != t(i) ) ret = false;
	}
	return ret;
}

bool sym_tensor2::operator !=( const sym_tensor2& t ) const{
	return !( *this == t );
}

sym_tensor2 operator +( const sym_tensor2& t1, const sym_tensor2& t2 ){
	sym_tensor2 ret;
	for( int i=0; i< 6; i++ ){
		ret(i) = t1(i) + t2(i);
	}
	return ret;
}

sym_tensor2 operator -( const sym_tensor2& t1, const sym_tensor2& t2 ){
	sym_tensor2 ret;
	for( int i=0; i< 6; i++ ){
		ret(i) = t1(i) - t2(i);
	}
	return ret;
}

sym_tensor2 operator *( const double s, const sym_tensor2& t ){
	sym_tensor2 ret;
	for( int i=0; i< 6; i++ ){
		ret(i) = s*t(i);
	}
	return ret;
}

sym_tensor2 operator *( const sym_tensor2& t, const double s ){
	sym_tensor2 ret;
	for( int i=0; i< 6; i++ ){
		ret(i) = s*t(i);
	}
	return ret;
}

sym_tensor2 operator /( const sym_tensor2& t, const double s ){
	sym_tensor2 ret;
	for( int i=0; i< 6; i++ ){
		ret(i) = t(i)/s;
	}
	return ret;
}


//----------------------------------------------------------------------
int main(){
	sym_tensor2 tens1 = { 1.0, 2.0, 0.8, 0.1, 0.0, 0.0 };
	sym_tensor2 tens2 = { 1.2, 1.8, 1.0, 0.2, 0.0, 0.0 };
	cout << "tens1:" << endl;
	tens1.show();
	cout << "tens2:" << endl;
	tens2.show();
	cout << "tens1 += tens2" << endl;
	tens1 += tens2;
	tens1.show();
	cout << "tens1 += 1.0" << endl;
	tens1 += 1.0;
	tens1.show();
	cout << "tens1 -= tens2" << endl;
	tens1 -= tens2;
	tens1.show();
	cout << "tens1 -= 1.0" << endl;
	tens1 -= 1.0;
	tens1.show();
	cout << "tens1 *= 2.0" << endl;
	tens1 *= 2.0;
	tens1.show();
	cout << "tens1 /= 2.0" << endl;
	tens1 /= 2.0;
	tens1.show();
	cout << "-tens1" << endl;
	(-tens1).show();
	cout << "tens1 == tens2? :" << (tens1 == tens2) << endl;
	cout << "tens1 != tens2? :" << (tens1 != tens2) << endl;
	cout << "tens1 + tens2" << endl;
	(tens1+tens2).show();
	cout << "tens1 - tens2" << endl;
	(tens1-tens2).show();
	cout << "2.0*tens1" << endl;
	(2.0*tens1).show();
	cout << "tens1*0.5" << endl;
	(tens1*0.5).show();
	cout << "tens1/2.0" << endl;
	(tens1/2.0).show();

	return 0;
}