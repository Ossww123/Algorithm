#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

    int A, B;
    cin >> A >> B;

    int Amod = (A-1) % 4;
    int Bmod = (B-1) % 4;

    int Adiv = (A-1) / 4;
    int Bdiv = (B-1) / 4;

    int answer = abs(Amod - Bmod) + abs(Adiv - Bdiv);

    cout << answer;
    

    return 0;
}
