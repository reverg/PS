#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int N, M;
int ans = 0;
vector<pair<int, int>> cctv;
int room[8][8];
int room_copy[8][8];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool inBoard(int y, int x)
{
    return 0 <= y && y < N && 0 <= x && x < M;
}

void upd(int y, int x, int dir)
{
    dir %= 4;
    while (true)
    {
        x += dx[dir];
        y += dy[dir];

        if (!inBoard(y, x) || room_copy[y][x] == 6)
            break;
        if (room_copy[y][x] != 0)
            continue;

        room_copy[y][x] = 7;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int j = 0; j < N; j++)
        for (int i = 0; i < M; i++)
        {
            cin >> room[j][i];
            if (1 <= room[j][i] && room[j][i] <= 5)
                cctv.push_back({j, i});
            if (room[j][i] == 0)
                ans++;
        }

    for (int tmp = 0; tmp < (1 << (2 * cctv.size())); tmp++)
    {
        for (int j = 0; j < N; j++)
            for (int i = 0; i < M; i++)
                room_copy[j][i] = room[j][i];

        int brute = tmp;
        for (int i = 0; i < cctv.size(); i++)
        {
            int dir = brute % 4;
            brute /= 4;

            int y, x;
            tie(y, x) = cctv[i];
            switch (room[y][x])
            {
            case 1:
                upd(y, x, dir);
                break;
            case 2:
                upd(y, x, dir);
                upd(y, x, dir + 2);
                break;
            case 3:
                upd(y, x, dir);
                upd(y, x, dir + 1);
                break;
            case 4:
                upd(y, x, dir);
                upd(y, x, dir + 1);
                upd(y, x, dir + 2);
                break;
            case 5:
                upd(y, x, dir);
                upd(y, x, dir + 1);
                upd(y, x, dir + 2);
                upd(y, x, dir + 3);
                break;
            default:
                break;
            }

            int sagak = 0;
            for (int j = 0; j < N; j++)
                for (int i = 0; i < M; i++)
                    sagak += (room_copy[j][i] == 0);
            ans = min(ans, sagak);
        }
    }
    cout << ans << '\n';
}
