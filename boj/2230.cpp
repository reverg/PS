#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int A[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];
    sort(A, A + N);

    int ans = 2000000000;
    int left = 0, right = 1;
    while (right < N)
    {
        int diff = A[right] - A[left];
        if (diff < M)
        {
            right++;
            continue;
        }
        else if (diff == M)
        {
            cout << M << '\n';
            return 0;
        }
        else
        {
            ans = min(ans, diff);
            left++;
        }
    }

    cout << ans << '\n';
}

/*
투 포인터.
right, left가 0부터 N까지 가므로 O(2N)에 해결된다.
*/