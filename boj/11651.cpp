#include <iostream>
using namespace std;

typedef struct
{
    int x;
    int y;
} Pos;

bool cmp(const Pos &p1, const Pos &p2)
{
    if (p1.y == p2.y)
        return p1.x < p2.x;
    else
        return p1.y < p2.y;
}

void merge(Pos arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;

    Pos *sorted=new Pos[right - left + 1];
    int k = 0;

    while (i <= mid && j <= right)
    {
        if (cmp(arr[i], arr[j]))
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

void merge_sort(Pos arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N;
    cin >> N;
    Pos *arr = new Pos[N];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i].x >> arr[i].y;
        cin.get();
    }

    merge_sort(arr, 0, N-1);

    for (int i = 0; i < N; i++)
    {
        cout << arr[i].x << " " << arr[i].y << '\n';
    }

    return 0;
}