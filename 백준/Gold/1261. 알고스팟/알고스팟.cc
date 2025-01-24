#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>

using namespace std;

// Directions for 4-way movement
constexpr int DY[4] = { 0, 0, 1, -1 };
constexpr int DX[4] = { 1, -1, 0, 0 };

// Structure to represent a point with its distance
struct Point {
    int y;
    int x;
    int dist;
    
    // Comparison for priority queue (min-heap)
    bool operator>(const Point& other) const {
        return dist > other.dist;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;

    // Map to store wall information
    vector<vector<int>> map(N, vector<int>(M));

    // Read input map
    string row;
    for (int i = 0; i < N; i++) {
        cin >> row;
        for (int j = 0; j < M; j++) {
            map[i][j] = row[j] - '0';
        }
    }

    // Distance matrix to track minimum walls broken
    vector<vector<int>> dist(N, vector<int>(M, INT_MAX));
    
    // Priority queue to process points with minimum walls broken first
    priority_queue<Point, vector<Point>, greater<Point>> pq;
    
    // Start from the top-left corner
    dist[0][0] = 0;
    pq.push({0, 0, 0});

    while (!pq.empty()) {
        Point current = pq.top();
        pq.pop();
        
        int cy = current.y, cx = current.x, currentDist = current.dist;
        
        // If we've reached the bottom-right corner, we're done
        if (cy == N-1 && cx == M-1) {
            cout << currentDist << '\n';
            return 0;
        }
        
        // Skip if we've found a better path to this point
        if (currentDist > dist[cy][cx]) continue;

        // Explore 4 adjacent directions
        for (int dir = 0; dir < 4; ++dir) {
            int ny = cy + DY[dir];
            int nx = cx + DX[dir];

            // Check if new point is within map bounds
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

            // Calculate new distance (walls broken)
            int newDist = currentDist + map[ny][nx];

            // Update if we found a better path
            if (newDist < dist[ny][nx]) {
                dist[ny][nx] = newDist;
                pq.push({ny, nx, newDist});
            }
        }
    }

    return 0;
}