#include <iostream>
#include <algorithm>

using namespace std;

int L, C;
char alp[26];
char pw[15];

void backtrack(int len, int pos, int vowels, int non_vowels)
{
    if (len == L)
    {
        if (vowels >= 1 && non_vowels >= 2)
        {
            for (int i = 0; i < L; i++)
                cout << pw[i];
            cout << '\n';
        }
        return;
    }

    for (int i = pos; i < C; i++)
    {
        pw[len] = alp[i];
        if (alp[i] == 'a' || alp[i] == 'e' || alp[i] == 'i' || alp[i] == 'o' || alp[i] == 'u')
            backtrack(len + 1, i + 1, vowels + 1, non_vowels);
        else
            backtrack(len + 1, i + 1, vowels, non_vowels + 1);
    }
}

int main()
{
    cin >> L >> C;
    for (int i = 0; i < C; i++)
        cin >> alp[i];
    sort(alp, alp + C);

    backtrack(0, 0, 0, 0);
}