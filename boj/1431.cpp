#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum(string s)
{
    int n = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            n += s[i] - '0';
        }
    }
    return n;
}

bool compare(string a, string b)
{
    if (a.length() != b.length())
    {
        return a.length() < b.length();
    }
    else
    {
        int a_sum = sum(a);
        int b_sum = sum(b);
        if (a_sum != b_sum)
        {
            return a_sum < b_sum;
        }
        else
        {
            return a < b;
        }
    }
}

int main()
{
    int N;
    cin >> N;

    vector<string> v;
    string s;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        v.push_back(s);
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < N; i++)
    {
        cout << v[i] << '\n';
    }
}