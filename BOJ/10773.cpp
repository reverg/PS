#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    stack<int> st;
    int x;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x != 0)
            st.push(x);
        else
            st.pop();
    }

    while(!st.empty())
    {
        sum += st.top();
        st.pop();
    }
    cout << sum;
}