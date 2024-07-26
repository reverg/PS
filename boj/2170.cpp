#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<long long, long long>> v;
    for (int i = 0; i < N; i++)
    {
        long long start, end;
        cin >> start >> end;
        v.push_back({start, end});
    }

    sort(v.begin(), v.end());

    stack<pair<long long, long long>> st;
    st.push(v[0]);
    for (int i = 1; i < N; i++)
    {
        if (st.top().second >= v[i].first)
        {
            if (st.top().second < v[i].second)
            {
                pair<long long, long long> newLine = {st.top().first, v[i].second};
                st.pop();
                st.push(newLine);
            }
        }
        else
        {
            st.push(v[i]);
        }
    }

    long long ans = 0;
    while (!st.empty())
    {
        ans += st.top().second - st.top().first;
        st.pop();
    }

    cout << ans << '\n';
}