#include <iostream>

using namespace std;

int main()
{
    int first;
    int second;

    cin >> first >> second;

    int answer = second + (second - first);

    cout << answer;

    return 0;
}
