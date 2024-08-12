#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> egg_stat;
int max_broken = 0;

void backtrack(int pos)
{
    if (pos == N)
    {
        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            if (egg_stat[i].first <= 0)
                cnt++;
        }
        max_broken = max(cnt, max_broken);
        return;
    }

    if (egg_stat[pos].first <= 0)
        backtrack(pos + 1);
    else
    {
        bool hit = false;
        for (int trg = 0; trg < N; trg++)
        {
            if (trg == pos || egg_stat[trg].first <= 0)
                continue;

            egg_stat[trg].first -= egg_stat[pos].second;
            egg_stat[pos].first -= egg_stat[trg].second;
            backtrack(pos + 1);
            hit = true;
            egg_stat[trg].first += egg_stat[pos].second;
            egg_stat[pos].first += egg_stat[trg].second;
        }

        if (!hit)
            backtrack(pos + 1);
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int t, w;
        cin >> t >> w;
        egg_stat.push_back({t, w});
    }

    backtrack(0);

    cout << max_broken << '\n';
}