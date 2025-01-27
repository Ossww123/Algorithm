#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string dict;
    getline(cin, dict);
    string word;
    getline(cin, word);

    int D = dict.size();
    int W = word.size();
    int cnt = 0;
    int index = 0;

    while (index <= (D-W)) {
        if (dict[index] == word[0]) {
            if (dict.substr(index, W) == word) {
                cnt++;
                index += (W - 1);
            }
        }
        index++;
    }

    cout << cnt;
    return 0;
}