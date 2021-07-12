#include <iostream>
using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;
    bool sosu[1000001]; //sosu[i]에 i 할당
    for (int i = 2; i < 1000001; i++)
        sosu[i] = true;
    sosu[0] = false;
    sosu[1] = false;

    for (int i = 2; i <= 1000; i++)
    {
        if (sosu[i] == true)
        {
            for (int j = 2 * i; j <= 1000000; j += i)
                sosu[j] = false;
        }
    }

    for (int i = M; i <= N; i++)
    {
        if (sosu[i])
            printf("%d\n", i);
    }

    return 0;
}