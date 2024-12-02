#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int w, k;
        cin >> w >> k;
        int answer = w * k / 2;

        cout << answer << endl;
    }



    return 0;
}
