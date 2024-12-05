#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int answer;

    if (min({ a, b, c }) == a) {
        answer = b + c;
    }
    
    if (min({ a, b, c }) == b) {
        answer = a + c;
    }

    if (min({ a, b, c }) == c) {
        answer = b + a;
    }

    cout << answer;
}
