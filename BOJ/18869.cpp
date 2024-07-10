// reference: https://codingnotes.tistory.com/175
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void compress(vector<int> &v)
{
    vector<int> ordered(v.size());
    copy(v.begin(), v.end(), ordered.begin());

    sort(ordered.begin(), ordered.end());
    ordered.erase(unique(ordered.begin(), ordered.end()), ordered.end()); // 와 이건 안 외우면 못 써먹을 듯

    for (int i = 0; i < v.size(); i++)
        v[i] = lower_bound(ordered.begin(), ordered.end(), v[i]) - ordered.begin();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin >> M >> N;

    vector<int> universe[M];
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int tmp;
            cin >> tmp;
            universe[i].push_back(tmp);
        }
        compress(universe[i]);
    }

    int ans = 0;
    for (int i = 0; i < M - 1; i++)
    {
        for (int j = i + 1; j < M; j++)
        {
            if (universe[i].size() == universe[j].size())
            {
                bool multiverse = true;
                for (int k = 0; k < universe[i].size(); k++)
                {
                    if (universe[i][k] != universe[j][k])
                        multiverse = false;
                }

                if (multiverse)
                    ans++;
            }
        }
    }

    cout << ans << '\n';
}