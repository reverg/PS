#include <iostream>

using namespace std;

long long N, K;

long long kth(long long l, long long r)
{
    if (l == r)
        return l;

    long long mid = (l + r) / 2;
    long long cnt = 0;

    for (long long i = 1; i <= N; i++)
    {
        if (mid / i == 0)
            break;
        cnt += min(mid / i, N);
    }

    if (cnt >= K)
        return kth(l, mid);
    else
        return kth(mid + 1, r);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    cout << kth(1, N * N);
}