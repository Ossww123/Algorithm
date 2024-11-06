#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int N = triangle.size();
    
    vector<vector<int>> dp_table(N, vector<int>(N));
    dp_table[0][0] = triangle[0][0];
    
    for (int i=1 ; i<N ; i++){
        for (int j=0; j<=i ; j++){
            if (j==0){
                dp_table[i][j] = dp_table[i-1][j] + triangle[i][j];
            } else if (j == i){
                dp_table[i][j] = dp_table[i-1][j-1] + triangle[i][j];
            } else{
                int temp = dp_table[i-1][j] > dp_table[i-1][j-1] ? dp_table[i-1][j] : dp_table[i-1][j-1];
                dp_table[i][j] = temp + triangle[i][j];
            }
            
        }
    }
    
    for (int i=0 ; i<N ; i++){
        if (dp_table[N-1][i] > answer)
            answer = dp_table[N-1][i];
    }
    
    return answer;
}