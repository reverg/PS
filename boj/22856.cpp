#include <iostream>

using namespace std;

const int ROOT = 1;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int lc[100001], rc[100001], p[100001];
    cin >> N;
    p[ROOT] = -1;
    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        lc[a] = b;
        rc[a] = c;
        p[b] = p[c] = a;
    }

    int endpoint = ROOT;
    while (rc[endpoint] != -1)
        endpoint = rc[endpoint];

    int cur = ROOT;
    int cnt = -1;
    bool visited[100001] = {false};
    while (true)
    {
        cnt++;
        visited[cur] = true;

        if (lc[cur] != -1 && !visited[lc[cur]])
            cur = lc[cur];
        else if (rc[cur] != -1 && !visited[rc[cur]])
            cur = rc[cur];
        else
        {
            if (cur == endpoint)
                break;
            else
                cur = p[cur];
        }
    }

    cout << cnt << '\n';
}