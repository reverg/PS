#include <iostream>
#include <cmath>

using namespace std;

int n;
int s[20][20];
bool team1[20];
int diff_min = 1000000;

void team(int k, int pos)
{
    if (k == n / 2)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (team1[i] && team1[j])
                {
                    sum += s[i][j];
                    sum += s[j][i];
                }
                else if (!team1[i] && !team1[j])
                {
                    sum -= s[i][j];
                    sum -= s[j][i];
                }
            }
        }
        diff_min = min(diff_min, abs(sum));
        return;
    }

    for (int i = pos; i < n; i++)
    {
        if (n - pos < n / 2 - k)
            return;
        team1[i] = true;
        team(k + 1, i + 1);
        team1[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> s[i][j];
        }
    }

    team(0, 0);
    cout << diff_min;
}