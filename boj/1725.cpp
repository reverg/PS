#include <iostream>
#include <stack>

using namespace std;

long long h[100001] = {0};

long long rectangle(long long n)
{
    stack<int> s;
    long long ans = 0;

    for (int i = 0; i <= n; i++)
    {
        long long height_pos, width;
        // check rectangles before i-th bar
        // if rectangle sizes are increasing, don't need to check
        // h[n] < 0, so it checks all the rectangles ends in n-th bar
        while (!s.empty() && h[i] < h[s.top()])
        {
            // h[i-1] is the biggest one
            height_pos = s.top(); // monotone decreasing
            s.pop();

            if (s.empty())
                width = i;
            else
                width = i - s.top() - 1;

            ans = max(ans, width * h[height_pos]);
        }
        s.push(i);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    long long n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> h[i];
    h[n] = -1; // end point

    // get area in rectangle 0 <= # <= n
    cout << rectangle(n);
}