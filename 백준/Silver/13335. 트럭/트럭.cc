#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, w, l;  // n: 트럭 수, w: 다리 길이, l: 다리의 최대하중
    cin >> n >> w >> l;
    
    queue<int> trucks;  // 대기 중인 트럭들
    for (int i = 0; i < n; i++) {
        int weight;
        cin >> weight;
        trucks.push(weight);
    }
    
    queue<int> bridge;  // 다리를 표현하는 큐
    for (int i = 0; i < w; i++) {
        bridge.push(0);  // 다리를 0으로 초기화
    }
    
    int time = 0;  // 경과 시간
    int current_weight = 0;  // 현재 다리 위의 총 무게
    
    while (!bridge.empty()) {
        time++;
        
        // 다리에서 트럭이 나가는 경우
        current_weight -= bridge.front();
        bridge.pop();
        
        // 새 트럭이 다리에 올라갈 수 있는지 확인
        if (!trucks.empty()) {
            if (current_weight + trucks.front() <= l) {  // 하중 제한을 넘지 않는 경우
                current_weight += trucks.front();
                bridge.push(trucks.front());
                trucks.pop();
            }
            else {
                bridge.push(0);  // 트럭이 올라갈 수 없으면 0을 추가
            }
        }
        else if (!bridge.empty()) {
            // 남은 트럭이 없지만 다리 위에 트럭이 있는 경우
            continue;
        }
    }
    
    cout << time << '\n';
    
    return 0;
}