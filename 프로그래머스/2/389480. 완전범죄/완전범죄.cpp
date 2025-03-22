#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    int len =info.size();
    
    // DP[i] : n번째 물건까지 훔쳤을 때 b의 흔적개수가 i일때 a의 최소값
    vector<int> DP(m, 1e9);
    DP[0] = 0;
    vector<int> tempDP;
    
    for (int i=0;i<len;i++){
        tempDP = DP;
        int a = info[i][0];
        int b = info[i][1];
        int value;
        
        /*
        0 0
        0 1, 2 0
        0 3, 2 2, 3 1, 5 1e9
        0 5, 2 4, 3 3, 1 3, 3 2, 4 1
        */
        
            // a를 선택했을 경우
        for (int j=0;j<m;j++){
            if (tempDP[j] > 1e8) continue;
            
            value = tempDP[j] + a;
            if (value >= n) DP[j] = 1e9;
            else DP[j] = value;
        }
        
            // b를 선택했을 경우
        for (int j=0;j<m;j++){
            if (tempDP[j] > 1e8) continue;
            
            value = j+b;
            if (value >= m) continue;
            else DP[value] = min(DP[value], tempDP[j]);
        }
    }
    
    answer = *min_element(DP.begin(), DP.end());
    if (answer > 1e8) answer = -1;
    
    return answer;
}