#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>  // LLONG_MAX, LONG_MAX 등을 사용하기 위해

using namespace std;

struct Stock {
	long value;
	int left;
	int right;
};

int main() {
	int N;
	cin >> N;

	vector<long> liquid(N);  // liquid 벡터 크기 설정
	for (int i = 0; i < N; i++) {
		cin >> liquid[i];
	}

	vector<Stock> result(N - 1);

	for (int i = 0; i < N - 1; i++) {
		long curr = LLONG_MAX;  // 현재 값의 초기화, LLONG_MAX로 설정
		int left = i + 1;
		int right = N - 1;
		int mid = (left + right) / 2;

		// 처음 mid 값을 계산
		long temp_two_plus = liquid[i] + liquid[mid];
		Stock p1;
		p1.value = abs(temp_two_plus);
		p1.left = i;
		p1.right = mid;

		while (left <= right) {
			mid = (left + right) / 2;
			temp_two_plus = liquid[i] + liquid[mid];

			// 더 작은 값을 찾으면 업데이트
			if (abs(temp_two_plus) < p1.value) {
				p1.value = abs(temp_two_plus);
				p1.left = i;
				p1.right = mid;
			}

			// 이동 방향 설정
			if (temp_two_plus < 0) {
				left = mid + 1;
			}
			else if (temp_two_plus == 0) {
				break;
			}
			else {
				right = mid - 1;
			}
		}

		result[i] = p1;
	}

	// result에서 가장 작은 value를 가진 원소 찾기
	Stock minStock = *min_element(result.begin(), result.end(), [](const Stock& a, const Stock& b) {
		return a.value < b.value;
	});

	cout << liquid[minStock.left] << ' ' << liquid[minStock.right] << endl;

	return 0;
}
