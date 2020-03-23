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
	void show( std::ostream& stream=std::cout, int width=15, int dec=5 );
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
void sym_tensor2::show( std::ostream& stream, int width, int dec ){
	stream << scientific << setprecision( dec );
	stream << "0: " << setw(width) << elem[0] << std::endl;
	stream << "1: " << setw(width) << elem[1] << std::endl;
	stream << "2: " << setw(width) << elem[2] << std::endl;
	stream << "3: " << setw(width) << elem[3] << std::endl;
	stream << "4: " << setw(width) << elem[4] << std::endl;
	stream << "5: " << setw(width) << elem[5] << std::endl;
	stream.unsetf( std::ios::scientific );
}

//----------------------------------------------------------------------
int main(){
	//sym_tensor2のインスタンスtens1を作成
	sym_tensor2 tens1;
	//()演算子を使ってtens1の各要素に値を代入
	tens1(0) = 1.0; tens1(1) = 2.0; tens1(2) = 0.8; tens1(3) = 0.1; tens1(4) = tens1(5) = 0.0;
	//コピーコンストラクタ
	sym_tensor2 tens2 = tens1;
	//tens1表示（デフォルトの引数を使用）
	cout << "tens1:" << endl;
	tens1.show();
	//tens2表示（桁数12, 小数点以下3桁を指定）
	cout << "tens2:" << endl;
	tens2.show( cout, 12, 3 );
	//()を使ってtens2の各要素を変更
	tens2(0) = 1.2; tens2(1) = 1.8; tens2(2) = 1.0; tens2(3) = 0.2;
	//インスタンスtens3の作成
	sym_tensor2 tens3;
	//=演算子を使ってtens3にtens2を代入
	tens3 = tens2;
	//tens3表示
	cout << "tens3:" << endl;
	tens3.show();

	return 0;
}