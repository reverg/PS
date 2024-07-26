// reference: https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x1E/solutions/11585.cpp
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int N;
string R, M;

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

int main()
{
    cin >> N;

    char input[N];
    for (int i = 0; i < N; i++)
        cin >> input[i];
    string R(input);

    for (int i = 0; i < N; i++)
        cin >> input[i];
    string M(input);

    vector<int> f = failure(M);

    // 원형 룰렛에서 KMP
    int cnt = 0;
    int j = 0;
    for (int i = 0; i < 2 * N - 1; i++)
    {
        int ci = i;
        if (ci >= N)
            ci -= N;

        while (j > 0 && R[ci] != M[j])
            j = f[j - 1];
        if (R[ci] == M[j])
            j++;
        if (j == N)
        {
            cnt++;
            j = f[j - 1];
        }
    }

    int g = gcd(cnt, N);
    cout << (cnt / g) << '/' << (N / g) << '\n';
}

/*
KMP를 원형 룰렛에서 돌리는 문제다.
0 ~ N-1번 위치에서 시작할 수 있으므로 i를 (2*N - 1)까지로 놓으면 된다.
*/