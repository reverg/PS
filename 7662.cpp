#include <iostream>
#include <set>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int t;
    std::cin >> t;

    int k;
    char op;
    int elem;
    while (t--)
    {
        std::cin >> k;
        std::multiset<int> ms;
        while (k--)
        {
            std::cin >> op >> elem;
            if (op == 'I')
            {
                ms.insert(elem);
            }
            else if (op == 'D' && !ms.empty())
            {
                if (elem < 0)
                {
                    ms.erase(ms.begin());
                }
                else
                {
                    auto iter = ms.end();
                    ms.erase(--iter);
                }
            }
        }
        if (ms.empty())
            std::cout << "EMPTY\n";
        else
        {
            auto end_iter = ms.end();
            std::cout << *(--end_iter) << ' ' << *ms.begin() << '\n';
        }
    }
}