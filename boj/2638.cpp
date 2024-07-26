#include <iostream>
#include <queue>

using namespace std;

int N, M;
int board[100][100];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void input()
{
    cin >> N >> M;
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < M; i++)
        {
            cin >> board[j][i];
        }
    }
}

inline bool onboard(int y, int x)
{
    return ((0 <= y && y < N) && (0 <= x && x < M));
}

bool airCount()
{
    bool visited[100][100] = {false};
    int airTouch[100][100] = {0};

    queue<pair<int, int>> q;
    q.emplace(0, 0);
    visited[0][0] = true;

    while (!q.empty())
    {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = cur_y + dy[i];
            int nx = cur_x + dx[i];
            if (onboard(ny, nx) && !visited[ny][nx])
            {
                if (board[ny][nx] == 1)
                {
                    airTouch[ny][nx]++;
                }
                else
                {
                    q.emplace(ny, nx);
                    visited[ny][nx] = true;
                }
            }
        }
    }

    bool hasCheese = false;
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < M; i++)
        {
            if (airTouch[j][i] >= 2)
            {
                board[j][i] = 0;
                hasCheese = true;
            }
        }
    }

    return hasCheese;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    int result = 0;
    while(airCount())
    {
        result++;
    }

    cout << result << endl;
}