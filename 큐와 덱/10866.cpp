#include <iostream>
#include <deque>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    deque<int> dq;
    string inst;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> inst;
        if (inst == "push_back")
        {
            cin >> x;
            dq.push_back(x);
        }
        else if (inst == "push_front")
        {
            cin >> x;
            dq.push_front(x);
        }
        else if (inst == "pop_front")
        {
            if (!dq.empty())
            {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
            else
            {
                cout << "-1\n";
            }
        }
        else if (inst == "pop_back")
        {
            if (!dq.empty())
            {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
            else
            {
                cout << "-1\n";
            }
        }
        else if (inst == "size")
        {
            cout << dq.size() << '\n';
        }
        else if (inst == "empty")
        {
            if (dq.empty())
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
            if (!dq.empty())
            {
                cout << dq.front() << '\n';
            }
            else
            {
                cout << "-1\n";
            }
        }
        else if (inst == "back")
        {
            if (!dq.empty())
            {
                cout << dq.back() << '\n';
            }
            else
            {
                cout << "-1\n";
            }
        }
    }
}