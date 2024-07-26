#include <iostream>
using namespace std;

int main()
{
    int N, M;
    cin>>N>>M;
    cin.get();

    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                if (sum < arr[i] + arr[j] + arr[k] && arr[i] + arr[j] + arr[k] <= M)
                    sum = arr[i] + arr[j] + arr[k];
            }
        }
    }

    cout << sum;

    return 0;
}