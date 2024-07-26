#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    int train[100000];
    bool passed[1 << 20] = {false};

    cin >> N >> M;
    while (M--)
    {
        int op, t, s;
        cin >> op;
        switch (op)
        {
        case 1:
            cin >> t >> s;
            train[t - 1] |= (1 << (s - 1));
            break;
        case 2:
            cin >> t >> s;
            train[t - 1] &= (~(1 << (s - 1)));
            break;
        case 3:
            cin >> t;
            train[t - 1] <<= 1;
            train[t - 1] &= ((1 << 20) - 1);
            break;
        case 4:
            cin >> t;
            train[t - 1] >>= 1;
            break;
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (!passed[train[i]])
        {
            passed[train[i]] = true;
            ans++;
        }
    }

    cout << ans << '\n';
}