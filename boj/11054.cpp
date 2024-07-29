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
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    cout << bitonic(n);
}

/*
각 원소별로 LIS와 LDS(?)의 길이를 구하고 합이 가장 큰 것을
고르면 된다. 선택한 원소가 중복돼서 들어가므로 1 빼야 한다.
O(N^2) LIS 사용해도 1000개밖에 안돼서 시간 충분.
*/