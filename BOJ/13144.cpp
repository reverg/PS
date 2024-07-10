#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    long long ans = 0;
    int counter[100001] = {0};
    long long left = 0, right = 0;
    while (right < N)
    {
        counter[arr[right]]++;
        while (counter[arr[right]] > 1)
        {
            counter[arr[left]]--;
            left++;
        }

        right++;
        ans += right - left;
    }

    cout << ans << '\n';
}