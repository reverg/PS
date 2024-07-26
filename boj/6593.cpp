#include <iostream>
#include <queue>

using namespace std;

int L, R, C;
int dz[6] = {-1, 0, 0, 0, 0, 1};
int dy[6] = {0, 0, -1, 0, 1, 0};
int dx[6] = {0, 1, 0, -1, 0, 0};

struct Coordinate
{
    int z;
    int y;
    int x;
};

inline bool inDungeon(int z, int y, int x)
{
    return (0 <= z && z < L) && (0 <= y && y < R) && (0 <= x && x < C);
}

int escape(char dungeon[30][30][30], Coordinate start, Coordinate end)
{
    int ellapsed_time = -1;
    queue<pair<Coordinate, int>> q;
    q.push({start, 0});

    while (!q.empty())
    {
        int cz = q.front().first.z;
        int cy = q.front().first.y;
        int cx = q.front().first.x;
        int ct = q.front().second;
        q.pop();

        for (int l = 0; l < 6; l++)
        {
            int nz = cz + dz[l];
            int ny = cy + dy[l];
            int nx = cx + dx[l];

            if (inDungeon(nz, ny, nx))
            {
                if (dungeon[nz][ny][nx] == '.')
                {
                    q.push({Coordinate{nz, ny, nx}, ct + 1});
                    dungeon[nz][ny][nx] = 'S';
                }
                if (dungeon[nz][ny][nx] == 'E')
                {
                    ellapsed_time = ct + 1;
                    goto success;
                }
            }
        }
    }

success:
    return ellapsed_time;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0)
            break;

        char dungeon[30][30][30];
        Coordinate start, end;
        for (int k = 0; k < L; k++)
        {
            for (int j = 0; j < R; j++)
            {
                for (int i = 0; i < C; i++)
                {
                    cin >> dungeon[k][j][i];
                    if (dungeon[k][j][i] == 'S')
                    {
                        start = Coordinate{k, j, i};
                    }
                    if (dungeon[k][j][i] == 'E')
                    {
                        end = Coordinate{k, j, i};
                    }
                }
            }
        }

        int ellapsed_time = escape(dungeon, start, end);
        if (ellapsed_time >= 0)
        {
            cout << "Escaped in " << ellapsed_time << " minute(s).\n";
        }
        else
        {
            cout << "Trapped!\n";
        }

        string empty_line;
        getline(cin, empty_line);
    }
}