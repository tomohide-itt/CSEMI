#include <iostream>
#include <string>
using namespace std;

int main(){
	int a, b;
	string ssa, ssb;

	cin >> ssa;
	cin >> ssb;
	a = stoi( ssa );
	b = stoi( ssb );
	cout << a+b << endl;

	return 0;
}