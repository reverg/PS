#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int N;
vector<int> v;
stack<int> LIS;
int num[1000001];
int dp[1000001];
int max_idx = 1;

int main()
{

    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> num[i];
        if (v.empty() || num[i] > v.back())
        {
            v.emplace_back(num[i]);
            dp[i] = v.size();
            max_idx = i;
        }
        else
        {
            int idx = lower_bound(v.begin(), v.end(), num[i]) - v.begin();
            v[idx] = num[i];
            dp[i] = idx + 1;
        }
    }

    // get the subsequence
    LIS.push(num[max_idx]);
    int cur = max_idx;
    for (int i = cur - 1; i >= 1; i--)
    {
        if (num[i] < num[cur] && dp[i] + 1 == dp[cur])
        {
            cur = i;
            LIS.push(num[i]);
        }
    }

    cout << v.size() << '\n';
    while (!LIS.empty())
    {
        cout << LIS.top() << ' ';
        LIS.pop();
    }
}