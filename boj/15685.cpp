#include <iostream>
#include <vector>

using namespace std;

int N;
int board[101][101];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while (N--)
    {
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        vector<int> v;
        v.push_back(d);
        board[y][x] = 1;

        while (g--)
        {
            for (int i = v.size() - 1; i >= 0; i--)
                v.push_back((v[i] + 1) % 4);
        }

        for (int i = 0; i < v.size(); i++)
        {
            int dir = v[i];
            if (dir == 0)
                x++;
            else if (dir == 1)
                y--;
            else if (dir == 2)
                x--;
            else if (dir == 3)
                y++;

            board[y][x] = 1;
        }
    }

    int cnt = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (!board[i][j])
                continue;

            if (board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1])
                cnt++;
        }
    }
    cout << cnt << '\n';
}

/*
세대가 증가할 때마다 기존 세대의 방향을 뒤부터 시계방향으로 90도 돌려서
추가해준다. 0 -> (0, 1) -> (0, 1, 2, 1) -> (0, 1, 2, 1, 2, 3, 2, 1)
*/