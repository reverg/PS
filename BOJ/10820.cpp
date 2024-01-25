#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    string s;

    while (getline(cin, s))
    {
        int lower = 0, upper = 0, num = 0, space = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if ('a' <= s[i] && s[i] <= 'z')
            {
                lower++;
            }
            else if ('A' <= s[i] && s[i] <= 'Z')
            {
                upper++;
            }
            else if ('0' <= s[i] && s[i] <= '9')
            {
                num++;
            }
            else
            {
                space++;
            }
        }

        cout << lower << ' ' << upper << ' ' << num << ' ' << space << endl;
    }
}