#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <set>

using namespace std;

bool isValid(string s) {
    bool hasVowel = false;

    set<char> vowels = { 'a', 'e', 'i', 'o', 'u' };

    // 모음이 하나 이상 포함되어 있는지 확인
    for (char c : s) {
        if (vowels.count(c)) {
            hasVowel = true;
            break;
        }
    }

    if (!hasVowel) {
        return false;
    }

    // 3연속 자음 모음 확인
    for (int i = 0; i <= (int)s.length() - 3; i++) {
        char first = s[i];
        char second = s[i + 1];
        char third = s[i + 2];

        bool firstIsVowel = vowels.count(first);
        bool secondIsVowel = vowels.count(second);
        bool thirdIsVowel = vowels.count(third);

        if ((firstIsVowel && secondIsVowel && thirdIsVowel) ||
            (!firstIsVowel && !secondIsVowel && !thirdIsVowel)) {

            return false;
        }
    }

    // 연속 같은 글자 확인
    for (int i = 0; i <= (int)s.length() - 2; i++) {
        char first = s[i];
        char second = s[i + 1];

        if (first == second) {
            if (first == 'e' || first == 'o') continue;
            return false;
        }
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (1) {
        string s;
        cin >> s;
        if (s == "end") break;

        if (isValid(s)) {
            cout << '<' << s << "> is acceptable." << endl;
        }
        else {
            cout << '<' << s << "> is not acceptable." << endl;
        }
    }

    return 0;
}