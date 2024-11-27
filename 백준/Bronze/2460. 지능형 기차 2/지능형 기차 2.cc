#include <iostream>

using namespace std;


int main() {
	int curr = 0;
	int max_num = 0;
	for (int i = 0; i < 10; i++) {
		int a, b;
		cin >> a >> b;
		curr = curr + b - a;
		if (curr > max_num) {
			max_num = curr;
		}
	}

	cout << max_num;

	return 0;
}
