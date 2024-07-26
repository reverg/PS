// reference: https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x1E/solutions/4354.cpp
#include <iostream>
#include <vector>

using namespace std;

vector<int> failure(string &s)
{
    vector<int> f(s.size());
    int j = 0;
    for (int i = 1; i < s.size(); i++)
    {
        while (j > 0 && s[i] != s[j])
            j = f[j - 1];
        if (s[i] == s[j])
            f[i] = ++j;
    }
    return f;
}

int get_power(int len, string &s)
{
    int j = 0;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != s[j])
            return 0;

        j++;
        if (j == len)
        {
            j = 0;
            cnt++;
        }
    }

    return cnt;
}

void solve(string &s)
{
    vector<int> f = failure(s);

    int ans = 1;
    int len = s.size();
    while (true)
    {
        len = f[len - 1];
        if (len == 0)
            break;
        if (s.size() % len != 0)
            continue;
        int n = get_power(len, s);
        ans = max(ans, n);
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string S;
    cin >> S;
    while (S[0] != '.')
    {
        solve(S);
        cin >> S;
    }
}

/*
KMP.
f[|S|-1]이 접두사와 접미사가 겹치는 가장 긴 부분이므로,
부분 문자열의 후보들 중 가장 긴 경우가 된다.
여기부터 문자열 길이를 점점 줄여나가면서 확인한다.

매칭하고자 하는 문자열의 길이를 len이라 하자.
len이 0이면 반복되는 부분이 없으므로 A=S, n=1이다.
|S| % len != 0이면 매칭이 불가능하므로 시도하지 않는다.
|S| % len == 0이면 몇 번 반복되나 확인한다.

길이가 f[l]인 문자열 또한 반복되는 문자열 후보이므로
루프를 돌며 확인해준다. 길이가 0이 되면 멈추고,
지금까지의 n 중에 가장 큰 것이 답이다.
*/