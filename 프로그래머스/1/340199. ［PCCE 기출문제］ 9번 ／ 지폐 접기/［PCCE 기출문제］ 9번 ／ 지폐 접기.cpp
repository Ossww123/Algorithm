#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int bill_y = bill[1];
    int bill_x = bill[0];
    
    int answer = 0;
    
    while(1){
        if (bill_y <= wallet[1] && bill_x <= wallet[0]){
            break;
        }
        else if (bill_y <= wallet[0] && bill_x <= wallet[1]){
            break;
        }
        
        if (bill_y >= bill_x){
            bill_y /= 2;
            ++answer;
        }
        else{
            bill_x /= 2;
            ++answer;
        }
    }
    return answer;
}