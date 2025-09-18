#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    unordered_set<string> types(gems.begin(), gems.end());
    int num_types = types.size();
    
    unordered_map<string, int> cnt;
    
    int l = 0;
    int min_length = gems.size();
    
    vector<int> answer = {1, min_length};
    
    for(int r=0;r<gems.size();r++){
        cnt[gems[r]]++;
        
        while (cnt.size() == num_types){
            int length = r - l + 1;
            if (length < min_length){
                min_length = length;
                answer = {l + 1, r + 1};
            }
            
            cnt[gems[l]]--;
            if(cnt[gems[l]] == 0) {
                cnt.erase(gems[l]);
            }
            l++;
        }
    }
    
    return answer;
}