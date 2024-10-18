#include <iostream>

using namespace std;


int main() {
	int k, result = 0;
	cin >> k;

	bool flag = false;
	while (k != 0) {
		if (k % 10 == 0) {
			if (flag) {
				result++;
				k /= 10;
			}
			else {
				k /= 10;
			}
		}
		else {
			flag = true;
			k /= 10;
		}
	}

	cout << result;

	return 0;
}
