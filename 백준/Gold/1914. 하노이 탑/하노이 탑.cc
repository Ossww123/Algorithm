#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string addBigNumbers(string num1, string num2) {
    if (num1.length() > num2.length())
        swap(num1, num2);
    
    string sum = "";
    int len1 = num1.length();
    int len2 = num2.length();
    int carry = 0;
    
    for (int i = 0; i < len1; i++) {
        int sum_digits = ((num1[len1 - 1 - i] - '0') + 
                          (num2[len2 - 1 - i] - '0') + 
                          carry);
        sum.push_back(sum_digits % 10 + '0');
        carry = sum_digits / 10;
    }
    
    for (int i = len1; i < len2; i++) {
        int sum_digits = ((num2[len2 - 1 - i] - '0') + carry);
        sum.push_back(sum_digits % 10 + '0');
        carry = sum_digits / 10;
    }
    
    if (carry)
        sum.push_back(carry + '0');
    
    reverse(sum.begin(), sum.end());
    return sum;
}

string calculateMoves(int n) {
    string result = "1";
    for (int i = 0; i < n; i++) {
        result = addBigNumbers(result, result);
    }
    
    int lastDigit = result.back() - '0';
    result.back() = ((lastDigit - 1 + 10) % 10) + '0';
    
    while (result.length() > 1 && result[0] == '0') {
        result.erase(0, 1);
    }
    
    return result;
}

void hanoi(int n, int start, int end, int aux, vector<vector<int>>& stacks) {
    if (n == 1) {
        cout << start + 1 << " " << end + 1 << "\n";
        stacks[end].push_back(stacks[start].back());
        stacks[start].pop_back();
        return;
    }

    hanoi(n - 1, start, aux, end, stacks);
    cout << start + 1 << " " << end + 1 << "\n";
    stacks[end].push_back(stacks[start].back());
    stacks[start].pop_back();
    hanoi(n - 1, aux, end, start, stacks);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> stacks(3);
    for (int i = N; i > 0; --i) {
        stacks[0].push_back(i);
    }

    string total_moves = calculateMoves(N);
    cout << total_moves << "\n";

    if (N <= 20) {
        hanoi(N, 0, 2, 1, stacks);
    }

    return 0;
}