#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string S;
    cin >> S;
    int N = S.size();

    string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    for (int i = 1;i < N - 1;i++) {
        for (int j = i + 1;j < N;j++) {
            string str1, str2, str3;
            
            for (int k = 0;k < i;k++) {
                str1 += S[k];
            }
            reverse(str1.begin(), str1.end());

            for (int k = i;k < j;k++) {
                str2 += S[k];
            }
            reverse(str2.begin(), str2.end());

            for (int k = j;k < N;k++) {
                str3 += S[k];
            }
            reverse(str3.begin(), str3.end());

            string temp = str1 + str2 + str3;
            if (ans > temp) ans = temp;
        }
    }
    cout << ans;
    return 0;
}