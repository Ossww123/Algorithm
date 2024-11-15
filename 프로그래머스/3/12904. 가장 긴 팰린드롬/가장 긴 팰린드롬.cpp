#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int solution(string s)
{
    int answer=1;
    
    
    for (int i=0 ; i<s.size();i++){
        int left = i;
        int right = i;
        int curr = 1;
        while (true){
            left--;
            right++;
            if (left < 0 || right >= s.size()){
                answer = max(answer, curr);
                break;
            }
            
            if (s[left] != s[right]){
                answer = max(answer, curr);
                break;
            }
            
            curr += 2;
            
        }
    }
    
    for (int i=1 ; i<s.size();i++){
        if (s[i] == s[i-1]){
            int left = i-1;
            int right = i;
            int curr = 2;
            while (true){
                left--;
                right++;
                if (left < 0 || right >= s.size()){
                    answer = max(answer, curr);
                    break;
                }

                if (s[left] != s[right]){
                    answer = max(answer, curr);
                    break;
                }

                curr += 2;

            }
        }
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << answer << endl;

    return answer;
}