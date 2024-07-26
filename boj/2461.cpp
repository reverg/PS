#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    pair<int, int> abil[N * M];
    for (int i = 0, idx = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++, idx++)
        {
            cin >> abil[idx].first;
            abil[idx].second = i;
        }
    }

    sort(abil, abil + N * M);

    int cnt[N] = {0};
    cnt[abil[0].second]++;

    int ans = 1e9;
    int left = 0;
    int right = 0;
    int teams = 1;
    while (true)
    {
        if (teams != N)
        {
            if (right == N * M - 1)
                break;

            right++;
            cnt[abil[right].second]++;

            if (cnt[abil[right].second] == 1)
                teams++;
        }
        else
        {
            ans = min(ans, abil[right].first - abil[left].first);

            cnt[abil[left].second]--;
            if (cnt[abil[left].second] == 0)
                teams--;

            left++;
        }
    }

    cout << ans << '\n';
}