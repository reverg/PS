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
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C;

    for (int i = 0; i < N; i++)
        cin >> house[i];

    sort(house, house + N);

    long long max_dist = house[N - 1] - house[0];
    cout << wifi(1, max_dist);
}

/*
공유기 설치 거리를 parametric search.
O(NlogM)으로 구해지는데, 200000 * 30 정도라
시간제한 2초 안에 충분히 들어온다.
*/