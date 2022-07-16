#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    int x;
    int nge[1000001];
    stack<int> st, big;

    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        st.push(x);
    }

    for (int i = n; i >= 1; i--)
    {
        int st_top = st.top();
        while (!big.empty() && st_top >= big.top())
            big.pop();

        if (!big.empty())
            nge[i] = big.top();
        else
            nge[i] = -1;

        big.push(st_top);
        st.pop();
    }

    for (int i = 1; i <= n; i++)
        cout << nge[i] << ' ';
}