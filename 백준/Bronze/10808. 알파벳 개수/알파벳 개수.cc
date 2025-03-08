#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    cin >> S;

    int str[26];
    for (int i = 0; i < 26; i++) {
        str[i] = 0;
    }

    for (char c : S) {
        int N = c - 'a';
        str[N]++;
    }

    for (int i = 0; i < 26; i++) {
        cout << str[i] << ' ';
    }
    
    return 0;
}
