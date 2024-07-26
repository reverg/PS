#include <iostream>

using namespace std;

int N, M;
long long len[1000000];

long long cut_tree(long long l, long long r)
{
    if (l == r)
        return l;

    long long mid = (l + r + 1) / 2;
    long long cut = 0;

    for (int i = 0; i < N; i++)
    {
        cut += max(len[i] - mid, (long long)0);
        if (cut > M)
            break;
    }

    if (cut < M)
        return cut_tree(l, mid - 1);
    else
        return cut_tree(mid, r);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    long long max_len = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> len[i];
        max_len = max(max_len, len[i]);
    }

    cout << cut_tree(0, max_len);
}