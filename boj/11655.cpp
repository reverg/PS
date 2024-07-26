#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    string s;
    getline(cin, s);

    for (int i = 0; i < s.length(); i++)
    {
        if ('a' <= s[i] && s[i] <= 'z')
        {
            s[i] = 'a' + (s[i] - 'a' + 13) % 26;
        }
        else if ('A' <= s[i] && s[i] <= 'Z')
        {
            s[i] = 'A' + (s[i] - 'A' + 13) % 26;
        }
    }

    cout << s;
}