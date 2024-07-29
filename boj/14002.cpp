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
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    subsequence(n);
}

/*
dp 배열을 보고 역추적 하는 방식으로 구현해놨는데, 점화식에서
dp 값이 갱신될 때 값을 어디서 가져왔는지를 따로 저장해놨다가
마지막에 쭉 출력해줘도 된다. 범위가 작아서 O(N^2)로 가능.
*/