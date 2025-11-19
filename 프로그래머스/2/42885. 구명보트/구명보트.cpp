#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    
    int l=0, r=people.size()-1;
    int answer = 0;
    
    while(l <= r){
        answer++;
        if (people[l] + people[r] <= limit){
            l++; r--;
        }
        else{
            r--;
        }
    }
        
    return answer;
}