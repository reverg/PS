#include <iostream>

int main()
{
    int density;
    int line[6];
    std::cin >> density;
    for (int i = 0; i < 6; i++)
    {
        int dir;
        std::cin >> dir >> line[i];
    }

    int area = 0, elim_area = 0;
    for (int i = 0; i < 6; i++)
    {
        int x = line[i] * line[(i + 1) % 6];
        if (area < x)
        {
            area = x;
            elim_area = line[(i + 3) % 6] * line[(i + 4) % 6];
        }
    }
    std::cout << (area - elim_area) * density;
    return 0;
}