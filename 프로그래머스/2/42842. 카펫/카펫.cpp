#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int total = brown + yellow;
    
    int x = 3;
    int y = 3;
    
    while(1)
    {
        if (total % x != 0)
        {
            x++;
            continue;
        }
        
        y = total / x;
        if (x < y)
        {
            x++;
            continue;
        }
        
        if ((x-2) * (y-2) != yellow)
        {
            x++;
            continue;
        }
        
        break;
    }
    
    return {x, y};
}