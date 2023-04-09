#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n;
    int arr[1001];
    arr[1] = 1, arr[2] = 2;

    std::cin >> n;
    for (int i = 3; i <= n; i++)
        arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;

    std::cout << arr[n] % 10007 << '\n';
}