#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int min_idx = 0;
    int curr = a[0];
    int n = a.size();
    
    for(int i=0;i<n;i++){
        if (a[i] < curr){
            min_idx = i;
            curr = a[i];
        }
    }
    
    int answer = 1;
    int currL = 1000000001;
    for(int i=0;i<min_idx;i++){
        if (a[i] < currL){
            answer++;
            currL = a[i];
        }
    }
    
    int currR = 1000000001;
    for(int i=n-1;i>min_idx;i--){
        if (a[i] < currR){
            answer++;
            currR = a[i];
        }
    }
    
    return answer;
}