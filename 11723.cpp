#include <iostream>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int M;
    std::cin >> M;

    int set = 0;
    std::string op;
    int elem;
    for (int i = 0; i < M; i++)
    {
        std::cin >> op;
        if (op == "add")
        {
            std::cin >> elem;
            set |= (1 << elem);
        }
        else if (op == "remove")
        {
            std::cin >> elem;
            set &= ~(1 << elem);
        }
        else if (op == "check")
        {
            std::cin >> elem;
            int found = (set & (1 << elem)) ? 1 : 0;
            std::cout << found << '\n';
        }
        else if (op == "toggle")
        {
            std::cin >> elem;
            set ^= (1 << elem);
        }
        else if (op == "all")
            set = (1 << 21) - 1;
        else if (op == "empty")
            set = 0;
    }
}