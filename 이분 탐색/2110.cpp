#include <iostream>
#include <algorithm>

using namespace std;

int N, C;
long long house[200000];

long long wifi(long long l, long long r)
{
    if (l == r)
        return l;

    long long mid = (l + r + 1) / 2;
    long long start = house[0];
    long long dist = 0;
    int cnt = 1;

    for (int i = 1; i < N; i++)
    {
        dist = house[i] - start;
        if (mid <= dist)
        {
            cnt++;
            start = house[i];
        }
    }

    if (cnt < C)
        return wifi(l, mid - 1);
    else
        return wifi(mid, r);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> N >> C;

    for (int i = 0; i < N; i++)
        cin >> house[i];

    sort(house, house + N);

    long long max_dist = house[N - 1] - house[0];
    cout << wifi(1, max_dist);
}