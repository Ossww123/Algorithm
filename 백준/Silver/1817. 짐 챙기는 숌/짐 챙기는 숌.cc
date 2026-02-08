#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    
    if (N == 0)
    {
        cout << 0;
        return 0;
    }
    
    vector<int> books(N, 0);
    
    for (int i=0; i<N; i++)
    {
        cin >> books[i];
    }
    
    int ans = 1;
    int sum = 0;
    for (int b : books)
    {
        if (sum + b > M)
        {
            ans++;
            sum = b;
        }
        else
        {
            sum += b;
        }
    }
    
    cout << ans;
    
    return 0;
}