#include <iostream>

using namespace std;

int main()
{
    while (true) {
        int M, W;
        cin >> M >> W;
        if (M == 0 && W == 0)
            break;
        cout << M + W << endl;
    }



    return 0;
}
