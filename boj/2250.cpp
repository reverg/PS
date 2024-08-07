#include <iostream>
#include <vector>

using namespace std;

int N;
int root;
int p[10005];
int lc[10005], rc[10005];
int order = 1;
int treeStat[10005][2];

void inorder(int cur, int depth)
{
    if (lc[cur] != -1)
        inorder(lc[cur], depth + 1);

    if (treeStat[depth][0] == 0)
        treeStat[depth][0] = order;
    else
        treeStat[depth][1] = order;
    order++;

    if (rc[cur] != -1)
        inorder(rc[cur], depth + 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, l, r;
        cin >> x >> l >> r;
        lc[x] = l;
        rc[x] = r;
        p[l] = p[r] = x;
    }

    // find root first
    for (int i = 1; i <= N; i++)
    {
        if (p[i] == 0)
        {
            root = i;
            break;
        }
    }

    inorder(root, 1);

    int ans_level = 1;
    int ans_width = 0;
    for (int i = 1; i <= 10004; i++)
    {
        if (treeStat[i][0] == 0)
            break;

        int width = (treeStat[i][1] == 0 ? 1 : treeStat[i][1] - treeStat[i][0] + 1);
        if (ans_width < width)
        {
            ans_width = width;
            ans_level = i;
        }
    }

    cout << ans_level << ' ' << ans_width << '\n';
}

/*
inorder 순회시 도착 순서가 x좌표, level이 y좌표다.
level별 최소/최대 좌표를 treeStat[depth]에 저장하고
둘의 차이가 가장 큰 level을 찾았다. 최대 좌표가 기록
안 되어있으면 너비는 1임에 유의. 트리 순회를 1번하므로
O(V+E) 시간에 풀린다. level 구하는 부분은 V보다 적다.
*/