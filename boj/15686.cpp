#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
vector<pair<int, int>> left_chicken;
int city[50][50];
int result = 99999999;

void input()
{
    cin >> N >> M;
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            cin >> city[j][i];
            if (city[j][i] == 2)
            {
                chicken.emplace_back(j, i);
            }
            else if (city[j][i] == 1)
            {
                house.emplace_back(j, i);
            }
        }
    }
}

int chickenDistance()
{
    int dist_sum = 0;
    for (int i = 0; i < house.size(); i++)
    {
        int min_dist = 100;
        for (int j = 0; j < M; j++)
        {
            int cur_dist = abs(house[i].first - left_chicken[j].first) + abs(house[i].second - left_chicken[j].second);
            min_dist = min(min_dist, cur_dist);
        }
        dist_sum += min_dist;
    }
    return dist_sum;
}

void destroyChicken(int cnt, int pos)
{
    if (cnt == M)
    {
        result = min(result, chickenDistance());
    }

    for (int i = pos; i < chicken.size(); i++)
    {
        if (chicken.size() - pos < M - cnt)
        {
            continue;
        }
        left_chicken.emplace_back(chicken[i]);
        destroyChicken(cnt + 1, i + 1);
        left_chicken.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    destroyChicken(0, 0);
    cout << result << endl;
}