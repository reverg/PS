#include <iostream>
int main()
{
    int h, m, time;
    std::cin >> h >> m;
    std::cin >> time;

    m += time;
    h = (h + (m / 60)) % 24;
    m = m % 60;

    std::cout << h << " " << m;

    return 0;
}