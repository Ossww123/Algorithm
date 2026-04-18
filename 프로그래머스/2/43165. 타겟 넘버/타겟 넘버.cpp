#include <string>
#include <vector>

using namespace std;

int answer;
int t;
int n;
vector<int> ns;

void dfs(int num, int depth)
{
    if (depth == n)
    {
        if (num == t) answer++;
        return;
    }
    
    dfs(num + ns[depth], depth + 1);
    dfs(num - ns[depth], depth + 1);
}

int solution(vector<int> numbers, int target) {
    answer = 0;
    t = target;
    n = numbers.size();
    ns = numbers;
    
    dfs(0, 0);
    
    return answer;
}