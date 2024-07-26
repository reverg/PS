#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    string s;
    cin >> s;

    int alphabets[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        alphabets[s[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        cout << alphabets[i] << ' ';
    }
}