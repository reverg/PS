#include <iostream>
#include <set>
#include <tuple>

using namespace std;

int N, P, L, G, M;
pair<int, int> probLevel[100002];
set<int> probByL[102];
set<int> probByGL[102][102];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> P >> L >> G;
        probLevel[P] = {L, G};
        probByL[L].insert(P);
        probByGL[G][L].insert(P);
    }

    cin >> M;
    while (M--)
    {
        string op;
        cin >> op;
        if (op == "recommend")
        {
            int x;
            cin >> G >> x;
            if (x == 1)
            {
                for (int i = 100; i >= 1; i--)
                {
                    if (probByGL[G][i].empty())
                        continue;

                    cout << *(prev(probByGL[G][i].end())) << '\n';
                    break;
                }
            }
            else
            {
                for (int i = 1; i <= 100; i++)
                {
                    if (probByGL[G][i].empty())
                        continue;

                    cout << *(probByGL[G][i].begin()) << '\n';
                    break;
                }
            }
        }
        else if (op == "recommend2")
        {
            int x;
            cin >> x;
            if (x == 1)
            {
                for (int i = 100; i >= 1; i--)
                {
                    if (probByL[i].empty())
                        continue;

                    cout << *(prev(probByL[i].end())) << '\n';
                    break;
                }
            }
            else
            {
                for (int i = 1; i <= 100; i++)
                {
                    if (probByL[i].empty())
                        continue;

                    cout << *(probByL[i].begin()) << '\n';
                    break;
                }
            }
        }
        else if (op == "recommend3")
        {
            int x;
            cin >> x >> L;
            if (x == 1)
            {
                int probNum = -1;
                for (int i = L; i <= 100; i++)
                {
                    if (probByL[i].empty())
                        continue;

                    probNum = *(probByL[i].begin());
                    break;
                }
                cout << probNum << '\n';
            }
            else
            {
                int probNum = -1;
                for (int i = L - 1; i >= 0; i--)
                {
                    if (probByL[i].empty())
                        continue;

                    probNum = *(prev(probByL[i].end()));
                    break;
                }
                cout << probNum << '\n';
            }
        }
        else if (op == "add")
        {
            cin >> P >> L >> G;
            probLevel[P] = {L, G};
            probByL[L].insert(P);
            probByGL[G][L].insert(P);
        }
        else if (op == "solved")
        {
            cin >> P;
            tie(L, G) = probLevel[P];
            probByL[L].erase(P);
            probByGL[G][L].erase(P);
        }
    }
}