#include <iostream>
#include <cstdio>
#include <set>
#include <string>

int main()
{
    int N, M;
    int cnt = 0;
    std::set<std::string> s;
    scanf("%d %d", &N, &M);
    std::string istring;
    getline(std::cin, istring);
    for (int i = 0; i < N; i++)
    {
        getline(std::cin, istring);
        s.insert(istring);
    }
    for (int i = 0; i < M; i++)
    {
        getline(std::cin, istring);
        if (s.find(istring) != s.end())
        {
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}