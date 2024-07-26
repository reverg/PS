#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin >> M >> N;

    vector<int> snacks;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        snacks.push_back(tmp);
    }

    sort(snacks.begin(), snacks.end());

    int ans = 0;
    int low = 1;
    int high = snacks[N - 1];
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int cnt = 0;
        for (int i = 0; i < N; i++)
            cnt += snacks[i] / mid;

        if (cnt < M)
            high = mid - 1;
        else
        {
            ans = mid;
            low = mid + 1;
        }
    }

    cout << ans << '\n';
}