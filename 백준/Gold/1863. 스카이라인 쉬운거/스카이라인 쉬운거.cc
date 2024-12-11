#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Point {
    int x;
    int y;
};

int main()
{
    int numPoints;
    cin >> numPoints;

    vector<Point> skylinePoints;

    for (int i = 0; i < numPoints; i++){
        int xCoord, yCoord;
        cin >> xCoord >> yCoord;

        Point currentPoint;

        currentPoint.x = xCoord;
        currentPoint.y = yCoord;

        skylinePoints.push_back(currentPoint);
    }

    //// xCoord 기준으로 정렬
    //sort(skylinePoints.begin(), skylinePoints.end(), [](const Point& a, const Point& b) {
    //    return a.x < b.x;
    //    });


    stack<int> yStack;
    int answer = 0;

    for (int i = 0; i < numPoints; i++) {
        int currY = skylinePoints[i].y;

        if (yStack.empty()) {
            if (currY == 0) {
                continue;
            }
            else {
                yStack.push(currY);
            }
        }

        else {
            if (currY == 0) {
                while (!yStack.empty()) {
                    yStack.pop();
                    answer++;
                }
            }
            else {
                if (currY > yStack.top()) {
                    yStack.push(currY);
                }
                else {
                    while (!yStack.empty() && currY < yStack.top()) {
                        yStack.pop();
                        answer++;
                    }

                    if (yStack.empty() || yStack.top() != currY)
                        yStack.push(currY);
                }
            }
        }
    }

    while (!yStack.empty()) {
        yStack.pop();
        answer++;
    }

    cout << answer;

    return 0;
}
