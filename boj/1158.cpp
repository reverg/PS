#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        q.push(i);
    }

    queue<int> ans;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < ((K - 1) % q.size()); j++)
        {
            int num = q.front();
            q.pop();
            q.push(num);
        }
        int elim = q.front();
        q.pop();
        ans.push(elim);
    }

    cout << '<';
    while (ans.size() != 1)
    {
        cout << ans.front() << ", ";
        ans.pop();
    }
    cout << ans.front() << ">\n";
}