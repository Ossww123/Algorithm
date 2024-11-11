#include <iostream>
#include <string>

using namespace std;

int main(){
	int N;
	cin >> N;

	string matrix[1000];

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		matrix[i] = temp;
	}

	int heartY, heartX;

	for (int i = 0; i < N; i++) {
		bool isFound = false;
		for (int j = 0; j < N; j++) {
			if (matrix[i][j] == '*') {
				heartY = i+1;
				heartX = j;
				isFound = true;
				break;
			}
		}
		if (isFound)
			break;
	}

	int leftArm = 0, rightArm = 0, body = 0, leftLeg = 0, rightLeg = 0;

	for (int j = heartX - 1;j >= 0; j--) {
		if (matrix[heartY][j] == '_')
			break;
		leftArm++;
	}

	for (int j = heartX + 1; j < N; j++) {
		if ( matrix[heartY][j] == '_')
			break;
		rightArm++;
	}

	for (int i = heartY + 1;i < N; i++) {
		if ( matrix[i][heartX] == '_')
			break;
		body++;
	}

	for (int i = heartY + body + 1;i < N; i++) {
		if ( matrix[i][heartX - 1] == '_')
			break;
		leftLeg++;
	}

	for (int i = heartY + body + 1;i < N; i++) {
		if (matrix[i][heartX + 1] == '_')
			break;
		rightLeg++;
	}
	

	cout << heartY+1 << ' ' << heartX+1 << endl;
	cout << leftArm << ' ' << rightArm << ' ' << body << ' ' << leftLeg << ' ' << rightLeg;
}