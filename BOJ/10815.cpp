#include <iostream>
#include <stdio.h>
#include <set>

int main()
{
    std::set<int> s;
    int N, M;
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int val;
        scanf("%d", &val);
        s.insert(val);
    }
    std::cin >> M;
    for (int i = 0; i < M; i++)
    {
        int val;
        scanf("%d", &val);
        if (s.end() != s.find(val))
        {
            printf("1 ");
        }
        else
        {
            printf("0 ");
        }
    }
    return 0;
}