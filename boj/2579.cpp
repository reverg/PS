#include <iostream>

using namespace std;

int score[301];
int step[301];

int stepping(int n)
{
    if (n == 1)
        return step[1];
    else
    {
        score[1] = step[1];
        score[2] = step[1] + step[2];
        for (int i = 2; i <= n; i++)
        {
            score[i] = step[i] + max(step[i - 1] + score[i - 3], score[i - 2]);
        }
        return score[n];
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> step[i];
    cout << stepping(n);
}