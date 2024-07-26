#include <iostream>

using namespace std;

int N, K;
long long len[10000];

long long cut_cable(long long l, long long r)
{
    if (l == r)
        return l;

    long long mid = (l + r +) / 2;
    long long cnt = 0;
    long long ans;

    for (int i = 0; i < N; i++)
        cnt += len[i] / mid;
    if (cnt < K)
        return cut_cable(l, mid - 1);
    else
        return cut_cable(mid, r);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;
    long long max_len = 0;
    long long tot_len = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> len[i];
        max_len = max(max_len, len[i]);
    }

    cout << cut_cable(0, max_len);
}