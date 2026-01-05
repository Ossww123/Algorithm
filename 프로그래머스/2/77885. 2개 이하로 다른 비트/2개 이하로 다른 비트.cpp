#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;

ll Solve(ll n)
{
    ll ret = 0;
    
    ll keyValue = (n & 0b1LL) + (n & 0b10LL);
    
    if (keyValue < 0b11LL)
    {
        ret = n + 1;
    }
    else
    {
        ll firstZeroBitMask = 0b1LL;
        ll cnt = 1;
        while (true)
        {
            ll maskedBit = n & firstZeroBitMask;
            
            if (maskedBit)
            {
                firstZeroBitMask <<= 1;
                continue;
            }
            else
            {
                ret = n + firstZeroBitMask - (firstZeroBitMask >> 1);
                break;
            }
        }
    }
    
    return ret;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (ll n : numbers)
    {
        answer.push_back(Solve(n));
    }
    return answer;
}