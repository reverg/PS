#include <iostream>

using namespace std;

int parent[1000001];

int findSet(int x)
{
    if (parent[x] == x)
        return x;
    else
        return parent[x] = findSet(parent[x]); // path compression
}

void unionSet(int a, int b)
{
    a = findSet(a);
    b = findSet(b);
    if (a != b)
        parent[a] = b;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int connected;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> connected;
            if (connected)
                unionSet(i, j);
        }
    }

    int dst;
    cin >> dst;
    int head = findSet(dst);

    bool avail = true;
    for (int i = 2; i <= m; i++)
    {
        cin >> dst;
        if (head != findSet(dst))
        {
            avail = false;
        }
    }

    if (avail)
        cout << "YES";
    else
        cout << "NO";
}