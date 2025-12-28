#include <string>
#include <vector>
using namespace std;

string ConvertBinary(int n)
{
    if (n == 0) return "0";
    string res;
    while (n > 0) {
        res = char('0' + (n % 2)) + res;
        n /= 2;
    }
    return res;
}

vector<int> solution(string s) 
{
    int trans_cnt = 0;
    int zero_cnt = 0;

    while (s != "1") 
    {
        int ones = 0;
        for (char c : s) 
        {
            if (c == '1')
                ones++;
            else
                zero_cnt++;
        }

        s = ConvertBinary(ones);
        trans_cnt++;
    }

    return {trans_cnt, zero_cnt};
}
