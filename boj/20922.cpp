#include <iostream>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    int A[1000000];
    for (int i = 0; i < N; i++)
        cin >> A[i];

    int ans = 0;
    int counter[200000] = {0};
    int left = 0, right = 0;
    while (right < N)
    {
        counter[A[right]]++;
        while (counter[A[right]] > K)
        {
            counter[A[left]]--;
            left++;
        }
        right++;
        ans = max(ans, right - left);
    }

    cout << ans << '\n';
}