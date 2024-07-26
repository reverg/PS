#include <iostream>
#include <algorithm>

using namespace std;

int N;
int board[100000][3];
int max_path[3], min_path[3], tmp[3];

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> board[i][0] >> board[i][1] >> board[i][2];
    }
    for (int j = 0; j < 3; j++)
    {
        max_path[j] = board[0][j];
        min_path[j] = board[0][j];
    }
}

void dp()
{
    for (int i = 1; i < N; i++)
    {
        tmp[0] = max(max_path[0], max_path[1]) + board[i][0];
        tmp[1] = max({max_path[0], max_path[1], max_path[2]}) + board[i][1];
        tmp[2] = max(max_path[1], max_path[2]) + board[i][2];
        copy(tmp, tmp + 3, max_path);

        tmp[0] = min(min_path[0], min_path[1]) + board[i][0];
        tmp[1] = min({min_path[0], min_path[1], min_path[2]}) + board[i][1];
        tmp[2] = min(min_path[1], min_path[2]) + board[i][2];
        copy(tmp, tmp + 3, min_path);
    }

    int max_result = max({max_path[0], max_path[1], max_path[2]});
    int min_result = min({min_path[0], min_path[1], min_path[2]});
    cout << max_result << ' ' << min_result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    dp();
}