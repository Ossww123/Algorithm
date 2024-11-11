#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int Rev(string X) {
    reverse(X.begin(), X.end());
    return stoi(X);
}

int main()
{
    string x, y;
    cin >> x >> y;

    int answer;

    answer = Rev(to_string(Rev(x) + Rev(y)));

    cout << answer;

    return 0;
}
