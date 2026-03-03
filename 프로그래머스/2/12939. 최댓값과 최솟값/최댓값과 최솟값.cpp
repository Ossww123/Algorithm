#include <string>
#include <sstream>
using namespace std;

string solution(string s) {
    stringstream ss(s);
    int x;
    
    ss >> x;
    int mn = x, mx = x;

    while (ss >> x) {
        if (x < mn) mn = x;
        if (x > mx) mx = x;
    }

    return to_string(mn) + " " + to_string(mx);
}