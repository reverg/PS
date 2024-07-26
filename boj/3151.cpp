#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, A[10000];
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    sort(A, A + N);

    long long ans = 0;
    for (int i = 0; i < N - 2; i++)
    {
        for (int j = i + 1; j < N - 1; j++)
        {
            int t = -(A[i] + A[j]);
            ans += upper_bound(A + j + 1, A + N, t) - lower_bound(A + j + 1, A + N, t);
        }
    }

    cout << ans << '\n';
}