#include <iostream>
#include <vector>

using namespace std;

int main(){
	int H, W;
	cin >> H >> W;
	vector<vector<int>> blocks(H, vector<int>(W, 0));

	for (int i = 0; i < W; i++) {
		int height;
		cin >> height;

		for (int j = H - 1; j >= H - height; j--) {
			blocks[j][i] = 1;
		}
	}

	bool isLeftClosed;
	int total = 0;
	int cnt;

	for (int i = 0; i < H; i++) {
		isLeftClosed = false;
		cnt = 0;

		for (int j = 0; j < W; j++) {
			if (!isLeftClosed) {
				if (blocks[i][j] == 1) {
					isLeftClosed = true;
				}	
			}
			else {
				if (blocks[i][j] == 0) {
					cnt++;
				}
				else {
					total += cnt;
					cnt = 0;
				}
			}
		}
	}

	cout << total;

	return 0;
}