// reference: https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x1E/solutions/16172.cpp
#include <iostream>
#include <vector>

using namespace std;

vector<int> f_func;

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

bool solve(string &s, string &k)
{
    int j = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            continue;

        while (j > 0 && s[i] != k[j])
            j = f_func[j - 1];
        if (s[i] == k[j])
            j++;

        if (j == (int)k.size())
            return 1;
    }
    return 0;
}

int main()
{
    string S, K;
    cin >> S >> K;

    f_func = failure(K);
    cout << solve(S, K) << '\n';
}

/*
KMP. 숫자 나오면 다음 i로 넘어가게 해뒀는데 그냥 숫자 뺀 문자열 만들어서 비교하는게 더 편하긴 함.
*/