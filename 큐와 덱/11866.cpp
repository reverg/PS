#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    queue<int> q;
    for (int i = 1; i <= n; i++)
        q.push(i);

    int seq[1000];
    int idx = 0;

    while (q.size() > 0)
    {
        for (int i = 0; i < k - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
        seq[idx++] = q.front();
        q.pop();
    }

    cout << '<';
    for (int i = 0; i < n - 1; i++)
        cout << seq[i] << ", ";
    cout << seq[n - 1] << '>';
}