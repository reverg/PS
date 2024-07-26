// reference: https://www.slideshare.net/slideshow/baekjoon-online-judge-1019/52810015
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void subCounting(int num, vector<ll> &count, int tenPower)
{
    while (num)
    {
        count[num % 10] += tenPower;
        num /= 10;
    }
}

void Solve(int end, vector<ll> &count)
{
    int start = 1;
    int tenPower = 1;

    while (start <= end)
    {
        while (start % 10 != 0 && start <= end)
        {
            subCounting(start, count, tenPower);
            start++;
        }

        if (end < start)
            return;

        while (end % 10 != 9 && start <= end)
        {
            subCounting(end, count, tenPower);
            end--;
        }

        start /= 10;
        end /= 10;

        for (int i = 0; i <= 9; i++)
            count[i] += (end - start + 1) * tenPower;
        tenPower *= 10;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<ll> count(10);

    Solve(N, count);

    for (auto &c : count)
        cout << c << ' ';
}
