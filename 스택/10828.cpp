#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    stack<int> st;
    string inst;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> inst;
        if (inst == "push")
        {
            cin >> x;
            st.push(x);
        }
        else if (inst == "pop")
        {
            if (!st.empty())
            {
                cout << st.top() << '\n';
                st.pop();
            }
            else
            {
                cout << "-1\n";
            }
        }
        else if (inst == "size")
        {
            cout << st.size() << '\n';
        }
        else if (inst == "empty")
        {
            if (st.empty())
            {
                cout << "1\n";
            }
            else
            {
                cout << "0\n";
            }
        }
        else if (inst == "top")
        {
            if (!st.empty())
            {
                cout << st.top() << '\n';
            }
            else
            {
                cout << "-1\n";
            }
        }
    }
}