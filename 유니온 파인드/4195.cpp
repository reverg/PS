#include <iostream>

using namespace std;

int parent[500001];

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
        parent[b] = a;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int a, b;
    int turn = 1;
    bool finished = false;
    while (m--)
    {
        cin >> a >> b;
        int parent_a = findSet(b);
        int parent_b = findSet(b);

        if (parent_a == parent_b)
        {
            finished = true;
            break;
        }
        else
        {
            unionSet(parent_a, parent_b);
            turn++;
        }
    }

    if (finished)
        cout << turn;
    else
        cout << '0';
}