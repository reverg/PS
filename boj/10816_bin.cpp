#include <iostream>
#include <algorithm>

using namespace std;
int N[500002];

int upper(int m, int l, int r)
{
    if (l == r)
    {
        if (N[r] == m)
            return r;
        else
            return -1;
    }
    else
    {
        int mid = (l + r + 1) / 2;
        if (m < N[mid])
            return upper(m, l, mid - 1);
        else
            return upper(m, mid, r);
    }
}

int lower(int m, int l, int r)
{
    if (l == r)
    {
        if (N[l] == m)
            return l;
        else
            return -1;
    }
    else
    {
        int mid = (l + r) / 2;
        if (m <= N[mid])
            return lower(m, l, mid);
        else
            return lower(m, mid + 1, r);
    }
}

int bin_count(int m, int l, int r)
{
    if (upper(m, l, r) == -1 && lower(m, l, r) == -1)
    {
        return 0;
    }
    else
    {
        return upper(m, l, r) - lower(m, l, r) + 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> N[i];
    }

    sort(N + 1, N + n + 1);

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        cout << bin_count(num, 1, n) << ' ';
    }
}