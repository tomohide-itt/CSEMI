#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
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

	double dbdot_prdct( const sym_tensor2& t ) const;
	double trace() const;
	double norm() const;
	sym_tensor2 deviatoric() const;

	double p() const;
	sym_tensor2 s() const;
	double q() const;
};

sym_tensor2 operator +( const sym_tensor2& t1, const sym_tensor2& t2 );
sym_tensor2 operator -( const sym_tensor2& t1, const sym_tensor2& t2 );
sym_tensor2 operator *( const double s, const sym_tensor2& t );
sym_tensor2 operator *( const sym_tensor2& t, const double s );
sym_tensor2 operator /( const sym_tensor2& t, const double s );