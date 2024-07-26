#include <iostream>

using namespace std;

int R, C;
char board[20][20];
bool visited[26] = {false};
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int max_move = 0;

void input()
{
    cin >> R >> C;
    for (int j = 0; j < R; j++)
    {
        for (int i = 0; i < C; i++)
        {
            cin >> board[j][i];
        }
    }
}

bool onBoard(int y, int x)
{
    return ((0 <= y && y < R) && (0 <= x && x < C));
}

void backtrack(int y, int x, int move)
{
    max_move = max(max_move, move);

    for (int k = 0; k < 4; k++)
    {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if (onBoard(ny, nx))
        {
            int next_alphabet_num = board[ny][nx] - 'A';
            if (!visited[next_alphabet_num])
            {
                visited[next_alphabet_num] = true;
                backtrack(ny, nx, move + 1);
                visited[next_alphabet_num] = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    visited[board[0][0] - 'A'] = true;
    backtrack(0, 0, 1);

    cout << max_move << endl;
}