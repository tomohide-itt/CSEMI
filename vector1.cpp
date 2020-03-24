#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> v1;	//空のint型ベクトル
	vector<int> v2 = { 1, 2, 3 };	//メンバイニシャライザ
	cout << "size of v1 = " << v1.size() << endl;
	cout << "size of v2 = " << v2.size() << endl;
	vector<int> v3(5); //サイズ5のint型ベクトル
	vector<int> v4 = v2;	//コピーコンストラクタによる生成
	cout << "size of v3 = " << v3.size() << endl;
	cout << "size of v4 = " << v4.size() << endl;
	vector<int> v5(5, 3);	//サイズ5のint型ベクトルを生成し，すべての要素を3とする．

	return 0;
}