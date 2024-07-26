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
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    string s1, s2;
    cin >> s1 >> s2;
    cout << LCS(s1, s2);
}