#include <iostream>
using namespace std;

typedef struct
{
    int age;
    string name;
} Member;

bool cmp(const Member &p1, const Member &p2)
{
    if (p1.age == p2.age)
        return true;
    else
        return p1.age < p2.age;
}

void merge(Member arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;

    Member *sorted=new Member[right - left + 1];
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

void merge_sort(Member arr[], int left, int right)
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
    Member *arr = new Member[N];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i].age >> arr[i].name;
        cin.get();
    }

    merge_sort(arr, 0, N-1);

    for (int i = 0; i < N; i++)
    {
        cout << arr[i].age << " " << arr[i].name << '\n';
    }

    return 0;
}