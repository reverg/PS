#include <iostream>
#include <cmath>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;

    int sorted[right - left + 1];
    int k = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
            sorted[k++] = arr[i++];
        else
            sorted[k++] = arr[j++];
    }

    if (i > mid)
    {
        while (j <= right)
            sorted[k++] = arr[j++];
    }
    else
    {
        while (i <= mid)
            sorted[k++] = arr[i++];
    }

    for (int l = left; l <= right; l++)
        arr[l] = sorted[l - left];
}

void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int freq(int arr2[])
{

    int mode = 0;
    int modecnt = 0;
    bool scn_mode = false;

    for (int i = 0; i < 8001; i++)
    {
        if (modecnt < arr2[i])
            modecnt = arr2[i];
    }

    for (int i = 0; i < 8001; i++)
    {
        if (modecnt == arr2[i])
        {
            mode = i - 4000;

            if (scn_mode)
                break;

            scn_mode = true;
        }
    }

    return mode;
}

int main()
{
    int N;
    int sum = 0;

    cin>>N;

    int arr1[N];
    int arr2[8001]={0, }; //arr[i]에 i-4000이 나오는 횟수 저장

    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        arr1[i] = n;
        arr2[n + 4000]++;
        sum += n;
        cin.get();
    }

    merge_sort(arr1, 0, N - 1);

    int average = round(sum / (double)N);
    int median = arr1[N / 2];
    int mode = freq(arr2);
    int range = arr1[N - 1] - arr1[0];

    cout << average << endl
         << median << endl
         << mode << endl
         << range;

    return 0;
}