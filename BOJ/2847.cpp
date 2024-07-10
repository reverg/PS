#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int levels[100];
    for (int i = 0; i < N; i++)
        cin >> levels[i];

    int patches = 0;
    for (int i = N - 1; i >= 1; i--)
    {
        if (levels[i] <= levels[i - 1])
        {
            patches += levels[i - 1] - (levels[i] - 1);
            levels[i - 1] = levels[i] - 1;
        }
    }

    cout << patches << '\n';
}