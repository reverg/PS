#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    string ps;
    for (int i = 0; i < n; i++)
    {
        stack<char> st;
        bool vps = true;
        cin >> ps;
        for (int j = 0; j < ps.length(); j++)
        {
            if (ps[j] == '(')
                st.push(ps[j]);
            else
            {
                if (st.empty())
                {
                    vps = false;
                    break;
                }
                else
                    st.pop();
            }
        }

        if (!st.empty())
            vps = false;

        if (vps)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}