#include <iostream>
#include <stack>

using namespace std;

bool isNice(string w)
{
    stack<char> st;
    if (w.length() % 2 != 0)
    {
        return false;
    }

    for (int i = 0; i < w.length(); i++)
    {
        if (st.empty() || st.top() != w[i])
        {
            st.push(w[i]);
        }
        else
        {
            st.pop();
        }
    }

    return st.empty() ? true : false;
}

int main()
{
    int N;
    cin >> N;

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        string w;
        cin >> w;
        if (isNice(w))
            ans += 1;
    }
    cout << ans << endl;
}