#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    unordered_set<string> strs;
    
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        strs.insert(str);
    }

    string ret;
    for (string s : strs) {
        string r_s = "";
        for (int i = (s.size()-1); i >= 0; i--) {
            r_s += s[i];
        }

        if (strs.find(r_s) != strs.end()) {
            ret = s;
            break;
        }
    }

    char c = ret[ret.size() / 2];

    cout << ret.size() << ' ' << c;

    return 0;
}
