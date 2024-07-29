#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int expression[11] = {0};
    expression[1] = 1;
    expression[2] = 2;
    expression[3] = 4;
    for (int i = 4; i < 11; i++)
        expression[i] = expression[i - 1] + expression[i - 2] + expression[i - 3];

    int T, N;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        cout << expression[N] << '\n';
    }
}