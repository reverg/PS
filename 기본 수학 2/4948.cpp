#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;

    bool sosu[246913]; //sosu[i]에 i 할당
    for (int i = 2; i < 246913; i++)
        sosu[i] = true;
    sosu[0] = false;
    sosu[1] = false;

    for (int i = 2; i <= sqrt(246913); i++)
    {
        if (sosu[i] == true)
        {
            for (int j = 2 * i; j <= 246913; j += i)
                sosu[j] = false;
        }
    }

    while (1)
    {
        cin >> n;
        int cnt=0;
        if (n == 0)
            break;
        for (int i = n + 1; i <= 2 * n; i++)
        {
            if (sosu[i])
                cnt++;
        }
        cout<<cnt<<"\n";
    }

    return 0;
}