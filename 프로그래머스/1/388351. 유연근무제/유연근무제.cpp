#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int num = schedules.size();
    vector<int> good(num, 0);

    for (int i = 0; i < 7; i++) {

        int day = (i + startday) % 7;
        if (day == 0) day = 7;

        if (day == 6 || day == 7) continue;

        for (int j = 0; j < num; j++) {
            int limitTime = schedules[j] + 10;
            if (limitTime % 100 >= 60) {
                limitTime = limitTime + 40;
            }

            int logTime = timelogs[j][i];

            if (logTime <= limitTime) {
                good[j]++;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < num; i++) {
        if (good[i] == 5) answer++;
    }

    return answer;
}