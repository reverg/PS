#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

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

/*
같은 동전을 여러 번 사용해도 되므로 1차원 dp를 bottom-up으로 써도 괜찮다.
자세한 내용은 #12865 주석 참조.
*/