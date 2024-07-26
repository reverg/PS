#include <iostream>

using namespace std;

int board[8][7] = {0};
bool visited[8][7] = {false};
bool domino[7][7] = {false}; // 01 ~ 66 domino
int dy[2] = {0, 1};
int dx[2] = {1, 0};

int backtrack(int y, int x)
{
    if (y == 8)
        return 1;

    int ny, nx;
    if (x == 6)
    {
        ny = y + 1;
        nx = 0;
    }
    else
    {
        ny = y;
        nx = x + 1;
    }

    if (visited[y][x])
    {
        return backtrack(ny, nx);
    }

    int cnt = 0;
    visited[y][x] = true;
    for (int k = 0; k < 2; k++)
    {
        int py = y + dy[k];
        int px = x + dx[k];
        if (py >= 8 || px >= 7 || visited[py][px])
            continue;

        if (!domino[board[y][x]][board[py][px]])
        {
            domino[board[y][x]][board[py][px]] = true;
            domino[board[py][px]][board[y][x]] = true;
            visited[py][px] = true;
            cnt += backtrack(ny, nx);
            visited[py][px] = false;
            domino[board[y][x]][board[py][px]] = false;
            domino[board[py][px]][board[y][x]] = false;
        }
    }
    visited[y][x] = false;
    return cnt;
}

int main()
{
    for (int j = 0; j < 8; j++)
    {
        for (int i = 0; i < 7; i++)
        {
            char c;
            cin >> c;
            board[j][i] = c - '0';
        }
    }

    cout << backtrack(0, 0) << '\n';
}