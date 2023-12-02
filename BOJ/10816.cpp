#include <iostream>
#include <cstdio>
#include <map>

int main()
{
    std::map<int, int> m;
    int N, M;
    int val;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &val);
        m[val]++;
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &val);
        printf("%d ", m[val]);
    }
    return 0;
}