#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int A[2000];
    for (int i = 0; i < N; i++)
        cin >> A[i];
    sort(A, A + N);

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int left = 0, right = N - 1;
        while (left < right)
        {
            if (left == i)
            {
                left++;
                continue;
            }
            if (right == i)
            {
                right--;
                continue;
            }

            if (A[i] > A[left] + A[right])
            {
                left++;
            }
            else if (A[i] == A[left] + A[right])
            {
                ans++;
                break;
            }
            else
            {
                right--;
            }
        }
    }

    cout << ans << '\n';
}