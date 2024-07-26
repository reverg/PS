// reference: https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x16/solutions/1539.cpp
#include <iostream>
#include <set>

using namespace std;

int N;
int height[250005];
set<int> s;
long long ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    height[0] = 0;
    s.insert(0);
    height[N + 1] = 0;
    s.insert(N + 1);

    // height[A] = max(height[(A보다 작은 수들 중 최댓값)], height[(A보다 큰 수들 중 최솟값)]) + 1
    // 0 <= A <= N-1이라 처리를 편하기 위해 1을 더해서 1 ~ N 구간에 배치

    int a;
    cin >> a;
    a++;
    height[a] = 1;
    s.insert(a);
    ans = 1;

    for (int i = 1; i < N; i++)
    {
        cin >> a;
        a++;
        auto it = s.lower_bound(a);
        height[a] = max(height[*prev(it)], height[*it]) + 1;
        s.insert(a);

        ans += height[a];
    }

    cout << ans << '\n';
}