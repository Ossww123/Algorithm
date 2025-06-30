#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    
    if (a > 15)
    {
        a -= 24;
    }
    
    cout << b - a;
    
    return 0;
}