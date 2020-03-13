#include <iostream>
#include <string>
using namespace std;

int main(){
	string str1;			//からの文字列""で初期化
	string str2 = "abcdef";		//"abcdef"で初期化
	string str3("uvwxyz");		//"uvwxyz"で初期化
	string str4(5, 'a' );		//5個の'a'で初期化"aaaaa"となる
	string str5(str2);		//str2と同じ内容で初期化"abcdef"
	string str6(str2, 3);		//str2[3]以降の文字列で初期化"def"
	string str7( str2, 2, 3 );	//str2[2]から3文字分で初期化"cde"

	cout << str1 << endl << str2 << endl << str3 << endl
	<< str4 << endl << str5 << endl << str6 << endl << str7 << endl;

	return 0;
}