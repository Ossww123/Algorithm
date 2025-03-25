
#include <string>
#include <vector>
#include <unordered_set>
#include <functional>

using namespace std;

struct Point {
    int r;
    int c;

    bool operator==(const Point& other) const {
        return r == other.r && c == other.c;
    }
};

struct PointHash {
    size_t operator()(const Point& p) const {
        return hash<int>()(p.r) ^ hash<int>()(p.c);
    }
};

Point move(Point now, Point nxt) {
    Point ret = now;

    if (now.r < nxt.r) ret.r++;
    else if (now.r > nxt.r) ret.r--;
    else {
        if (now.c < nxt.c) ret.c++;
        else if (now.c > nxt.c) ret.c--;
        else {
            ret = { -1, -1 };
        }
    }

    return ret;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;

    unordered_set<int> initCheck1;
    unordered_set<int> initCheck2;

    for (int i = 0; i < routes.size(); i++) {
        if (initCheck1.find(routes[i][0]) != initCheck1.end()) {
            initCheck2.insert(routes[i][0]);
        }
        else {
            initCheck1.insert(routes[i][0]);
        }
    }

    answer += initCheck2.size();

    int x = routes.size();
    vector<Point> robots(x);
    for (int i = 0; i < x; i++) {
        Point temp;
        temp.r = points[routes[i][0] - 1][0];
        temp.c = points[routes[i][0] - 1][1];
        robots[i] = temp;
    }

    int targetNum = routes[0].size();
    vector<int> nxtTargetIndex(x, 0);

    bool isEnd = false;
    while (!isEnd) {
        isEnd = true;
        unordered_set<Point, PointHash> positions;
        unordered_set<Point, PointHash> crashPositions;
        for (int i = 0; i < x; i++) {
            int nowR = robots[i].r;
            int nowC = robots[i].c;



            if (nowR == -1 && nowC == -1) continue;

            int targetR = points[routes[i][nxtTargetIndex[i]] - 1][0];
            int targetC = points[routes[i][nxtTargetIndex[i]] - 1][1];
            if (nowR == targetR && nowC == targetC) {
                nxtTargetIndex[i] += 1;
                if (nxtTargetIndex[i] < targetNum) {
                    targetR = points[routes[i][nxtTargetIndex[i]] - 1][0];
                    targetC = points[routes[i][nxtTargetIndex[i]] - 1][1];
                }

                else {
                    robots[i] = { -1, -1 };
                    continue;
                }
            }

            Point now = { nowR, nowC };
            Point target = { targetR, targetC };

            // cout << "번호: " << i << "    nowR " << nowR << "    nowC " << nowC << "    nxtTarget " << nxtTargetIndex[i] << "    targetR " << targetR << "    targetC " << targetC << endl;


            Point nxt = move(now, target);
            robots[i] = nxt;

            if (positions.find(nxt) != positions.end()) {
                crashPositions.insert(nxt);
            }
            else {
                positions.insert(nxt);
            }

            isEnd = false;
        }

        answer += crashPositions.size();
    }

    return answer;

}
