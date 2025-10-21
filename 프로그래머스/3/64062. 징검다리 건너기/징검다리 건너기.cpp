#include <string>
#include <vector>

using namespace std;

bool Simulator(vector<int>& stones, int k, int num){
    int cnt = 0;
    for (int stone : stones){
        if (stone < num){
            cnt++;
            if (cnt >= k) return false;
        }
        else {
            cnt = 0;
        }
    }
    
    return true;
}

int solution(vector<int> stones, int k) {
    int l = 1;
    int r = 200000000;
    int answer = 0;
    
    while(l <= r){
        int mid = (l + r) / 2;
        
        if(Simulator(stones, k, mid)){
            answer = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    
    
    return answer;
}