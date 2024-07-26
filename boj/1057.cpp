#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N, J, H;
    cin >> N >> J >> H;
    if (J > H)
        swap(J, H);

    int round = 1;
    while (true)
    {
        if (J + 1 == H && H % 2 == 0)
            break;

        J = (J + 1) / 2;
        H = (H + 1) / 2;
        round++;
    }

    cout << round << '\n';
}