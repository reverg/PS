#include <iostream>

using namespace std;

int num[1001];
int increasing[1001];
int decreasing[1001];

void inc_seq(int n)
{
    for (int i = 1; i <= n; i++)
    {
        int max_part = 0;
        for (int j = 0; j < i; j++)
        {
            if (num[j] < num[i])
                max_part = max(max_part, increasing[j]);
        }
        increasing[i] = max_part + 1;
    }
}

void dec_seq(int n)
{
    decreasing[n] = 1;
    for (int i = n; i >= 1; i--)
    {
        int max_part = 0;
        for (int j = n; j > i; j--)
        {
            if (num[j] < num[i])
                max_part = max(max_part, decreasing[j]);
        }
        decreasing[i] = max_part + 1;
    }
}

int bitonic(int n)
{
    int ans = 0;
    inc_seq(n);
    dec_seq(n);
    for (int i = 1; i <= n; i++)
    {
        int bi_sum = increasing[i] + decreasing[i] - 1;
        if (bi_sum > ans)
            ans = bi_sum;
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
    cout << bitonic(n);
}