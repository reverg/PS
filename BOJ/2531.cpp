#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, D, K, C;
    cin >> N >> D >> K >> C;

    vector<int> sushi;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        sushi.push_back(tmp);
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int cnt = 0;
        bool check[3001] = {false};

        for (int j = i; j < i + K; j++)
        {
            if (!check[sushi[j % N]])
            {
                check[sushi[j % N]] = true;
                cnt++;
            }
        }

        if (!check[C])
            cnt++;

        ans = max(ans, cnt);
    }

    cout << ans << '\n';
}