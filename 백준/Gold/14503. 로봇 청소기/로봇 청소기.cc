#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int DY[4] = { -1,0,1,0 }; // 북, 동, 남, 서 방향
int DX[4] = { 0,1,0,-1 };

int main() {
    int N, M;
    cin >> N >> M;

    int R, C, D;
    cin >> R >> C >> D;

    vector<vector<int>> room(N, vector<int>(M));
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> room[y][x];
        }
    }

    int cnt = 0;
    int cy = R;
    int cx = C;
    int cd = D;

    while (1) {
        // 1. 현재 칸이 청소되지 않은 경우
        if (room[cy][cx] == 0) {
            cnt++;
            room[cy][cx] = 2; // 청소된 칸
        }

        bool cleaned = false;

        // 2. 주변 4칸을 확인
        for (int i = 0; i < 4; i++) {
            // 반시계 방향으로 90도 회전
            cd = (cd + 3) % 4;

            int ny = cy + DY[cd];
            int nx = cx + DX[cd];

            // 청소되지 않은 칸인지 확인
            if (ny >= 0 && ny < N && nx >= 0 && nx < M && room[ny][nx] == 0) {
                cy = ny;
                cx = nx;
                cleaned = true;
                break;
            }
        }

        // 3. 주변 4칸이 모두 청소됐거나 벽인 경우
        if (!cleaned) {
            // 후진 방향 계산
            int backDir = (cd + 2) % 4;
            int ny = cy + DY[backDir];
            int nx = cx + DX[backDir];

            // 후진할 수 있는지 확인
            if (ny >= 0 && ny < N && nx >= 0 && nx < M && room[ny][nx] != 1) {
                cy = ny;
                cx = nx;
            }
            else {
                // 후진도 할 수 없으면 작동 중지
                break;
            }
        }
    }

    cout << cnt;
    return 0;
}