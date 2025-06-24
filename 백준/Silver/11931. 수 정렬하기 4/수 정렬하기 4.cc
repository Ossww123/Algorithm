#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> nums(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }

    // 내림차순 정렬
    sort(nums.begin(), nums.end(), greater<int>());

    // 결과 출력
    for (int i = 0; i < N; ++i)
    {
        cout << nums[i] << '\n';
    }

    return 0;
}