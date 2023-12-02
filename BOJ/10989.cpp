#include <iostream>
using namespace std;
#define MAX_NUM 10000

/*
void count_sort(int arr[], int N)
{
    int count[MAX_NUM + 1] = {
        0,
    };
   // int sorted[N + 1];

    for (int i = 0; i < N; i++)
        count[arr[i]]++;

    //for (int i = 1; i < MAX_NUM + 1; i++)
    //    count[i] += count[i - 1];

    //for (int i = N - 1; i >= 0; i--)
    //    sorted[count[arr[i]]--] = arr[i];

    //for (int i = 1; i <= N; i++)
    //    cout << sorted[i] << '\n';
    for(int i=1; i<=N; i++)
    {
        for(int j=0; j<count[i]; j++)
            cout<<i<<'\n';
    }
}
*/

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    //int arr[N];
    int count[MAX_NUM + 1] = {
        0,
    };

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        cin.get();
        count[num]++;
    }

    for (int i = 1; i <= 10000; i++)
    {
        for (int j = 0; j < count[i]; j++)
            cout << i << '\n';
    }

    return 0;
}