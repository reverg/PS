#include <iostream>

using namespace std;

int dst[501];
int line[501];

int electric(int max_str)
{
    int ans = 0;

    for (int i = 1; i <= max_str; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dst[i] > dst[j])
                // 여기가 아래로 나가면 전깃줄 없는 부분이 line[i] = 1 됨
                line[i] = max(line[i], line[j] + 1);
        }
        ans = max(ans, line[i]);
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, max_str = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        dst[a] = b;
        max_str = max(max_str, a);
    }
    cout << n - electric(max_str);
}