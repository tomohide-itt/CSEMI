#include <iostream>
#include <iomanip>
using namespace std;

class sym_tensor2{
private:
	double elem[6];
public:
	sym_tensor2(){};	//コンストラクタ：何もしない
	sym_tensor2( const sym_tensor2& t );	//コピーコンストラクタ
	sym_tensor2& operator=( const sym_tensor2& t );	//=演算子
	double operator()( const int i ) const;	//取得用()演算子
	double& operator()( const int i );	//設定用()演算子
	void show( std::ostream& stream=std::cout, int width=15, int dec=5 ) const;
	static sym_tensor2 delta();
};

//コピーコンストラクタ
sym_tensor2::sym_tensor2( const sym_tensor2& t ){
	for( int i=0; i< 6; i++ ) elem[i] = t.elem[i];
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

//----------------------------------------------------------------------
int main(){
	sym_tensor2 del = sym_tensor2::delta();
	del.show();

	return 0;
}