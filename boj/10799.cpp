#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    string batch;
    cin >> batch;

    stack<char> st;
    int ans = 0;
    for (int i = 0; i < batch.length(); i++)
    {
        if (batch[i] == '(')
            st.push('(');
        else if (batch[i] == ')')
        {
            if (batch[i - 1] == '(')
            {
                st.pop();
                ans += st.size();
            }
            else
            {
                st.pop();
                ans++;
            }
        }
    }

    cout << ans << endl;
}