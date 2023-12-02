#include <iostream>

int main()
{
    int W, H, X, Y, P;
    std::cin >> W >> H >> X >> Y >> P;
    int center_y = Y + (H / 2);
    int cnt = 0;
    for (int i = 0; i < P; i++)
    {
        int p_x, p_y;
        std::cin >> p_x >> p_y;
        if ((X <= p_x && p_x <= X + W) && (Y <= p_y && p_y <= Y + H))
            cnt++;
        else if ((p_x - X) * (p_x - X) + (p_y - center_y) * (p_y - center_y) <= H * H / 4)
            cnt++;
        else if ((p_x - X - W) * (p_x - X - W) + (p_y - center_y) * (p_y - center_y) <= H * H / 4)
            cnt++;
    }
    std::cout << cnt;
    return 0;
}