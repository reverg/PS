#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int parts[2] = {0};
    parts[s[0] - '0']++;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] != s[i - 1])
            parts[s[i] - '0']++;
    }

    cout << min(parts[0], parts[1]) << '\n';
}