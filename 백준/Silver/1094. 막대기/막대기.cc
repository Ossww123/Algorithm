#include <iostream>

using namespace std;

int countOnes(int n) {
	int count = 0;
	while (n > 0) {
		count += (n & 1); // 마지막 비트가 1인지 체크
		n >>= 1;          // 오른쪽으로 1비트 이동
	}
	return count;
}

int main() {
	int X;
	cin >> X;

	int result = countOnes(X); // 이진수에서 1의 개수 세기

	cout << result << endl; // 결과 출력

	return 0;
}
