#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // 모든 순열을 확인하기 위해 정렬
    sort(a.begin(), a.end());
    
    int maxSum = 0;
    
    // 모든 순열에 대해 확인
    do {
        int currentSum = 0;
        
        // 현재 순열에서 인접한 원소들의 차이의 절댓값 합 계산
        for (int i = 0; i < n - 1; i++) {
            currentSum += abs(a[i] - a[i + 1]);
        }
        
        // 최댓값 갱신
        maxSum = max(maxSum, currentSum);
        
    } while (next_permutation(a.begin(), a.end()));
    
    cout << maxSum << endl;
    
    return 0;
}