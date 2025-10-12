#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int idx = 0;
    int s = stations.size();
    
    int range = 0;
    while(range < n){
        if (idx < s && stations[idx] <= range + w + 1){
            range = stations[idx++] + w;
        }
        else{
            answer++;
            range = range + 2 * w + 1;
        }
    }

    return answer;
}