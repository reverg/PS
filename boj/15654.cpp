#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int numbers[8];
bool selected[8];
vector<int> ans;

void backtrack(int cnt)
{
    if (cnt == M)
    {
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }

    for (int i = 0; i < N; i++)
    {
        if (selected[i])
            continue;

        selected[i] = true;
        ans.push_back(numbers[i]);
        backtrack(cnt + 1);
        selected[i] = false;
        ans.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> numbers[i];

    sort(numbers, numbers + N);

    backtrack(0);
}