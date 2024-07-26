#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int arr[1000];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N);

    vector<int> sum;
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            sum.push_back(arr[i] + arr[j]);
    sort(sum.begin(), sum.end());

    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int trg = arr[i] - arr[j];
            if (binary_search(sum.begin(), sum.end(), trg))
            {
                cout << arr[i] << '\n';
                return 0;
            }
        }
    }
}