#include <iostream>
#include <vector>

using namespace std;

#define MAX 1001

int seq[MAX][MAX];
string s1, s2;

int LCS()
{
    for (int i = 1; i <= s1.length(); i++)
    {
        for (int j = 1; j <= s2.length(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                seq[i][j] = seq[i - 1][j - 1] + 1;
            }
            else
                seq[i][j] = max(seq[i - 1][j], seq[i][j - 1]);
        }
    }
    return seq[s1.length()][s2.length()];
}

void printSequence(int i, int j)
{
    if (seq[i][j] == 0)
        return;
    if (s1[i - 1] == s2[j - 1])
    {
        printSequence(i - 1, j - 1);
        cout << s1[i - 1];
    }
    else
        (seq[i - 1][j] > seq[i][j - 1]) ? printSequence(i - 1, j) : printSequence(i, j - 1);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> s1 >> s2;

    int len = LCS();
    cout << len << '\n';
    printSequence(s1.length(), s2.length());
}