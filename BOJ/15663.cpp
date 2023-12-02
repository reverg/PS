#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int num[9], print[9];
bool check[9];

void backtrack(int rem)
{
    if (rem == 0)
    {
        for (int i = M; i > 0; i--)
            cout << print[i] << ' ';
        cout << '\n';
        return;
    }

    int prev_num = 0;

    for (int i = 0; i < N; i++)
    {
        if (!check[i] && (prev_num != num[i]))
        {
            check[i] = true;
            print[rem] = num[i];
            prev_num = num[i];
            backtrack(rem - 1);
            check[i] = false;
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> num[i];
    sort(num, num + N);

    backtrack(M);

    return 0;
}