#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int DY[4] = {0, 0, 1, -1};
int DX[4] = {1, -1, 0, 0};

struct Point {
    int y;
    int x;

    Point(int yCoord, int xCoord) : y(yCoord), x(xCoord) {}
};


vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int width = maps[0].size();
    int height = maps.size();
    vector<vector<bool>> visited(height, vector<bool>(width, false));
    
    for (int y=0;y<height;y++){
        for (int x=0;x<width;x++){
            if (maps[y][x] == 'X')
                continue;
            if (visited[y][x])
                continue;
            
            int total = maps[y][x] - '0';
            queue<Point> q;
            Point p(y, x);
            q.push(p);
            visited[y][x] = true;
            
            while (!q.empty()){
                int sy = q.front().y;
                int sx = q.front().x;
                q.pop();
                
                for (int index = 0 ; index < 4 ; index++){
                    int ny = sy + DY[index];
                    int nx = sx + DX[index];
                    
                    if (ny < 0 || ny >= height || nx < 0 || nx >= width)
                        continue;
                    
                    if (maps[ny][nx] == 'X' || visited[ny][nx])
                        continue;
                    
                    int num_food = maps[ny][nx] - '0';
                    total += num_food;
                    visited[ny][nx] = true;
                    Point np(ny, nx);
                    q.push(np);
                }
            }
            answer.push_back(total);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    if (answer.empty())
        answer.push_back(-1);
    
    return answer;
}