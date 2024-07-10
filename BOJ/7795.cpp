#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        cin >> N >> M;

        vector<int> v1, v2;
        for (int i = 0; i < N; i++)
        {
            int tmp;
            cin >> tmp;
            v1.push_back(tmp);
        }
        for (int i = 0; i < M; i++)
        {
            int tmp;
            cin >> tmp;
            v2.push_back(tmp);
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        int ptr1 = 0, ptr2 = 0;
        int ans = 0;
        for (ptr1 = 0; ptr1 < N; ptr1++)
        {
            while (ptr2 < M && v2[ptr2] < v1[ptr1])
            {
                ptr2++;
            }
            ans += ptr2;
        }

        cout << ans << '\n';
    }
}