#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    
    // 4와 7로 이루어진 수의 길이 계산
    int len = 1;
    long long count = 2; // 길이가 1인 수의 개수 (4, 7)
    
    while (N > count) {
        N -= count;
        len++;
        count *= 2; // 길이가 len인 수의 개수는 2^len
    }
    
    // k번째 수 구성
    string result = "";
    for (int i = 0; i < len; i++) {
        if (N <= count / 2) {
            result += "4";
        } else {
            result += "7";
            N -= count / 2;
        }
        count /= 2;
    }
    
    cout << result << endl;
    
    return 0;
}