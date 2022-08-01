#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
string map[25];
bool visited[25][25] = {
    false,
};
vector<int> danji;
int cnt;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void dfs(int y, int x)
{
    visited[y][x] = true;
    cnt++;

    for (int k = 0; k < 4; k++)
    {
        int ny = y + dy[k];
        int nx = x + dx[k];

        if (0 <= nx && nx < N && 0 <= ny && ny < N)
        {
            if (map[ny][nx] == '1' && !visited[ny][nx])
                dfs(ny, nx);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> map[i];

    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            if (map[j][i] == '1' && !visited[j][i])
            {
                cnt = 0;
                dfs(j, i);
                danji.push_back(cnt);
            }
        }
    }

    sort(danji.begin(), danji.end());
    cout << danji.size() << '\n';
    for (int i = 0; i < danji.size(); i++)
        cout << danji[i] << '\n';
}