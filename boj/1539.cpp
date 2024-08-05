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
    // 0 <= A <= N-1이라 처리를 편하게 하기 위해 1을 더해서 1 ~ N 구간에 배치

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

/*
새로 달릴 노드는 직전 노드 높이 + 1에 달리는데, 직전 노드는
해당 수보다 작은 수들 중 최댓값 또는 해당 수보다 큰 수들
중 최소값을 가진 노드이다. 그래서 둘 중 어디에 달릴지가 문제인데,
어차피 둘은 같은 줄기에 있어야 하기 때문에(중간에 부모가 있는 형태로
줄기가 꺾이면 부모가 해당 수보다 큰 수들 중 최소값을 차지하게 된다)
둘 중 높이가 더 큰 노드 다음에 매달린다. 아이디어를 잘 찾아야 하는 문제.
*/