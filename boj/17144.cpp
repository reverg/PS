#include <iostream>
#include <vector>

using namespace std;

int R, C, T;
int room[50][50];

vector<int> cleaner;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void input()
{
    cin >> R >> C >> T;
    for (int j = 0; j < R; j++)
    {
        for (int i = 0; i < C; i++)
        {
            cin >> room[j][i];
            if (room[j][i] == -1)
                cleaner.emplace_back(j);
        }
    }
}

int checkRoom()
{
    int result = 0;
    for (int j = 0; j < R; j++)
    {
        for (int i = 0; i < C; i++)
        {
            if (room[j][i] > 0)
                result += room[j][i];
        }
    }

    return result;
}

inline bool inBoard(int y, int x)
{
    return ((0 <= y && y < R) && (0 <= x && x < C));
}

void spread()
{
    int spread[50][50] = {0};
    for (int y = 0; y < R; y++)
    {
        for (int x = 0; x < C; x++)
        {
            if (room[y][x] == -1)
                continue;

            int spread_dust = room[y][x] / 5;
            for (int k = 0; k < 4; k++)
            {
                int ny = y + dy[k];
                int nx = x + dx[k];
                if (inBoard(ny, nx) && room[ny][nx] != -1)
                {
                    room[y][x] -= spread_dust;
                    spread[ny][nx] += spread_dust;
                }
            }
        }
    }

    for (int y = 0; y < R; y++)
    {
        for (int x = 0; x < C; x++)
        {
            room[y][x] += spread[y][x];
        }
    }
}

void circulate()
{
    int cleaner_y1 = cleaner[0];
    int cleaner_y2 = cleaner[1];

    // direction 1
    for (int i = cleaner_y1 - 1; i > 0; i--)
        room[i][0] = room[i - 1][0];
    for (int i = cleaner_y2 + 1; i < R - 1; i++)
        room[i][0] = room[i + 1][0];

    // direction 2
    for (int i = 0; i < C - 1; i++)
    {
        room[0][i] = room[0][i + 1];
        room[R - 1][i] = room[R - 1][i + 1];
    }

    // direction 3
    for (int i = 0; i < cleaner_y1; i++)
        room[i][C - 1] = room[i + 1][C - 1];

    for (int i = R - 1; i > cleaner_y2; i--)
        room[i][C - 1] = room[i - 1][C - 1];

    // direction 4
    for (int i = C - 1; i >= 2; i--)
    {
        room[cleaner_y1][i] = room[cleaner_y1][i - 1];
        room[cleaner_y2][i] = room[cleaner_y2][i - 1];
    }
    room[cleaner_y1][1] = room[cleaner_y2][1] = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    for (int i = 0; i < T; i++)
    {
        spread();
        circulate();
    }
    cout << checkRoom() << endl;
}