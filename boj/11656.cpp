#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    string s;
    cin >> s;

    vector<string> v;
    for (int i = 0; i < s.length(); i++)
    {
        v.emplace_back(s.substr(i));
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}