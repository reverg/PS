#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<int> pq;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        if (num > 0)
            pq.push(num);
        else if (num == 0)
        {
            if (pq.empty())
            {
                cout << 0 << '\n';
                continue;
            }

            cout << pq.top() << '\n';
            pq.pop();
        }
    }
}