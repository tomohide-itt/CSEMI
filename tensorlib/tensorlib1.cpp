#include <iostream>
#include "tensor.h"
using namespace std;
using namespace tens;

int main(){
	//tensor1クラス ----------------------------------------------------
	tensor1 vec1 = tensor1::zero();	//vec1をゼロベクトルにする
	cout << "vec1: ";
	vec1.show_in_mat();	//vec1をマトリクス形式で表示

	vec1(0)=1.0; vec1(1)=2.0; vec1(2)=3.0;	//()演算子を使ってvec1に値を代入
	cout << "vec1: ";
	vec1.show_in_mat();	//vec1をマトリクス形式で表示

	tensor1 vec2 = { 4.0, 5.0, 6.0 };	//メンバイニシャライザを使ってvec2を初期化
	cout << "vec2: ";
	vec2.show_in_mat();	//vec2をマトリクス形式で表示

	cout << "vec1.dot_prdct(vec2) = " << vec1.dot_prdct(vec2) << endl;	//内積
	cout << "vec1.norm() = " << vec1.norm() << endl;	//ノルム

	tensor1 vec3 = vec1.vec_prdct(vec2);	//外積
	cout << "vec1.vec_prdct(vec2): ";
	vec3.show_in_mat();	//vec3をマトリクス形式で表示

	//sym_tensor2クラス -----------------------------------------------
	sym_tensor2 del = sym_tensor2::delta();	//クロネッカーのデルタを作成
	cout << "del:" << endl;
	del.show_in_mat();	//delをマトリクス形式で表示

	sym_tensor2 sig = { 1.0, 2.0, 3.0, -0.1, 0.2, 0.1 };	//メンバイニシャライザを使ってsigを初期化
	cout << "sig:" << endl;
	sig.show_in_mat(); //sigをマトリクス形式で表示

	cout << "p = " << sig.p() << endl;	//平均主応力
	cout << "s: " << endl;
	sig.s().show_in_mat();	//偏差応力テンソルをマトリクス形式で表示
	cout << "q = " << sig.q() << endl; //偏差応力

	//sym_tensor4クラス -----------------------------------------------
	sym_tensor4 idn = sym_tensor4::idn();	//4階恒等テンソルを作成 I
	sym_tensor4 dev4 = idn - 1.0/3.0*del.tens_prdct(del);	//4階偏差テンソル A
	sym_tensor2 s = dev4.dbdot_prdct( sig );	//偏差応力テンソル s = A:sig
	cout << "s: " << endl;
	s.show_in_mat();	//偏差応力テンソルをマトリクス形式で表示

	return 0;
}