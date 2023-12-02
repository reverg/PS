#include <iostream>
#include <string>
#include <vector>
#define MAX 360000

using namespace std;

string text, pattern;
vector<int> pi;

void getPi(bool pattern[MAX])
{
    pi.resize(MAX, 0);
    int j = 0;

    for (int i = 1; i < MAX; i++)
    {
        while ((j > 0) && (pattern[i] != pattern[j]))
            j = pi[j - 1];

        if (pattern[i] == pattern[j])
            pi[i] = ++j;
    }
}

bool KMP(bool text[MAX * 2], bool pattern[MAX])
{
    int j = 0;

    for (int i = 0; i < MAX * 2; i++)
    {
        while ((j > 0) && (text[i] != pattern[j]))
            j = pi[j - 1];

        if (text[i] == pattern[j])
        {
            if (j == MAX - 1)
            {
                j = pi[j];
                return true;
            }
            else
                j++;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    // use clock1*2 as a text, clock2 as a pattern
    int n;
    bool clock1[MAX * 2];
    bool clock2[MAX];

    cin >> n;

    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        clock1[num] = clock1[num + MAX] = true;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        clock2[num] = true;
    }

    getPi(clock2);

    bool matches = (KMP(clock1, clock2));

    if (matches)
        cout << "possible\n";
    else
        cout << "impossible\n";
}