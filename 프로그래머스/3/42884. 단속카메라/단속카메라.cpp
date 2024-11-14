#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[1] == b[1]) {
            return a[0] < b[0]; // 두 번째 원소가 같으면 첫 번째 원소로 비교
        }
        return a[1] < b[1]; // 두 번째 원소 기준으로 비교
    });
    
    int curr = routes[0][1];
    answer++;
    
    if (routes.size() > 1 )
    for (int i=1; i<routes.size() ; i++){
        if(routes[i][0] > curr){
            curr = routes[i][1];
            answer++;
        }
    }
    
    return answer;
}