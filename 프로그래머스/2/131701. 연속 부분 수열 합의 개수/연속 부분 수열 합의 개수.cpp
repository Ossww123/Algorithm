#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    int n = elements.size();
    
    vector<int> subTotals(n, 0);
    
    for(int i=0; i<n; i++)
    {
        if (i == 0) subTotals[0] = elements[0];
        else        subTotals[i] = subTotals[i-1] + elements[i];
    }
    
    // 1 2 3 4 5
    // 1 3 6 10 15
    // 4 + 5 + 1 = (15 + 1) - 6
    
    unordered_set<int> partialSums;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int left = i == 0 ? 0 : subTotals[i-1];
            int right = subTotals[j];
            
            int partialSum = right - left;
            partialSums.insert(partialSum);
            
            if (i == 0 && j == n-1) continue;
            
            partialSum = left - right + subTotals[n-1];
            partialSums.insert(partialSum);
        }
    }
    
    return partialSums.size();
}