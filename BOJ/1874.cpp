#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    stack<int> st;
    vector<char> op;
    int x, biggest;
    bool available = true;

    cin >> x;
    biggest = x;
    for (int i = 1; i < x; i++)
    {
        op.push_back('+');
        st.push(i);
    }
    op.push_back('+');
    op.push_back('-');

    for (int i = 2; i <= n; i++)
    {
        cin >> x;
        int cur = st.empty() ? 0 : st.top();
        if (cur == x)
        {
            op.push_back('-');
            st.pop();
        }
        else if (cur < x)
        {
            for (int j = biggest + 1; j < x; j++)
            {
                op.push_back('+');
                st.push(j);
            }
            op.push_back('+');
            op.push_back('-');
            biggest = x;
        }
        else
        {
            available = false;
            break;
        }
    }

    if (!available)
    {
        cout << "NO";
    }
    else
    {
        for (int i = 0; i < op.size(); i++)
            cout << op[i] << '\n';
    }
}