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
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    cout << subsequence(n) << '\n';
}

/*
LIS의 O(N^2) 알고리즘. DP로 현재 위치를 포함하는 가장 긴 부분수열을
구하고, 처음부터 끝까지 한번 확인해 그 중 가장 긴 길이를 얻는다.
자신을 포함하는 가장 긴 부분수열의 길이는 앞에 나온 수들 중 자기보다
작은 수들의 부분수열 길이를 확인해 그 중 가장 긴 것의 길이 + 1로 구한다.
*/