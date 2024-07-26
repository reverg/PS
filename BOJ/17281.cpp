#include <iostream>
#include <algorithm>

using namespace std;

int N;
int board[50][9];
bool inEntry[9];
int order[9];
int max_score;

void playGame()
{
    int score = 0;
    int idx = 0;
    for (int inning = 0; inning < N; inning++)
    {
        bool bases[4] = {};
        int out = 0;
        while (out < 3)
        {
            bases[0] = true;
            int ruta = board[inning][order[idx]];
            idx = (idx + 1) % 9;

            if (ruta == 0)
                out++;
            else
            {
                for (int i = 3; i >= 0; i--)
                {
                    if (!bases[i])
                        continue;

                    if (i + ruta >= 4)
                        score++;
                    else
                        bases[i + ruta] = true;

                    bases[i] = false;
                }
            }
        }
    }

    max_score = max(max_score, score);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 9; j++)
            cin >> board[i][j];

    int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    order[3] = 0;
    do
    {
        copy(arr, arr + 3, order);
        copy(arr + 3, arr + 8, order + 4);
        playGame();
    } while (next_permutation(arr, arr + 8));

    cout << max_score << '\n';
}