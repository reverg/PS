#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    string ps;
    while (true)
    {
        getline(cin, ps);
        if (ps == ".")
            break;

        stack<char> st;
        bool vps = true;

        for (int i = 0; i < ps.length(); i++)
        {
            if (ps[i] == '(' || ps[i] == '[')
                st.push(ps[i]);
            else if (ps[i] == ')')
            {
                if (st.empty() || st.top() != '(')
                {
                    vps = false;
                    break;
                }
                else
                    st.pop();
            }
            else if (ps[i] == ']')
            {
                if (st.empty() || st.top() != '[')
                {
                    vps = false;
                    break;
                }
                else
                    st.pop();
            }
        }

        if (!vps || !st.empty())
            cout << "no\n";
        else
            cout << "yes\n";
    }
}