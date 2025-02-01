#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string name;
    int d;
    int m;
    int y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<Student> students;

    for (int i = 0; i < N; i++) {
        string name;
        int d, m, y;
        cin >> name >> d >> m >> y;
        students.emplace_back(Student{ name, d, m, y });
    }

    int youngest = 0;
    int oldest = 0;

    for (int i = 1; i < N; i++) {
        if (students[i].y > students[youngest].y ||
            (students[i].y == students[youngest].y && students[i].m > students[youngest].m) ||
            (students[i].y == students[youngest].y && students[i].m == students[youngest].m && students[i].d > students[youngest].d)) {
            youngest = i;
        }

        if (students[i].y < students[oldest].y ||
            (students[i].y == students[oldest].y && students[i].m < students[oldest].m) ||
            (students[i].y == students[oldest].y && students[i].m == students[oldest].m && students[i].d < students[oldest].d)) {
            oldest = i;
        }
    }

    cout << students[youngest].name << '\n';
    cout << students[oldest].name << '\n';

    return 0;
}