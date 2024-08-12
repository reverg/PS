#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int nums[9];
vector<int> candidates;
bool selected[9];

void backtrack(int cnt)
{
    if (cnt == 0)
    {
        for (int i = 0; i < M; i++)
            cout << candidates[i] << ' ';
        cout << '\n';
        return;
    }

    int prev_num = 0;
    for (int i = 0; i < N; i++)
    {
        if (!selected[i] && (prev_num != nums[i]))
        {
            selected[i] = true;
            candidates.push_back(nums[i]);
            prev_num = nums[i];
            backtrack(cnt - 1);
            selected[i] = false;
            candidates.pop_back();
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> nums[i];

    sort(nums, nums + N);

    backtrack(M);
}

/*
문제 조건상 중복된 수열을 출력하면 안되므로 같은 숫자를 여러 번
고르지 않게 prev_num을 뒀다. backtrack()이 호출 될 때마다 수를
하나씩 고르므로, 같은 자리에 직전에 쓴 숫자가 들어가지 않게 된다.
*/