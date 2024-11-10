#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


int main()
{
    long S;
    cin >> S;

    long total = 0;
    int cnt = 0;

    for (long i = 1; total <= S; i++) {
        total += i;
        cnt++;
    }

    cout << --cnt;

    return 0;
}
