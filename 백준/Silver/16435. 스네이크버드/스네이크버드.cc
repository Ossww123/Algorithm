#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int DY[4] = { -1,0,1,0 }; // 북, 동, 남, 서 방향
int DX[4] = { 0,1,0,-1 };


int main() {
    int N, L;
    cin >> N >> L;

    vector<int> fruits(20005);
    for (int i = 0; i < N; i++) {
        int H;
        cin >> H;
        fruits[H]++;
    }
    
    int curr_length = L;
    int curr_height = 1;
    while (curr_length >= curr_height) {
        curr_length += fruits[curr_height];
        curr_height++;
    }

    cout << curr_length;

    return 0;
}