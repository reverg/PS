#include <iostream>

uint div_conq(int N, uint r, uint c)
{
    if (N == 0)
        return 0;

    uint res = 0;
    uint block = (uint)1 << (2 * N - 2);
    int half = 1 << (N - 1);
    res += block * (2 * (r / half) + (c / half));
    res += div_conq(N - 1, r % half, c % half);
    return res;
}

int main()
{
    int N, r, c;
    std::cin >> N >> r >> c;
    std::cout << div_conq(N, r, c);
}