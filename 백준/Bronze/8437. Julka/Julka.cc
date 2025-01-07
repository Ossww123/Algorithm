#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 문자열 덧셈 함수
string addStrings(string num1, string num2) {
    string result = "";
    int carry = 0, sum = 0;
    int i = num1.size() - 1, j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;

        sum = digit1 + digit2 + carry;
        result += (sum % 10) + '0';
        carry = sum / 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

// 문자열 뺄셈 함수 (num1 > num2라고 가정)
string subtractStrings(string num1, string num2) {
    string result = "";
    int borrow = 0, diff = 0;
    int i = num1.size() - 1, j = num2.size() - 1;

    while (i >= 0 || j >= 0) {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;

        diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result += diff + '0';
    }

    // 앞쪽에 있는 불필요한 0 제거
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }

    reverse(result.begin(), result.end());
    return result;
}

// 숫자를 반으로 나누는 함수
string divideByTwo(string num) {
    string result = "";
    int carry = 0;

    for (char c : num) {
        int digit = carry * 10 + (c - '0');
        result += (digit / 2) + '0';
        carry = digit % 2;
    }

    // 앞쪽의 불필요한 0 제거
    while (result.size() > 1 && result[0] == '0') {
        result.erase(result.begin());
    }

    return result;
}

int main() {
    string A, B;
    cin >> A >> B;

    // (A + B) / 2
    string sum = addStrings(A, B);
    string Klaudia = divideByTwo(sum);

    // (A - B) / 2
    string diff = subtractStrings(A, B);
    string Natalia = divideByTwo(diff);

    cout << Klaudia << endl << Natalia << endl;

    return 0;
}
