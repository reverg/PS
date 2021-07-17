#include <iostream>
#include <algorithm>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;

    int sorted[right - left + 1];
    for(int i=0; i<right-left+1; i++)
        sorted[i]=2147483647;
    int k = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
            sorted[k++] = arr[i++];
        else if (arr[i] > arr[j])
            sorted[k++] = arr[j++];
        else
        {
            sorted[k++] = arr[i++];
            j++;
        }
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

int binarysearchIdx(int arr[], int n, int key)
{
    int start = 0;
    int end = n;
    int mid = n;

    while (end > start)
    {
        mid = (start + end) / 2;

        if (arr[mid] < key)
            start = mid + 1;
        else
            end = mid;
    }

    return end;
}

int main()
{
    int N;
    cin >> N;
    cin.get();
    int arr[N] = {
        0,
    };
    int carr[N] = {
        0,
    };
    int max = -2147483648;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        carr[i] = arr[i];
        if (max < arr[i])
            max = arr[i];
    }

    merge_sort(carr, 0, N - 1);

    int cnt = 0;
    for (cnt = 0; cnt < N; cnt++)
    {
        if (carr[cnt] == max)
            break;
    }

    for (int i = 0; i < N; i++)
        cout << binarysearchIdx(carr, cnt, arr[i]) << " ";

    return 0;
}