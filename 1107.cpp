#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int trg_chn;
    std::cin >> trg_chn;

    int broken_button_num, num;
    bool broken_button[10] = {false};
    std::cin >> broken_button_num;
    for (int i = 0; i < broken_button_num; i++)
    {
        std::cin >> num;
        broken_button[num] = true;
    }

    int min_press = abs(trg_chn - 100);

    if (!broken_button[0])
    {
        min_press = std::min(min_press, 1 + trg_chn);
    }
    for (int i = 1; i <= 1000000; i++)
    {
        bool possible = true;
        int len = 0;
        for (int n = i; n > 0; n /= 10)
        {
            if (broken_button[n % 10])
            {
                possible = false;
                break;
            }
            len++;
        }

        if (possible)
        {
            if (min_press > len + abs(trg_chn - i))
                min_press = len + abs(trg_chn - i);
        }
    }

    std::cout << min_press << '\n';
}