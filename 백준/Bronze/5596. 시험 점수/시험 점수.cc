#include <iostream>

using namespace std;

int main(){
	int a, b, aa = 0, bb = 0;

	for (int i = 0; i < 4; i++) {
		cin >> a;
		aa += a;
	}

	for (int i = 0; i < 4; i++) {
		cin >> b;
		bb += b;
	}

	int result = aa > bb ? aa : bb;

	cout << result;

}