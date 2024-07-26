#include <iostream>
#include <queue>

using namespace std;

int N;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

int getSafeAreaNumber(int board[100][100], int precipitation)
{
    int visited[100][100] = {false};
    int safeAreaNumber = 0;
    queue<pair<int, int>> q;

    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            if (board[j][i] > precipitation && !visited[j][i])
            {
                visited[j][i] = true;
                q.push({j, i});
                while (!q.empty())
                {
                    int cy = q.front().first;
                    int cx = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++)
                    {
                        int ny = cy + dy[k];
                        int nx = cx + dx[k];
                        if (0 <= ny && ny < N && 0 <= nx && nx < N)
                        {
                            if (!visited[ny][nx] && board[ny][nx] > precipitation)
                            {
                                visited[ny][nx] = true;
                                q.push({ny, nx});
                            }
                        }
                    }
                }
                safeAreaNumber += 1;
            }
        }
    }

    return safeAreaNumber;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int precipitation = 0;
    int board[100][100];
    int max_altitude = 0;

    cin >> N;
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            cin >> board[j][i];
            max_altitude = max(board[j][i], max_altitude);
        }
    }

    int max_safe_area = 1;
    for (int i = 1; i <= max_altitude; i++)
    {
        max_safe_area = max(getSafeAreaNumber(board, i), max_safe_area);
    }

    cout << max_safe_area << '\n';
}