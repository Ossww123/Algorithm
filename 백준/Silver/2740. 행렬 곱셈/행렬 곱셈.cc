#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int DY[4] = { -1,0,1,0 }; // 북, 동, 남, 서 방향
int DX[4] = { 0,1,0,-1 };


int main() {
    
    int N, M1;
    cin >> N >> M1;

    vector<vector<int>> matrix1(N, vector<int>(M1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M1; j++) {
            cin >> matrix1[i][j];
        }
    }

    int M2, K;
    cin >> M2 >> K;

    vector<vector<int>> matrix2(M2, vector<int>(K));
    for (int i = 0; i < M2; i++) {
        for (int j = 0; j < K; j++) {
            cin >> matrix2[i][j];
        }
    }

    vector<vector<int>> matrix3(N, vector<int>(K, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            for (int k = 0; k < M1; k++) {
                matrix3[i][j] += (matrix1[i][k] * matrix2[k][j]);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            cout << matrix3[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}