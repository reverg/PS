#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < N; i++)
    {
        long long tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    for (int i = 0; i < M; i++)
    {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();

        pq.push(a + b);
        pq.push(a + b);
    }

    long long ans = 0;
    while (!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }

    cout << ans << '\n';
}