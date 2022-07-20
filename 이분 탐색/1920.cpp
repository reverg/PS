#include <iostream>
#include <algorithm>

using namespace std;
int N[100000];

int bin_search(int m, int l, int r)
{
    if (l == r)
    {
        if (N[l] == m)
            return 1;
        else
            return 0;
    }
    else
    {
        int mid = (l + r) / 2;
        if (m <= N[mid])
            return bin_search(m, l, mid);
        else
            return bin_search(m, mid + 1, r);
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> N[i];
    }

    sort(N, N + n);

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        cout << bin_search(num, 0, n - 1) << '\n';
    }
}