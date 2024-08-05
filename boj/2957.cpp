#include <iostream>
#include <set>

using namespace std;

int N;
int depth[300002];
set<int> bst;
long long cnt;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    // To avoid exception handling
    // for bst.begin(), bst.end()
    bst.insert(0);
    bst.insert(N + 1);

    int root;
    cin >> root;
    bst.insert(root);
    depth[root] = 0;
    cnt += depth[root];
    cout << cnt << '\n';

    for (int i = 1; i < N; i++)
    {
        int num;
        cin >> num;

        auto it = bst.lower_bound(num);
        depth[num] = max(depth[*prev(it)], depth[*it]) + 1;
        bst.insert(num);
        cnt += depth[num];

        cout << cnt << '\n';
    }
}

/*
#1539와 거의 동일.
*/