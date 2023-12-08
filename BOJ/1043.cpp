#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool know[51] = {false};
int parent[51];
int first_men[51];

int findSet(int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    else
    {
        return parent[x] = findSet(parent[x]);
    }
}

void unionSet(int a, int b)
{
    a = findSet(a);
    b = findSet(b);
    if (b != a)
    {
        parent[b] = a;
        if (know[b])
        {
            know[a] = true;
        }
    }
}

void initialize()
{
    cin >> N >> M;
    int truth_num = 0;
    cin >> truth_num;
    for (int i = 0; i < truth_num; i++)
    {
        int num = 0;
        cin >> num;
        know[num] = true;
    }

    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
}

void makeParty()
{
    for (int i = 0; i < M; i++)
    {
        int num = 0;
        cin >> num;

        int first_man = 0;
        cin >> first_man;
        first_men[i] = first_man;
        for (int j = 1; j < num; j++)
        {
            int other_man = 0;
            cin >> other_man;
            unionSet(first_man, other_man);
        }
    }
}

int checkParty()
{
    int result = M;
    for (int i = 0; i < M; i++)
    {
        if (know[findSet(first_men[i])])
        {
            result--;
        }
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    initialize();
    makeParty();
    cout << checkParty() << endl;
}