#include <iostream>

using namespace std;

long long h[100001] = {0};

long long rectangle(long long left, long long right)
{
    if (right == left)
        return h[right];

    long long mid = (left + right) / 2;
    long long rec_max = max(rectangle(left, mid), rectangle(mid + 1, right));

    long long l = mid, r = mid + 1;
    long long mid_height = min(h[l], h[r]);
    long long mid_width = 2;
    long long mid_max = mid_height * mid_width;

    while (left <= l || r <= right)
    {
        bool right_end = (r == right);
        bool left_end = (l == left);

        if (right_end && left_end)
            break;

        bool extend_right = right_end ? false : (left_end || (h[l - 1] < h[r + 1]));
        if (extend_right)
            mid_height = min(mid_height, h[++r]);
        else
            mid_height = min(mid_height, h[--l]);
        mid_width++;

        mid_max = max(mid_max, mid_height * mid_width);
    }

    return max(rec_max, mid_max);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    while (true)
    {
        long long n;
        cin >> n;

        if (n == 0)
            break;

        for (long long i = 1; i <= n; i++)
            cin >> h[i];

        // get area in rectangle 0 < # <= n
        cout << rectangle(1, n) << '\n';
    }
}