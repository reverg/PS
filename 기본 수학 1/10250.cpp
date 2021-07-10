#include <iostream>
using namespace std;

int main()
{
    int T;
    int H, W, N;
    int floor, room;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> H >> W >> N;

        floor = N % H;
        if (floor == 0)
            floor = H;
        room = (N - 1) / H + 1;
        cout << floor * 100 + room << endl;
    }

    return 0;
}