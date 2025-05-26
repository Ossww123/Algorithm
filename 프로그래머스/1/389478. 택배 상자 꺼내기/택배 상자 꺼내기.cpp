#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 1; // 13, 3, 6
    int quot = (num-1) / w; // 1
    int rema = num % w; // 0
    if (rema == 0) rema = w;
    
    bool isEven = quot % 2 == 1; // true
    
    int curr = num; // 6
    while (1){
        if (isEven){
            curr = curr + (w-rema) * 2 + 1; // 6 + (3-0) * 2 + 1
            if (curr > n) break;
            answer++;
            isEven = false;
            rema = w-rema+1;
        }
        else{
            curr = curr + (w-rema) * 2 + 1;
            if (curr > n) break;
            answer++;
            isEven = true;
            rema = w-rema+1;
        }
    }
    return answer;
}