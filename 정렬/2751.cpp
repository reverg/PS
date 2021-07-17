#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;

    int sorted[right-left+1];
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
        merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        cin.get();
    }

    merge_sort(arr, 0, N - 1);

    for (int i = 0; i < N; i++)
        cout << arr[i] << '\n';

    return 0;
}