#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int difficulty[300000];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> difficulty[i];
    sort(difficulty, difficulty + n);

    if (n == 0)
    {
        cout << 0;
        return 0;
    }

    int round = (int)(n * 0.15 + 0.5);
    int sum = 0;
    for (int i = round; i < n - round; i++)
        sum += difficulty[i];

    cout << (int)((double)sum / (n - 2 * round) + 0.5);
}