#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int N;
vector<int> v;
stack<int> LIS;
int num[1000001];
int dp[1000001];
int max_idx = 1;

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> num[i];
        if (v.empty() || num[i] > v.back())
        {
            v.emplace_back(num[i]);
            dp[i] = v.size();
            max_idx = i;
        }
        else
        {
            int idx = lower_bound(v.begin(), v.end(), num[i]) - v.begin();
            v[idx] = num[i];
            dp[i] = idx + 1;
        }
    }

    // get the subsequence
    LIS.push(num[max_idx]);
    int cur = max_idx;
    for (int i = cur - 1; i >= 1; i--)
    {
        if (num[i] < num[cur] && dp[i] + 1 == dp[cur])
        {
            cur = i;
            LIS.push(num[i]);
        }
    }

    cout << v.size() << '\n';
    while (!LIS.empty())
    {
        cout << LIS.top() << ' ';
        LIS.pop();
    }
}

/*
LIS의 크기를 구하는 것은 #12738과 동일하다.
v의 몇 번째 자리에 삽입되었는지를 저장하는 dp[i]가 추가되었는데,
lower_bound로 순서대로 넣었으므로 dp 배열을 반대로 순회하면서
max_idx, ... , 1에 해당하는 값을 찾을 때마다 LIS의 원소로 쓰면 된다.
dp 값이 같은 원소들이 여럿 있을텐데, LIS 순위를 뒤에서 계속 덮어쓰므로
처음 만나는 원소만 고려하고 그 앞은 무시해주면 정상적인 결과가 나온다.
반대로 넣었으므로 stack에 넣었다가 다 꺼내는게 편하다.
*/