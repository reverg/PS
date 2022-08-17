#include <iostream>
#include <string>
#include <vector>

using namespace std;

string text, pattern;
int n, m;
vector<int> pi;
vector<int> ans;

void getPi(string pattern)
{
    pi.resize(m, 0);
    int j = 0;

    for (int i = 1; i < m; i++)
    {
        while ((j > 0) && (pattern[i] != pattern[j]))
            j = pi[j - 1];

        if (pattern[i] == pattern[j])
            pi[i] = ++j;
    }
}

void KMP(string text, string pattern)
{
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        while ((j > 0) && (text[i] != pattern[j]))
            j = pi[j - 1];

        if (text[i] == pattern[j])
        {
            if (j == m - 1)
            {
                ans.emplace_back(i - j);
                j = pi[j];
            }
            else
                j++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    // https://bowbowbow.tistory.com/6
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);
    n = text.length();
    m = pattern.length();

    getPi(pattern);

    KMP(text, pattern);

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] + 1 << '\n';
}