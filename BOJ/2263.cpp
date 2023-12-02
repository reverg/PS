#include <iostream>

using namespace std;

int n;
int in[100001];
int in_idx[100001];
int post[100001];

void preOrder(int in_start, int in_end, int post_start, int post_end)
{
    if ((in_start > in_end) || (post_start > post_end))
        return;

    int root = post[post_end];
    cout << root << ' ';

    int mid = in_idx[root];

    preOrder(in_start, mid - 1, post_start, post_start + mid - in_start - 1);
    preOrder(mid + 1, in_end, post_start + mid - in_start, post_end - 1);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> in[i];
    for (int i = 1; i <= n; i++)
        cin >> post[i];
    for (int i = 1; i <= n; i++)
        in_idx[in[i]] = i;

    preOrder(1, n, 1, n);
}