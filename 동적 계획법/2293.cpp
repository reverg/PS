#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int coin;
    int cases[10001] = {0};
    cases[0] = 1;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> coin;
        for (int j = coin; j <= k; j++)
            cases[j] += cases[j - coin];
    }

    cout << cases[k] << '\n';
}