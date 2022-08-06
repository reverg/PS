#include <iostream>
#include <stack>

using namespace std;

int num[1001];
int subseq[1001];
int max_idx = 0;

void subsequence(int n)
{
    int ans = 0;
    // get max length of subsequence
    for (int i = 1; i <= n; i++)
    {
        int max_part = 0;
        for (int j = 0; j < i; j++)
        {
            if (num[j] < num[i])
                max_part = max(max_part, subseq[j]);
        }
        subseq[i] = max_part + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (ans < subseq[i])
        {
            ans = subseq[i];
            max_idx = i;
        }
    }

    // get the subsequence
    stack<int> LIS;
    LIS.push(num[max_idx]);
    int cur = max_idx;
    for (int i = max_idx - 1; i >= 1; i--)
    {
        if (num[i] < num[cur] && subseq[i] + 1 == subseq[cur])
        {
            cur = i;
            LIS.push(num[i]);
        }
    }

    cout << ans << '\n';
    while (!LIS.empty())
    {
        cout << LIS.top() << ' ';
        LIS.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    subsequence(n);
}