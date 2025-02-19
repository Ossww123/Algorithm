#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<string, pair<int, int>> resistor = {
        {"black", {0, 1}},
        {"brown", {1, 10}},
        {"red", {2, 100}},
        {"orange", {3, 1000}},
        {"yellow", {4, 10000}},
        {"green", {5, 100000}},
        {"blue", {6, 1000000}},
        {"violet", {7, 10000000}},
        {"grey", {8, 100000000}},
        {"white", {9, 1000000000}}
    };

    string st1, st2, st3;
    cin >> st1 >> st2 >> st3;

    long value = resistor[st1].first * 10 + resistor[st2].first;
    value *= resistor[st3].second;

    cout << value;

    return 0;
}
