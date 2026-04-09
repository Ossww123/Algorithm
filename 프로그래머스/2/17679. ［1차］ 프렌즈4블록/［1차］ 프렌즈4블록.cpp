#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while (true)
    {
        vector<vector<bool>> remove(m, vector<bool>(n, false));
        
        for (int i = 0; i < m - 1; i++) 
        {
            for (int j = 0; j < n - 1; j++) 
            {
                char c = board[i][j];
                if (c == '0') continue;
                
                if (board[i][j+1] == c &&
                    board[i+1][j] == c &&
                    board[i+1][j+1] == c) 
                {
                    
                    remove[i][j] = true;
                    remove[i][j+1] = true;
                    remove[i+1][j] = true;
                    remove[i+1][j+1] = true;
                }
            }
        }
        
        bool any = false;
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (remove[i][j]) 
                {
                    any = true;
                    board[i][j] = '0';
                    answer++;
                }
            }
        }
        
        if (!any) break;
        
        for (int j = 0; j < n; j++) 
        {
            vector<char> temp;
            
            for (int i = m - 1; i >= 0; i--) 
            {
                if (board[i][j] != '0') 
                {
                    temp.push_back(board[i][j]);
                }
            }
            
            int idx = m - 1;
            for (char c : temp) 
            {
                board[idx--][j] = c;
            }
            
            for (int i = idx; i >= 0; i--) 
            {
                board[i][j] = '0';
            }
        }
    }
    
    return answer;
}