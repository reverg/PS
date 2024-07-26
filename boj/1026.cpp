#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int A[50], B[50];
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];

    sort(A, A + N, greater<int>());
    sort(B, B + N);

    int ans = 0;
    for (int i = 0; i < N; i++)
        ans += A[i] * B[i];

    cout << ans << '\n';
}