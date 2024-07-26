#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, A[1000000];
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    int left = 0, right = N - 1;
    int chval = 2000000000;
    while (left < right)
    {
        int s = A[left] + A[right];
        if (abs(chval) > abs(s))
            chval = s;

        if (s < 0)
            left++;
        else if (s > 0)
            right--;
        else
            break;
    }

    cout << chval << '\n';
}