#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int G, C, E;
        cin >> G >> C >> E;
        int requiredCandy = E - C;
        if (requiredCandy <= 0) {
            cout << 0 << endl;
        }
        else {
            int kilometers = requiredCandy * (G * 2 - 1);

            cout << kilometers << endl;
        }
    }

    return 0;
}