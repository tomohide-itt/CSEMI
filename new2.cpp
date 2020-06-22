#include <iostream>
#include <fstream>
#include <string>
#include <new>
using namespace std;

void open_file_m( ifstream& fp, const string message, ios_base::openmode mode = ios_base::in );
void least_squares( const int n, const double* x, const double* y, double* a, double* b );

int main(){
	ifstream fin;

	//ファイルを開く
	open_file_m( fin, "input file name>> " );

	//プロットの個数を読み込む
	string ss;
	fin >> ss;
	int n = stoi(ss);

	//メモリの確保
	double* x = new double[n];
	double* y = new double[n];

	//プロットの座標を読み込む
	for( int i=0; i< n; i++ ){
		fin >> ss;
		x[i] = stod( ss );
		fin >> ss;
		y[i] = stod( ss );
	}

	//傾き，切片を計算
	double a, b;
	least_squares( n, x, y, &a, &b );

	//結果の表示
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;

	//ファイルを閉じる
	fin.close();

	//メモリの解放
	delete[] x;
	delete[] y;

	return 0;
}

void open_file_m( ifstream& fp, const string message, ios_base::openmode mode ){
	string fname;
	cout << message << endl;
	cin >> fname;
	fp.open( fname, mode );
	if( !fp ){
		cout << fname << "was not opened." << endl;
	}
}

void least_squares( const int n, const double* x, const double* y, double* a, double* b ){
	double A=0.0, B=0.0, C=0.0, D=0.0;

	//x^2
	for( int i=0; i< n; i++ ) A += x[i]*x[i];
	//x
	for( int i=0; i< n; i++ ) B += x[i];
	//xy
	for( int i=0; i< n; i++ ) C += x[i]*y[i];
	//y
	for( int i=0; i< n; i++ ) D += y[i];

	*a = (n*C - B*D)/(n*A - B*B);
	*b = (D - B*(*a))/n;
}