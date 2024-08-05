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

/*
3번 operation이 핵심. 배열을 쓰면 다음 명소를 찾는데 O(N)이지만,
set을 써서 lower_bound로 찾으면 O(logN)으로 해결된다. erase와
insert도 모두 O(logN)으로 해결되므로 구역과 쿼리가 많아도 괜찮다.ㄴ
*/