#include <iostream>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    int ans;
    int cnt = 0;
    bool checked[1001] = {false};
    for (int i = 2; i <= N; i++)
    {
        for (int j = i; j <= N; j += i)
        {
            if (checked[j])
                continue;

            checked[j] = true;
            cnt++;

            if (cnt == K)
            {
                cout << j << '\n';
                return 0;
            }
        }
    }
}