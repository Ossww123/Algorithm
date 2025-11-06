#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<vector<int>> win(n + 1, vector<int>(n + 1, 0));
    
    for (const auto& r : results) {
        int a = r[0], b = r[1];
        win[a][b] = 1;
    }
    
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            if (i == k) continue;
            if (!win[i][k]) continue;
            for (int j = 1; j <= n; ++j) {
                if (win[i][j]) continue;
                if (win[k][j]) win[i][j] = 1;
            }
        }
    }
    
    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        int known = 0;
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            if (win[i][j] || win[j][i]) ++known;
        }
        if (known == n - 1) ++answer;
    }
    return answer;
}
