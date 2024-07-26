#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    stack<char> l;
    stack<char> r;
    for (int i = 0; i < s.size(); i++)
    {
        l.push(s[i]);
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        char inst;
        cin >> inst;
        switch (inst)
        {
        case 'L':
            if (!l.empty())
            {
                r.push(l.top());
                l.pop();
            }
            break;
        case 'D':
            if (!r.empty())
            {
                l.push(r.top());
                r.pop();
            }
            break;
        case 'B':
            if (!l.empty())
            {
                l.pop();
            }
            break;
        case 'P':
            char c;
            cin >> c;
            l.push(c);
            break;
        }
    }

    while (!l.empty())
    {
        r.push(l.top());
        l.pop();
    }
    while (!r.empty())
    {
        cout << r.top();
        r.pop();
    }
}