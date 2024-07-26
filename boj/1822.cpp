#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nA, nB;
    cin >> nA >> nB;

    set<int> A, B;
    for (int i = 0; i < nA; i++)
    {
        int tmp;
        cin >> tmp;
        A.insert(tmp);
    }
    for (int i = 0; i < nB; i++)
    {
        int tmp;
        cin >> tmp;
        auto pos = A.find(tmp);
        if (pos != A.end())
            A.erase(pos);
    }

    cout << A.size() << '\n';
    for (auto it = A.begin(); it != A.end(); it++)
        cout << *it << ' ';
}