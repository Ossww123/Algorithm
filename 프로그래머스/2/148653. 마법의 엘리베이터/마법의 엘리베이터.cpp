#include <string>
#include <vector>

using namespace std;

int solution(int storey) 
{
    int answer = 0;
    while(storey > 0)
    {
        int m = storey % 10;
        if (m < 5)
        {
            answer += m;
            storey -= m;
        }
        else if (m > 5)
        {
            answer += (10 - m);
            storey += (10 - m);
        }
        else
        {
           if ((storey % 100) / 10 >= 5)
           {
               answer += (10 - m);
               storey += (10 - m);
           }
           else
           {
               answer += m;
               storey -= m;
           }
        }
        
        storey /= 10;
    }
    
    return answer;
}