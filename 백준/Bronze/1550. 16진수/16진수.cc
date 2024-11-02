#include <iostream>
#include <string>

using namespace std;


int main() {
    string hexStr;
    cin >> hexStr;
    int num = stoi(hexStr, nullptr, 16);

    cout << num;
    

    return 0;
}