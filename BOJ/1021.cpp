#include <iostream>
#include <deque>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    deque<int> dq;
    for (int i = 1; i <= n; i++)
        dq.push_back(i);

    int trg, cnt = 0;
    for (int i = 0; i < m; i++)
    {
        int rot = 0;
        cin >> trg;
        while (dq.front() != trg)
        {
            dq.push_back(dq.front());
            dq.pop_front();
            rot++;
        }
        cnt += (rot < dq.size() - rot) ? rot : dq.size() - rot;
        dq.pop_front();
    }
    cout << cnt;
}