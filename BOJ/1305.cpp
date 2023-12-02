#include <iostream>
#include <string>
#include <vector>

using namespace std;

string text, pattern;
vector<int> pi;

void getPi(string pattern, int L)
{
    pi.resize(L + 1, 0);
    int j = 0;

    for (int i = 1; i < L; i++)
    {
        while ((j > 0) && (pattern[i] != pattern[j]))
            j = pi[j - 1];

        if (pattern[i] == pattern[j])
            pi[i] = ++j;
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    // can reduce L by length of common part of prefix & text end part
    int L;
    string text, pattern;

    cin >> L >> text;
    pattern = text;

    getPi(pattern, L);

    cout << L - pi[L - 1];
}