#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

template<typename T>
vector<string> split( const string& str, const T& sep ){
	vector<string> vecstr;
	string sub_str = "";
	int cnt = 0;
	while( cnt <= str.size() ){
		char c = str[cnt];	//strから一文字取り出す
		if( c == sep || cnt == str.size() ){	//cがsepと同じかstrの最後の文字だった場合
			if( !sub_str.empty() ){	//sub_strが空の文字列でなかったら
				vecstr.push_back( sub_str );	//vecstrにsub_strを追加する
				sub_str.clear();	//sub_strを空の文字列にする
			}
		}else{	//cがsepでもないし，strの最後の文字でもなかった場合
			sub_str += c;	//sub_strにcを連結
		}
		cnt++;
	}
	return vecstr;
}

int main(){
	string str_in = "aa bbb cc    ddd";
	vector<string> vecstr;
	vecstr = split( str_in, ' ' );
	for( int i=0; i< vecstr.size(); i++ ){
		cout << i << ": " << vecstr[i] << endl;
	}

	return 0;
}