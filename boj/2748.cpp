#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    long long f0 = 0, f1 = 1;
    if (N == 0)
    {
        cout << 0 << '\n';
    }
    else
    {
        for (int i = 2; i <= N; i++)
        {
            long long tmp = f0 + f1;
            f0 = f1;
            f1 = tmp;
        }

        cout << f1 << '\n';
    }
}