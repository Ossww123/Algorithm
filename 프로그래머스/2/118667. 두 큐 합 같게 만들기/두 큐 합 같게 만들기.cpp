#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long sum1 = 0;
    long long sum2 = 0;
    
    for (int num1 : queue1)
        sum1 += num1;
    for (int num2 : queue2)
        sum2 += num2;
    
    long long sum = sum1 + sum2;
    
    if (sum % 2 == 1)
        return -1;
    
    long long target = sum / 2;
    
    vector<long long> v;
    v.insert(v.end(), queue1.begin(), queue1.end());
    v.insert(v.end(), queue2.begin(), queue2.end());
    
    int n = queue1.size();
    int left = 0, right = n - 1;
    long long cur = sum1;
    
    int ans = 0;
    while (left <= right && right < v.size())
    {
        
    if (cur == target)
        return ans;
        
    if (cur < target)
    {
        right++;
        cur += v[right];
    }
    else
    {
        cur -= v[left];
        left++;
    }
    ans++;
    }

    return -1;
}