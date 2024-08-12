#include <iostream>
#include <queue>

using namespace std;

int N;
char picture[100][101]; // one extra for '\0'
bool visited[100][100] = {false};
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

void BFS(int st_y, int st_x)
{
    queue<pair<int, int>> q;
    visited[st_y][st_x] = true;
    q.push({st_y, st_x});

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                continue;
            if (visited[ny][nx])
                continue;

            if (picture[y][x] == picture[ny][nx])
            {
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int j = 0; j < N; j++)
        cin >> picture[j];

    int human = 0;
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            if (!visited[j][i])
            {
                BFS(j, i);
                human++;
            }
        }
    }

    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            visited[j][i] = false;
            if (picture[j][i] == 'G')
                picture[j][i] = 'R';
        }
    }

    int cow = 0;
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            if (!visited[j][i])
            {
                BFS(j, i);
                cow++;
            }
        }
    }

    cout << human << ' ' << cow << '\n';
}