#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int TC;
    cin >> TC;

    while (TC--)
    {
        int N;
        int sticker[100001][2] = {0};
        int score[100001][2] = {0};
        cin >> N;
        for (int j = 0; j < 2; j++)
            for (int i = 1; i <= N; i++)
                cin >> sticker[i][j];

        score[1][0] = sticker[1][0];
        score[1][1] = sticker[1][1];
        for (int i = 2; i <= N; i++)
        {
            score[i][0] = max(score[i - 1][1], score[i - 2][1]) + sticker[i][0];
            score[i][1] = max(score[i - 1][0], score[i - 2][0]) + sticker[i][1];
        }
        cout << max(score[N][0], score[N][1]) << '\n';
    }
}