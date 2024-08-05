#include <iostream>
#include <set>

using namespace std;

string op;
int N, L, P, M;
int probLevel[100002];
set<int> probByLevel[102];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> P >> L;
        probLevel[P] = L;
        probByLevel[L].insert(P);
    }

    cin >> M;
    while (M--)
    {
        string op;
        cin >> op;

        if (op == "recommend")
        {
            int x;
            cin >> x;

            if (x == 1)
            {
                for (int i = 100; i >= 0; i--)
                {
                    if (probByLevel[i].empty())
                        continue;
                    cout << *(prev(probByLevel[i].end())) << '\n';
                    break;
                }
            }
            else
            {
                for (int i = 0; i < 101; i++)
                {
                    if (probByLevel[i].empty())
                        continue;
                    cout << *probByLevel[i].begin() << '\n';
                    break;
                }
            }
        }
        else if (op == "add")
        {
            cin >> P >> L;
            probLevel[P] = L;
            probByLevel[L].insert(P);
        }
        else if (op == "solved")
        {
            cin >> P;
            probByLevel[probLevel[P]].erase(P);
        }
    }
}

/*
문제번호만으로 제거하는 연산이 있어서 문제번호별 난이도
배열을 따로 가지고 있는게 편하다. 나머지는 set 활용하면 간단.
*/