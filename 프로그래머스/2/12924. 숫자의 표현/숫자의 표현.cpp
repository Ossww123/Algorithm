#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for (int i=1; i<n+1; i++)
    {
        int j = 1;
        while(true)
        {
            int sum = i * j + j * (j - 1) / 2;
            if (sum < n)
            {
                j++;
            }
            else if (sum == n)
            {
                answer++;
                break;
            }
            else
            {
                break;
            }
        }
    }
    
    return answer;
}