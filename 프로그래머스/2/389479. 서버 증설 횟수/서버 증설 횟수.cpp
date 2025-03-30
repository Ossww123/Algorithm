#include <string>
#include <vector>
#include <queue>

using namespace std;

int calNeedServer(int players, int m){
    return players / m;
}

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    queue<int> serverLifetime;
    for (int i=0;i<k;i++){
        serverLifetime.push(0);
    }
    
    int currServer = 0;
    for (int i=0;i<24;i++){
        int needServer = calNeedServer(players[i], m);
        int endServer = serverLifetime.front();
        currServer -= endServer;
        
        if (currServer >= needServer){
            serverLifetime.pop();
            serverLifetime.push(0);
        }
        else{
            int diff = needServer - currServer;
            answer += diff;
            currServer += diff;
            serverLifetime.pop();
            serverLifetime.push(diff);
        }
    }
    return answer;
}