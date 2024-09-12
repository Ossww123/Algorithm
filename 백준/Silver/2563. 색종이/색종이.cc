#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000000

using namespace std;

int main()
{
	int N;

	cin >> N;
	vector<vector<int>> array(100, vector<int>(100));

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			array[i][j] = 0;
		}
	}
	
	int c, d;
	for (int i = 0; i < N; i++) {
		cin >> c >> d;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				array[c + j][d + k] = 1;
			}
		}
	}

	int cnt = 0;

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (array[i][j] == 1) {
				cnt++;
			}
		}
	}

	cout << cnt << endl;

	return 0;
}