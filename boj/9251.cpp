#include <iostream>

using namespace std;

#define MAX 1001

int seq[MAX][MAX];

int LCS(string s1, string s2)
{
    for (int i = 1; i <= s1.length(); i++)
    {
        for (int j = 1; j <= s2.length(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
                seq[i][j] = seq[i - 1][j - 1] + 1;
            else
                seq[i][j] = max(seq[i - 1][j], seq[i][j - 1]);
        }
    }
    return seq[s1.length()][s2.length()];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    cout << LCS(s1, s2);
}

/*
seq[i][j] = s1의 i번째, s2의 j번째 글자까지 봤을 때 LCS 길이
글자가 같으면 직전까지의 LCS 길이에 +1, 다르면 s1의 1글자 전과
s2의 1글자 전 LCS 길이 중 긴 것 선택. 계단식으로 채워지므로
이전의 모든 경우를 자동적으로 확인하게 되어 최대임이 보장된다.
*/