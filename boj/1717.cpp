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

    int k, a, b;
    while (m--)
    {
        cin >> k >> a >> b;
        if (k == 0)
            unionSet(a, b);
        else
        {
            if (findSet(a) == findSet(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}