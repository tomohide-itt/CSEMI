#include <iostream>
#include <string>
using namespace std;

struct PC{
	string name;	//PC名
	int year;	//購入した年
	string user;	//使用者
};

PC entry( const string name, const int year, const string user );
void change_user( PC* pc, const string new_user );
void disp_pc( const PC pc );

int main(){
	PC pc1, pc2; //2個の構造体変数を宣言

	pc1 = entry( "pc1", 2012, "sato" );
	pc2 = entry( "pc2", 2015, "suzuki" );

	disp_pc( pc1 );	//pc1の内容を表示
	disp_pc( pc2 ); //pc2の内容を表示
	change_user( &pc2, "takahashi" );	//pc2の使用者を変更
	disp_pc( pc2 ); //pc2の内容を再表示して使用者変更を確認

	return 0;
}

PC entry( const string name, const int year, const string user ){
	PC pc;
	pc.name = name;
	pc.year = year;
	pc.user = user;
	return pc;
}

void change_user( PC* pc, const string new_user ){
	pc->user = new_user;
}

void disp_pc( const PC pc ){
	cout << "----------------------" << endl;
	cout << "name: " << pc.name << ", "
		 << "year: " << pc.year << ", "
		 << "user: " << pc.user << endl;
	cout << "----------------------" << endl;
}