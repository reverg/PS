#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(string s1, string s2)
{
    if (s1.length() != s2.length())
        return s1.length() < s2.length();
    else
        return s1 < s2;
}

int main()
{
    int N;
    cin >> N;
    cin.ignore();

    vector<string> v;
    while (N--)
    {
        string s;
        getline(cin, s);
        for (int i = 0; i < s.length(); i++)
        {
            bool isNum = false;
            string tmp = "0";
            while ('0' <= s[i] && s[i] <= '9')
            {
                isNum = true;
                if (tmp == "0")
                {
                    if (s[i] != '0')
                        tmp = string(1, s[i]);
                }
                else
                    tmp += s[i];
                i++;
            }

            if (isNum)
                v.push_back(tmp);
        }
    }

    sort(v.begin(), v.end(), cmp);

    for (auto num : v)
        cout << num << '\n';
}
