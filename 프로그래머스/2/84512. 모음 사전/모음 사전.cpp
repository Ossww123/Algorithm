#include <string>
#include <vector>
using namespace std;

int solution(string word) {
    vector<int> w = {781, 156, 31, 6, 1};
    string chars = "AEIOU";

    int answer = 0;
    for (int i = 0; i < (int)word.size(); i++) 
    {
        int idx = chars.find(word[i]);
        answer += idx * w[i] + 1;
    }
    return answer;
}
