#include <iostream>

using namespace std;
int sum[26][200002] = {
    0,
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    string s;
    int q;
    cin >> s >> q;

    for (int i = 1; i <= s.size(); i++)
    {
        sum[s[i - 1] - 'a'][i]++;
        for (int j = 0; j < 26; j++)
        {
            sum[j][i] += sum[j][i - 1];
        }
    }

    char a;
    int l, r;
    for (int i = 0; i < q; i++)
    {
        cin >> a >> l >> r;
        cout << sum[a - 'a'][r + 1] - sum[a - 'a'][l] << '\n';
    }
}