#include <iostream>
#include <cmath>

using namespace std;


int main() {
	int H, W, N, M;
	cin >> H >> W >> N >> M;

	int a = (H / (N + 1));
	int b = (W / (M + 1));

	if ((H % (N + 1)))
		a++;
	if (W % (M + 1))
		b++;

	cout << a*b;

	return 0;
}
