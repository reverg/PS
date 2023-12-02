#include <iostream>
using namespace std;

int cmp(const string word1, const string word2)
{
    if (word1.length() == word2.length())
    {
        int i = 0;

        while (word1[i] == word2[i] && i < word1.length())
            i++;

        if (i == word1.length())
            return 0;
        else
            return (word1[i] < word2[i]) ? 1 : -1;
    }

    else
        return (word1.length() < word2.length()) ? 1 : -1;
}

void merge(string word[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;

    string sorted[right - left + 1];
    int k = 0;

    while (i <= mid && j <= right)
    {
        if (cmp(word[i], word[j]) > 0)
            sorted[k++] = word[i++];
        else
            sorted[k++] = word[j++];
    }

    if (i > mid)
    {
        while (j <= right)
            sorted[k++] = word[j++];
    }
    else
    {
        while (i <= mid)
            sorted[k++] = word[i++];
    }

    for (int l = left; l <= right; l++)
        word[l] = sorted[l - left];
}

void merge_sort(string word[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(word, left, mid);
        merge_sort(word, mid + 1, right);
        merge(word, left, mid, right);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N;
    cin >> N;
    string word[N];

    for (int i = 0; i < N; i++)
    {
        cin >> word[i];
        cin.get();
    }

    merge_sort(word, 0, N - 1);

    cout << word[0] << '\n';
    for (int i = 1; i < N; i++)
    {
        if (cmp(word[i - 1], word[i]) != 0)
            cout << word[i] << '\n';
    }

    return 0;
}