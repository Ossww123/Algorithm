#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int solution(vector<int> arr) {
    int result = arr[0];
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        result = lcm(result, arr[i]);
    }

    return result;
    
}