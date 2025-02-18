#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    N *= 100;
    if (N >= M)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}