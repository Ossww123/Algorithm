#include <iostream>
#include <vector>

using namespace std;

int k;
vector<int> nums;
vector<int> selected;

void Combination(int idx, int cnt)
{
    if (cnt == 6)
    {
        for (int i = 0; i < 6; i++)
        {
            cout << selected[i] << " ";
        }
        cout << '\n';
        return;
    }

    if (idx == k) return;

    selected[cnt] = nums[idx];
    Combination(idx + 1, cnt + 1);
    Combination(idx + 1, cnt);
}

int main()
{
    while (true)
    {
        cin >> k;
        if (k == 0) break;

        nums.resize(k);
        selected.resize(6);

        for (int i = 0; i < k; i++)
        {
            cin >> nums[i];
        }

        Combination(0, 0);
        cout << '\n';
    }
    return 0;
}
