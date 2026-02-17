#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<string> tails;
    
    int n = s.size();
    string tail = "";
    
    for (int i=n-1; i>=0; i--)
    {
        tail = s[i] + tail;
        tails.push_back(tail);
    }
    
    sort(tails.begin(), tails.end());
    
    for(string t : tails)
    {
        cout << t << endl;
    }
    return 0;
}