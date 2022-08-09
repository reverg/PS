#include <iostream>

using namespace std;

int N, M;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int T;
    cin >> T;

    int a, b;
    while (T--)
    {
        cin >> N >> M;
        for (int i = 0; i < M; i++)
            cin >> a >> b;
        cout << N - 1 << '\n';
    }
}