#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int N;

    vector<pair<int, int>> v;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int start, end;
        cin >> start >> end;
        v.push_back({start, end});
    }

    sort(v.begin(), v.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(v[0].second);
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i].first >= pq.top())
        {
            pq.pop();
            pq.push(v[i].second);
        }
        else
        {
            pq.push(v[i].second);
        }
    }

    cout << pq.size() << '\n';
}