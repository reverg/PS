#include <iostream>
#include <cstring>

using namespace std;

int seq[2001] = {0};
int palindrome[2001][2001] = {0};

int isPalindrome(int i, int j)
{
    if (palindrome[i][j] == -1)
    {
        if (i + 1 < j)
            palindrome[i][j] = (seq[i] == seq[j]) && isPalindrome(i + 1, j - 1);
        else if (i == j)
            palindrome[i][j] = 1;
        else if (i + 1 == j)
            palindrome[i][j] = (seq[i] == seq[j]);
    }

    return palindrome[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    memset(palindrome, -1, sizeof(palindrome));
    for (int i = 1; i <= n; i++)
    {
        cin >> seq[i];
    }

    int m, s, e;
    cin >> m;
    for (int j = 0; j < m; j++)
    {
        cin >> s >> e;
        cout << isPalindrome(s, e) << '\n';
    }
}