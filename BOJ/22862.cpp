#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    int S[N];
    for (int i = 0; i < N; i++)
        cin >> S[i];

    int ans = 0;
    int left = 0, right = 0, cnt = 0;
    while (right < N)
    {
        if (cnt <= K)
        {
            if (S[right] % 2 == 1)
                cnt++;
            right++;
        }
        else
        {
            while (S[left] % 2 == 0)
                left++;

            cnt--;
            left++;
        }

        ans = max(ans, right - left - cnt);
    }

    cout << ans << '\n';
}