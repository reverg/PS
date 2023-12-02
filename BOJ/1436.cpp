#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int cnt = 0;
    for (int i = 666; cnt<N; i++)
    {
        int k = i;
        bool digit6 = false;
        bool digit66 = false;
        while (k / 100 != 0)
        {
            if (k % 1000 == 666)
            {
                cnt++;
                break;
            }
            
            k /= 10;
        }

        if (cnt == N)
            cout << i;
    }

    return 0;
}