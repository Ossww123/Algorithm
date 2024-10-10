#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int L, A, B, C, D;
	cin >> L >> A >> B >> C >> D;

	int korean_day = A / C;

	if (A % C != 0) {
		korean_day++;
	}

	int math_day = B / D;

	if (B % D != 0) {
		math_day++;
	}

	if (korean_day >= math_day) {
		cout << L - korean_day << endl;
	}
	else {
		cout << L - math_day << endl;
	}

	return 0;
}