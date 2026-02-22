#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int gcd_multiple(const vector<int>& nums)
{
    int result = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        result = gcd(result, nums[i]);
    }
    return result;
}

bool divides_any(int g, const vector<int>& nums)
{
    for (int n : nums)
    {
        if (n % g == 0)
            return true;
    }
    return false;
}

int solution(vector<int> arrayA, vector<int> arrayB)
{
    int gcdA = gcd_multiple(arrayA);
    int gcdB = gcd_multiple(arrayB);

    int answer = 0;

    if (!divides_any(gcdA, arrayB))
        answer = max(answer, gcdA);

    if (!divides_any(gcdB, arrayA))
        answer = max(answer, gcdB);

    return answer;
}