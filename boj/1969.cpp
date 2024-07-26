#include <iostream>

using namespace std;

string acids = "ACGT";

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    int d[50][4] = {0};
    while (N--)
    {
        string s;
        cin >> s;
        for (int i = 0; i < M; i++)
        {
            int j = acids.find(s[i]);
            d[i][j]++;
        }
    }

    int hd = 0;
    for (int i = 0; i < M; i++)
    {
        int mx = 0;
        int idx = -1;
        for (int j = 0; j < 4; j++)
        {
            hd += d[i][j];
            if (mx < d[i][j])
            {
                mx = d[i][j];
                idx = j;
            }
        }
        hd -= mx;
        cout << acids[idx];
    }

    cout << '\n'
         << hd << '\n';
}