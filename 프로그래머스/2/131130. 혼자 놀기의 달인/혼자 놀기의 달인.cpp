#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    int N = cards.size();
    vector<bool> visited(N, false);
    
    for (int i=0;i<N;i++){
        int temp1 = i;
        int first_cnt = 0;
        do{
            visited[temp1] = true;
            first_cnt++;
            temp1 = cards[temp1] - 1;
        } while(!visited[temp1]);
            
        for (int j =0 ; j < N ; j++){
            if (visited[j])
                continue;
            
            vector<int> second_group;
            int temp2 = j;
            int second_cnt = 0;
            do{
                visited[temp2] = true;
                second_group.push_back(temp2);
                second_cnt++;
                temp2 = cards[temp2] - 1;
            } while(!visited[temp2]);
            
            if (first_cnt * second_cnt > answer)
                answer = first_cnt * second_cnt;
            
            for (int node : second_group) {
                visited[node] = false;
            }
        }
        
        fill(visited.begin(), visited.end(), false);
    }
    
    return answer;
}