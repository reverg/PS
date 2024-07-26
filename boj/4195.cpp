#include <iostream>
#include <string>
#include <map>

using namespace std;

int parent[200001];
int setSize[200001];

int findSet(int x)
{
    if (parent[x] == x)
        return x;
    else
        return parent[x] = findSet(parent[x]); // path compression
}

int getSetSize(int x)
{
    return setSize[findSet(x)];
}

void unionSet(int a, int b)
{
    a = findSet(a);
    b = findSet(b);
    if (a != b)
    {
        if (getSetSize(a) < getSetSize(b))
            swap(a, b);
        setSize[a] += setSize[b];
        parent[b] = a;
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t, f;
    cin >> t;
    while (t--)
    {
        cin >> f;
        for (int i = 1; i <= 2 * f + 1; i++)
        {
            parent[i] = i;
            setSize[i] = 1;
        }

        map<string, int> m;
        string p1, p2;
        int id = 1;
        for (int i = 1; i <= f; i++)
        {
            cin >> p1 >> p2;
            // give id to each person
            if (m.count(p1) == 0)
                m[p1] = id++;
            if (m.count(p2) == 0)
                m[p2] = id++;

            unionSet(m[p1], m[p2]);
            cout << getSetSize(m[p1]) << '\n';
        }
    }
}