#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long maxValue(vector<int>& s, int n){
    long long currMax = s[0];
    long long globMax = s[0];
    
    for (int i=1;i<n;i++){
        currMax = max(currMax + s[i], (long long)s[i]);
        globMax = max(globMax, currMax);
    }
    
    return globMax;
}

long long solution(vector<int> sequence) {
    int n = sequence.size();
    
    vector<int> s1(n);
    for (int i=0; i<n; i++){
        s1[i] = (i % 2 == 0) ? sequence[i] : (-1) * sequence[i];
    }
    
    vector<int> s2(n);
    for (int i=0; i<n; i++){
        s2[i] = (i % 2 == 1) ? sequence[i] : (-1) * sequence[i];
    }
    
    return max(maxValue(s1, n), maxValue(s2, n));
}