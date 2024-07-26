#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int origin[50][50];
int board[50][50];
vector<pair<int, int>> vp;
bool not_use[10];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
int min_time = 2500;

void spread_virus()
{
    for (int j = 0; j < N; j++)
        copy(origin[j], origin[j] + N, board[j]);

    queue<pair<int, int>> q;
    for (int i = 0; i < vp.size(); i++)
        if (!not_use[i])
            q.push(vp[i]);

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int ny = cur.first + dy[k];
            int nx = cur.second + dx[k];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                continue;
            if (board[ny][nx] != 0)
                continue;

            board[ny][nx] = board[cur.first][cur.second] + 1;
            q.push({ny, nx});
        }
    }

    int spread_time = 0;
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            if (board[j][i] == 0)
                spread_time = 2502;
            spread_time = max(spread_time, board[j][i]);
        }
        if (spread_time == 2502)
            break;
    }

    min_time = min(min_time, spread_time - 2);
}

void backtrack(int cnt, int pos)
{
    if (cnt == 0)
    {
        spread_virus();
        return;
    }

    for (int i = pos; i < vp.size(); i++)
    {
        if (not_use[i])
            continue;

        origin[vp[i].first][vp[i].second] = 0;
        not_use[i] = true;
        backtrack(cnt - 1, i + 1);
        origin[vp[i].first][vp[i].second] = 2;
        not_use[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            cin >> origin[j][i];
            if (origin[j][i] == 2)
                vp.push_back({j, i});
        }
    }

    backtrack(vp.size() - M, 0);

    if (min_time == 2500)
        cout << -1 << '\n';
    else
        cout << min_time << '\n';
}

/*
바이러스를 놓지 않을 곳들을 골라서 0으로 바꿔주는 backtracking을 했음.
사실 96번째 줄에서 origin[j][i] = 0 만들고 평범하게 하면 됐었음...
backtracking 말고 {1...1, 0...0} 만들어서 next_permutation 쓰는 것도 가능.
*/