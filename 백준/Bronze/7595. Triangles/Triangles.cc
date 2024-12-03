#include <iostream>

using namespace std;

int main()
{
    while (true) {
        int N;
        cin >> N;
        if (N == 0)
            break;

        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < i; j++) {
                cout << '*';
            }
            cout << endl;
        }
    }



    return 0;
}
