#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int s = n + m;
    
    vector<int> array(s, 0);
    for (int i=0; i<s; i++)
    {
        cin >> array[i];
    }
    
    sort(array.begin(), array.end());
    
    for (int a : array)
    {
        cout << a << ' ';
    }
    
    return 0;
}