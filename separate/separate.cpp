#include "sym_tensor2.h"

int main(){
	sym_tensor2 tens1 = { 1.0, 2.0, 0.8, 0.1, 0.0, 0.0 };
	sym_tensor2 tens2 = { 1.2, 1.8, 1.0, 0.2, 0.0, 0.0 };
	cout << "tens1:" << endl;
	tens1.show();
	cout << "tens2:" << endl;
	tens2.show();
	cout << "tens1:tens2=" << tens1.dbdot_prdct(tens2) << endl;
	cout << "tr(tens1) = " << tens1.trace() << endl;
	cout << "norm(tens1)=" << tens1.norm() << endl;
	cout << "deviatoric(tens1):" << endl;
	tens1.deviatoric().show();
	cout << "p(tens1)=" << tens1.p() << endl;
	cout << "s(tens1):" << endl;
	tens1.s().show();
	cout << "q(tens1)=" << tens1.q() << endl;

	return 0;
}