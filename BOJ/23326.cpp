#include <iostream>
#include <set>

using namespace std;

int N, Q;
set<int> s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;

    int t;
    for (int i = 1; i <= N; i++)
    {
        cin >> t;
        if (t == 1)
            s.insert(i);
    }

    int curr = 1;
    while (Q--)
    {
        cin >> t;
        switch (t)
        {
        case 1:
            cin >> t;
            if (s.find(t) != s.end())
                s.erase(t);
            else
                s.insert(t);
            break;
        case 2:
            cin >> t;
            curr = (curr + t - 1) % N + 1;
            break;
        case 3:
            if (s.empty())
                cout << -1 << '\n';
            else
            {
                set<int>::iterator it = s.lower_bound(curr);
                if (it != s.end())
                    cout << *it - curr << '\n';
                else
                    cout << N - curr + *s.begin() << '\n';
            }
        }
    }
}