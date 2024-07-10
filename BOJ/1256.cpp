// reference: http://boj.kr/189891e34a774527af857b715027b275
#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
int comb[202][202];
vector<char> ans;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;

    for (int i = 1; i <= 200; i++)
    {
        comb[i][0] = 1;
        comb[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
            if (comb[i][j] > 1'000'000'000)
                comb[i][j] = 1'000'000'001; // 값이 1'000'000'000을 초과할 경우, 이후 연산에서의 overflow를 막기 위해 1'000'000'001로 설정
        }
    }

    while (N && M)
    {
        if (K > comb[N + M - 1][M])
        {
            K -= comb[N + M - 1][M];
            ans.push_back('z');
            M--;
        }
        else
        {
            ans.push_back('a');
            N--;
        }
    }

    while (N--)
        ans.push_back('a');
    while (M--)
        ans.push_back('z');

    if (K > 1)
        cout << -1;
    else
        for (auto c : ans)
            cout << c;
}

/*
N, M, k값을 감소시키며 가장 큰 자리수부터 문자를 확정해나간다.
현재 사용할 수 있는 'a'와 'z'의 개수가 각각 N, m개일 때, (N + M)번째 자리수의 문자가 'a'일 경우의 수는 (N + M - 1)C(M) 가지이다.
따라서 현재 k값이 이보다 클 경우 (N + M)번째 문자는 'z'로 확정할 수 있다.
*/