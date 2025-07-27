#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::pair;

#include <string>
using std::string;

#include <algorithm>
using std::fill;
using std::max;
using std::min;
using std::find;

#include <vector>
using std::vector;

#include <queue>
using std::queue;

int DY[4] = { 1, -1, 0, 0 };
int DX[4] = { 0, 0, -1, 1 };

int N;
int diff;

int ability[21][21];
bool visited[21];

vector<int> l_team;
vector<int> r_team;

void cal_ability() {
    for (int i = 0; i < N; ++i) {
        if (!visited[i])
            r_team.push_back(i);
    }

    int l_team_pow = 0;
    int r_team_pow = 0;

    for (int i = 0; i < N / 2; ++i) {
        for (int j = 0; j < N / 2; ++j) {
            if (i != j) {
                l_team_pow += ability[l_team[i]][l_team[j]];
                r_team_pow += ability[r_team[i]][r_team[j]];
            }
        }
    }

    diff = min(diff, abs(l_team_pow - r_team_pow));

    while (!r_team.empty())
        r_team.pop_back();
}

void devide_team(int idx = 0, int start = 0) {
    if (diff == 0) return;

    if (N / 2 == idx) {
        cal_ability();
        return;
    }

    if (N - start < N / 2 - idx) return;

    for (int i = start; i < N; ++i) {
        if (!visited[i]) {
            l_team.push_back(i);
            visited[i] = true;
            devide_team(idx + 1, i + 1);
            l_team.pop_back();
            visited[i] = false;
        }
    }
}

int main()
{
    cin >> N;
    diff = 0xFFFFFF;
    fill(visited, visited + 21, false);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> ability[i][j];
        }
    }

    devide_team();

    cout << diff;

    return 0;
}