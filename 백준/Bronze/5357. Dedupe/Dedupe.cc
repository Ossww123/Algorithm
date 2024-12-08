#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string a;
        cin >> a;

        string ans = "";
        char prev = '\0';
        for (int j = 0; j < a.size(); j++) {
            if (prev == a[j]) {
                continue;
            }
            ans += a[j];
            prev = a[j];
        }

        cout << ans << endl;
    }

    return 0;
}
