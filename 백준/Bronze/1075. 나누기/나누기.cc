#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
	int N, F;
	cin >> N >> F;

	int remain = N % F;
	int curr = N % 100;

	// cout << remain << ' ' << curr << endl;

	int temp = curr - remain;
	if (temp < 0)
		temp += F;

	while (true) {
		if (temp - F < 0)
			break;
		temp -= F;
	}

	if (temp < 10)
		cout << '0' << temp;
	else
		cout << temp;


	return 0;
}