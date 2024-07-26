#include <iostream>
#include <vector>
#include <cstring>

#define MAX 19 // ceil(log_2(n))

using namespace std;

int parent[200001][MAX];
int m, q;

void sparseTable(int m)
{
    for (int k = 1; k < MAX; k++)
    {
        for (int cur = 1; cur <= m; cur++)
        {
            // recursive: 2^k = 2^(k-1) + 2^(k-1)
            parent[cur][k] = parent[parent[cur][k - 1]][k - 1];
        }
    }
}

int getf(int n, int x)
{
    for (int ind = 0; n != 0; ind++)
    {
        if (n & 1)
            x = parent[x][ind];

        n = n >> 1;
    }
    return x;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> parent[i][0];

    sparseTable(m);

    cin >> q;
    while (q--)
    {
        int n, x;
        cin >> n >> x;
        cout << getf(n, x) << '\n';
    }
}