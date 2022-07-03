#include <iostream>

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;

    int money = 0;
    if (a == b && b == c)
    {
        money = 10000 + a * 1000;
    }
    else if (a == b)
    {
        money = 1000 + a * 100;
    }
    else if (b == c)
    {
        money = 1000 + b * 100;
    }
    else if (c == a)
    {
        money = 1000 + c * 100;
    }
    else
    {
        int max = a > b ? a : b;
        max = max > c ? max : c;
        money = max * 100;
    }
    std::cout << money;
    return 0;
}