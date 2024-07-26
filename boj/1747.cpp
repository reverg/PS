#include <iostream>
#include <string>

using namespace std;

bool palindrome(int num)
{
    string s = to_string(num);
    int left = 0, right = s.length() - 1;
    while (left < right)
    {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}

int main()
{
    bool prime[2000001];
    fill(prime, prime + 2000001, true);
    prime[1] = false;
    for (int i = 2; i <= 1500; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= 2000000; j += i)
                prime[j] = false;
        }
    }

    int N;
    cin >> N;
    while (true)
    {
        if (prime[N] && palindrome(N))
            break;

        N++;
    }

    cout << N << '\n';
}