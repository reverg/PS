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
        return x;
    else
        return parent[x] = findSet(parent[x]);
}

void unionSet(int a, int b)
{
    a = findSet(a);
    b = findSet(b);
    if (b != a)
    {
        parent[b] = a;
        if (know[b])
            know[a] = true;
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
            result--;
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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
        parent[i] = i;

    makeParty();

    cout << checkParty() << endl;
}

/*
union-find 문제. 진실을 아는 사람과 n다리 건너
연결된 사람들 모두한테 거짓말을 하면 안된다.
N이 작아서 같은 파티에 참석한 사람들 모두에 간선을
잇고 bfs를 돌려 진실을 전파한 뒤, 모든 파티에 대해
참석자 모두가 진실을 모르는지 확인해 카운팅해도 된다.
*/