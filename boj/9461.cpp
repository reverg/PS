#include <iostream>

using namespace std;

long long len[101];

long long padovan(int n)
{
    if (len[n] != 0)
        return len[n];

    len[1] = len[2] = len[3] = 1;

    if (n <= 3)
        return len[n];
    else
    {
        for (int i = 4; i <= n; i++)
        {
            len[i] = len[i - 2] + len[i - 3];
        }
        return len[n];
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cout << padovan(n) << '\n';
    }
}