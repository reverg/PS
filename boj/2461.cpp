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

/*
(능력치, 학급) 정보로 줄 세우고 모든 학급이 들어가게
구간을 움직이면서 투 포인터를 사용하는 문제. 정렬이
들어가서 O(NM logNM + 2NM)이 된다. 우선순위 큐를
사용하는 방법도 있다. 각 반을 정렬하고 가장 작은 값들을
우선순위 큐에 넣어 비교하면 되지만 떠올릴 수만 있다면
투 포인터 풀이가 더 쉽다.
*/