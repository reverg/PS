#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

int main()
{
    int N;
    cin >> N;
    if (N == 0)
    {
        cout << 0 << '\n';
        return 0;
    }

    queue<ll> q;
    for (int i = 1; i <= 9; i++)
        q.push(i);

    ll ans = -1;
    while (!q.empty())
    {
        ll cur = q.front();
        q.pop();
        N--;

        if (N == 0)
        {
            ans = cur;
            break;
        }

        for (int i = 0; i < cur % 10; i++)
            q.push(cur * 10 + i);
    }

    cout << ans << '\n';
}