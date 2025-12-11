#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int curr = sequence[0];
    int left = 0;
    int right = 0;
    int n = sequence.size();
    
    vector<int> answer = {left, right};
    int min_length = 1000001;
    
    while(right < n)
    {
        if (curr < k)
        {
            right++;
            curr += sequence[right];
        }
        else if (curr == k)
        {
            int curr_length = right - left + 1;
            if (curr_length < min_length)
            {
                answer[0] = left;
                answer[1] = right;
                min_length = curr_length;
            }
            right++;
            curr += sequence[right];
        }
        else
        {
            curr -= sequence[left];
            left++;
        }
    }
    
    return answer;
}