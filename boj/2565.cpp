#include <iostream>

using namespace std;

int dst[501];
int line[501];

int electric(int max_start)
{
    int ans = 0;

    for (int i = 1; i <= max_start; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (dst[i] > dst[j])
                line[i] = max(line[i], line[j] + 1);
        }
        ans = max(ans, line[i]);
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int max_start = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        dst[a] = b;
        max_start = max(max_start, a);
    }
    cout << n - electric(max_start);
}

/*
i번째 지점에서 시작하는 전선을 사용할 때의 최대 전선 수는 i-1번째 지점까지의
결과들 중 i번째 지점 전선과 엇갈리지 않는 최대 개수 + 1이다. O(N^2)로 풀린다.
정렬하고 LIS 쓰면 O(NlogN)도 가능하다.
*/