#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> floor_cards(N);
    for (int i = 0; i < N; i++) {
        floor_cards[i] = N - i;
    }

    vector<int> query(N);
    for (int i = N-1; i >= 0; i--) {
        cin >> query[i];
    }

    list<int> cards;  // 연결 리스트 사용

    for (int A : query) {
        int length = floor_cards.size();

        if (A == 1) {
            cards.push_back(floor_cards[length - 1]);
            floor_cards.pop_back();
        }
        else if (A == 2) {
            auto it = cards.end();
            --it;  // 끝에서 두 번째 위치로 이동
            cards.insert(it, floor_cards[length - 1]);
            floor_cards.pop_back();
        }
        else {
            cards.push_front(floor_cards[length - 1]);
            floor_cards.pop_back();
        }
    }

    // 뒤집은 순서대로 출력
    vector<int> result(cards.begin(), cards.end());
    reverse(result.begin(), result.end());
    
    for (int i : result) {
        cout << i << ' ';
    }

    return 0;
}