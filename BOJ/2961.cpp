#include <iostream>
#include <climits>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    pair<int, int> taste[10];
    for (int i = 0; i < N; i++)
        cin >> taste[i].first >> taste[i].second;

    int ans = INT32_MAX;
    for (int tmp = 1; tmp < (1 << N); tmp++)
    {
        int sour = 1, bitter = 0;
        for (int i = 0; i < N; i++)
        {
            if ((tmp & (1 << i)) == 0)
                continue;
            sour *= taste[i].first;
            bitter += taste[i].second;
        }
        ans = min(ans, abs(sour - bitter));
    }

    cout << ans << '\n';
}