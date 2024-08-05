#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    int k;
    char op;
    int elem;
    while (t--)
    {
        cin >> k;
        multiset<int> ms;
        while (k--)
        {
            cin >> op >> elem;
            if (op == 'I')
                ms.insert(elem);
            else if (op == 'D')
            {
                if (ms.empty())
                    continue;

                if (elem < 0)
                    ms.erase(ms.begin());
                else
                    ms.erase(prev(ms.end()));
            }
        }

        if (ms.empty())
            cout << "EMPTY\n";
        else
            cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
    }
}

/*
multiset을 사용하는 문제. 원소로 erase하면 똑같은거 다 지워지므로
find 등을 써서 iterator를 인자로 넘겨야 한다.
*/