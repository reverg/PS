#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int i = 0; i < K; i++)
        {
            int tmp;
            cin >> tmp;
            pq.push(tmp);
        }

        long long ans = 0;
        for (int i = 0; i < K - 1; i++)
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
}