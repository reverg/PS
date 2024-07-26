#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int N;
priority_queue<int> max_pq;
priority_queue<int, vector<int>, greater<int>> min_pq;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        if (max_pq.size() <= min_pq.size())
            max_pq.push(num);
        else
            min_pq.push(num);

        if (!min_pq.empty() && max_pq.top() > min_pq.top())
        {
            min_pq.push(max_pq.top());
            max_pq.push(min_pq.top());
            min_pq.pop();
            max_pq.pop();
        }

        cout << max_pq.top() << '\n';
    }
}