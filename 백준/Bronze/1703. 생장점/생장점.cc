#include <iostream>

using namespace std;

int main()
{
    while (true) {
        int N;
        cin >> N;
        if (N == 0) {
            break;
        }

        int total_leaf = 1;
        for (int i = 0; i < N; i++) {
            int divided_num, sliced_num;
            cin >> divided_num >> sliced_num;

            total_leaf *= divided_num;
            total_leaf -= sliced_num;
        }

        cout << total_leaf << endl;
    }

    return 0;
}
