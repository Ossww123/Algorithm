#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 오름차순 정렬
    sort(arr.begin(), arr.end());

    int answer = 0;
    for (int i = 0; i < N; i++) {
        int target = arr[i];
        int start = 0;
        int end = N - 1;

        while (start < end) {

            if (arr[start] + arr[end] == target) {
                if (start == i)
                    start++;
                else if (end == i)
                    end--;
                else {
                    answer++;
                    break;
                }
            }

            else if (arr[start] + arr[end] < target) {
                start++;
            }

            else if (arr[start] + arr[end] > target) {
                end--;
            }

        }
    }

    cout << answer;

    return 0;
}
