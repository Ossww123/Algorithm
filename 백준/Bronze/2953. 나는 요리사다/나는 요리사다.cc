#include <iostream>

using namespace std;

int main(){
	int winner = 0;
	int max_score = 0;
	int total_score;

	for (int i = 0; i < 5; i++) {
		total_score = 0;
		for (int j = 0; j < 4; j++) {
			int score;
			cin >> score;
			total_score += score;
		}

		if (total_score > max_score) {
			winner = i + 1;
			max_score = total_score;
		}
	}

	cout << winner << ' ' << max_score << endl;
}