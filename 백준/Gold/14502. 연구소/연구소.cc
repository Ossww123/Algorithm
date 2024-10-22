#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring> // memset을 위해 추가

using namespace std;

const int MAX_N = 8;
int N, M;
int lab[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int copyLab[MAX_N][MAX_N];  // BFS에서 사용할 복사본

const int DY[4] = { 0, 0, 1, -1 };
const int DX[4] = { 1, -1, 0, 0 };

int max_value = 0;

// BFS를 위한 좌표 구조체
struct Point {
    int y, x;
    Point(int y, int x) : y(y), x(x) {}
};

int BFS() {
    queue<Point> q;
    memset(visited, false, sizeof(visited));

    // lab 배열 복사
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            copyLab[i][j] = lab[i][j];

    // 바이러스 위치 찾아서 큐에 삽입
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (copyLab[i][j] == 2) {
                q.push(Point(i, j));
                visited[i][j] = true;
            }
        }
    }

    // 바이러스 퍼뜨리기
    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.y + DY[i];
            int nx = cur.x + DX[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;
            if (copyLab[ny][nx] != 0 || visited[ny][nx])
                continue;

            copyLab[ny][nx] = 2;
            q.push(Point(ny, nx));
            visited[ny][nx] = true;
        }
    }

    // 안전 영역 크기 계산
    int safe_area = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (copyLab[i][j] == 0) {
                safe_area++;
            }
        }
    }

    return safe_area;
}

void solve(int wall_cnt) {
    if (wall_cnt == 3) {
        max_value = max(max_value, BFS());
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (lab[i][j] == 0) {  // 빈 공간일 때만 벽을 세울 수 있음
                lab[i][j] = 1;  // 벽 설치
                solve(wall_cnt + 1);
                lab[i][j] = 0;  // 벽 제거
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> lab[i][j];
        }
    }

    solve(0);  // 벽 개수 0부터 시작

    cout << max_value << endl;  // 최대 안전 영역 크기 출력
    return 0;
}