#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string answer = "";

    int N;
    cin >> N;

    vector<char> first_chars;

    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;
        char first_char = name[0];
        first_chars.push_back(first_char);
    }

    for (int i = 0; i < 26; i++) {
        char a = 'a' + i;
        int cnt = 0;

        for (int j = 0; j < N; j++) {
            if (first_chars[j] == a) {
                cnt++;
            }
        }

        if (cnt >= 5) {
            answer += a;
        }
    }
    if (answer != "") {
        cout << answer;
    }
    else {
        cout << "PREDAJA";
    }

    return 0;
}
