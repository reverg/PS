#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    long long part = -1000;
    long long ans = -1000;
    for (int i = 0; i < n; i++)
    {
        int z;
        cin >> z;
        part = (part > 0) ? part + z : z;

        if (part > ans)
            ans = part;
    }
    cout << ans << '\n';
}

/*
i번째 숫자를 끝으로 하는 연속합 S(i)를 생각하자.
연속된 수를 골라야 하므로 S(i)는 S(i-1) + i번째 수
또는 아니면 S(i-1)부분을 버리고 i번째 수만 넣는 방법으로
구성하게 된다. S(i-1)이 음수면 후자가 이득이고, 아니면
전자가 이득이다.
*/