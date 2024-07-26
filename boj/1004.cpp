#include <iostream>

int main()
{
    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++)
    {
        int start_x, start_y, dest_x, dest_y;
        std::cin >> start_x >> start_y >> dest_x >> dest_y;

        int n;
        std::cin >> n;
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            int c_x, c_y, r;
            std::cin >> c_x >> c_y >> r;
            bool start_in = true, dest_in = true;
            if ((start_x - c_x) * (start_x - c_x) + (start_y - c_y) * (start_y - c_y) > r * r)
            {
                start_in = false;
            }
            if ((dest_x - c_x) * (dest_x - c_x) + (dest_y - c_y) * (dest_y - c_y) > r * r)
            {
                dest_in = false;
            }
            if (start_in != dest_in)
                cnt++;
        }
        std::cout << cnt << std::endl;
    }
    return 0;
}