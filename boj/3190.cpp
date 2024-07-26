#include <iostream>
#include <deque>
#include <queue>
#include <tuple>

using namespace std;

int N, K, L;
int board[101][101];
deque<pair<int, int>> snake;
queue<pair<int, char>> cd;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    while (K--)
    {
        int r, c;
        cin >> r >> c;
        board[r][c] = 1;
    }

    cin >> L;
    while (L--)
    {
        int t;
        char d;
        cin >> t >> d;
        cd.push({t, d});
    }

    int dir = 0;
    int time = 1;
    snake.push_front({1, 1});
    board[1][1] = 2;

    while (true)
    {
        int chy, chx;
        tie(chy, chx) = snake.front();

        int nhy = chy + dy[dir];
        int nhx = chx + dx[dir];

        if (nhy <= 0 || nhy > N || nhx <= 0 || nhx > N) // 벽에 부딪힘
            break;
        if (board[nhy][nhx] == 2) // 자기 몸에 부딪힘
            break;

        if (board[nhy][nhx] == 1) // 사과 있음
        {
            snake.push_front({nhy, nhx});
            board[nhy][nhx] = 2;
        }
        else if (board[nhy][nhx] == 0) // 사과 없음
        {
            snake.push_front({nhy, nhx});
            board[nhy][nhx] = 2;

            int cty, ctx;
            tie(cty, ctx) = snake.back();
            snake.pop_back();
            board[cty][ctx] = 0;
        }

        if (cd.front().first == time)
        {
            if (cd.front().second == 'L')
                dir = (dir + 3) % 4;
            else
                dir = (dir + 1) % 4;
            cd.pop();
        }

        time++;
    }

    cout << time << '\n';
}