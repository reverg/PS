#include <iostream>

using namespace std;

int num[1001];
int subseq[1001];

int subsequence(int n)
{
    int ans = 0;
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
            ans = subseq[i];
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    cout << subsequence(n);
}