#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> child[51];
int root;
int del;

int countLeaf(int x)
{
    if (x == del) // 다 지워짐
        return 0;

    if (child[x].empty()) // r이 leaf
        return 1;

    if (child[x].size() == 1 && child[x][0] == del) // x가 leaf됨
        return 1;

    int ret = 0;
    for (auto nxt : child[x])
        ret += countLeaf(nxt);

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int p;
        cin >> p;
        if (p == -1)
            root = i;
        else
            child[p].push_back(i);
    }

    cin >> del;

    cout << countLeaf(root) << '\n';
}

/*
리프 노드를 지우면 부모가 리프 노드가 될 수 있다.
19~20행 처리 안해두면 del의 부모가 leaf가 됐을 때
ret가 0이 되어 오답이 된다.
*/