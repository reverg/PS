#include <iostream>
#include <deque>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;
    cin >> N >> L;

    deque<pair<int, int>> dq;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        while (!dq.empty() && dq.front().second + L <= i)
        {
            dq.pop_front();
        }

        while (!dq.empty() && dq.back().first > num)
        {
            dq.pop_back();
        }

        dq.emplace_back(make_pair(num, i));

        cout << dq.front().first << ' ';
    }
}