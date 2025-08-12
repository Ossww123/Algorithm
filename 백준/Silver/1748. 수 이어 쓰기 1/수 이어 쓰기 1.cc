#include <iostream>
using std::cin;
using std::cout;

#include <algorithm>
using std::max;

typedef long long ll;

int main() {
	ll ans = 0;
	// 1 ~ 9 : 1
	// 10 ~ 99 : 2
	// 100 ~ 999 : 3
	// ...
	// 100,000,000 : 9

	int temp = 999999999;
	int temp2 = 10;

	int N;
	cin >> N;

	while (N > 0) {
		ans = ans + max(N - temp, 0) * temp2--;
		if(N > temp) N = temp;
		temp /= 10;
	}

	cout << ans;
	
	return 0;
}