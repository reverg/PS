#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    long long ans = 0;
    for (int i = 0; i < N - 1; i++)
    {
        long long a, b, c;
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        c = a + b;
        ans += c;
        pq.push(c);
    }

    cout << ans << '\n';
}