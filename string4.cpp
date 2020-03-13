#include <iostream>
#include <string>
using namespace std;

int main(){
	string str1 = "abc";
	string str2;
	string str3 = "def";

	str2 = str1;	//代入：str2にstr1を代入
	str1 += str3;	//連結：str1にstr3を連結，str1 = str1 + str3と同じ

	cout << str1 << endl;

	return 0;
}