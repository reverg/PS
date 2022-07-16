#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    queue<int> q;
    string inst;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> inst;
        if (inst == "push")
        {
            cin >> x;
            q.push(x);
        }
        else if (inst == "pop")
        {
            if (!q.empty())
            {
                cout << q.front() << '\n';
                q.pop();
            }
            else
            {
                cout << "-1\n";
            }
        }
        else if (inst == "size")
        {
            cout << q.size() << '\n';
        }
        else if (inst == "empty")
        {
            if (q.empty())
            {
                cout << "1\n";
            }
            else
            {
                cout << "0\n";
            }
        }
        else if (inst == "front")
        {
            if (!q.empty())
            {
                cout << q.front() << '\n';
            }
            else
            {
                cout << "-1\n";
            }
        }
        else if (inst == "back")
        {
            if (!q.empty())
            {
                cout << q.back() << '\n';
            }
            else
            {
                cout << "-1\n";
            }
        }
    }
}