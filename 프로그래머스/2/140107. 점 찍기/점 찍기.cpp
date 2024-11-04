#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    for (int a = 0; a * k <= d; a++) {
        int y = static_cast<int>(sqrt(pow(d, 2) - pow(a*k, 2)) / k);
        answer += y + 1;
    }
    return answer;
}