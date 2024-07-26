#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int lab[8][8];
int simul[8][8];
vector<pair<int, int>> space;
vector<pair<int, int>> virus;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void input()
{
    cin >> N >> M;
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < M; i++)
        {
            cin >> lab[j][i];
            if (lab[j][i] == 0)
            {
                space.emplace_back(j, i);
            }
            else if (lab[j][i] == 2)
            {
                virus.emplace_back(j, i);
            }
        }
    }
}

void copyMap()
{
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < M; i++)
        {
            simul[j][i] = lab[j][i];
        }
    }
}

int spreadVirus()
{
    // BFS
    queue<pair<int, int>> q;
    for (int t = 0; t < virus.size(); t++)
    {
        q.emplace(virus[t]);
    }
    while (!q.empty())
    {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = cur_y + dy[i];
            int nx = cur_x + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M || simul[ny][nx] != 0)
                continue;

            simul[ny][nx] = 2;
            q.emplace(ny, nx);
        }
    }

    // get safe area size
    int safe_size = 0;
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < M; i++)
        {
            if (simul[j][i] == 0)
            {
                safe_size++;
            }
        }
    }

    return safe_size;
}

int getSafeAreaSize()
{
    int max_safe_size = 0;

    // set wall
    for (int i = 0; i < space.size() - 2; i++)
    {
        for (int j = i + 1; j < space.size() - 1; j++)
        {
            for (int k = j + 1; k < space.size(); k++)
            {
                copyMap();
                simul[space[i].first][space[i].second] = 1;
                simul[space[j].first][space[j].second] = 1;
                simul[space[k].first][space[k].second] = 1;
                int safe_size = spreadVirus();
                max_safe_size = max(max_safe_size, safe_size);
            }
        }
    }

    return max_safe_size;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    cout << getSafeAreaSize() << endl;
}