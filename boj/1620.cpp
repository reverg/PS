#include <iostream>
#include <cstdio>
#include <map>

int main()
{
    int N, M;
    std::map<std::string, int> m;
    std::string strArr[100001];
    scanf("%d %d", &N, &M);
    char istring[21];
    for (int i = 0; i < N; i++)
    {
        scanf("%s", istring);
        m.insert(std::make_pair(istring, i + 1));
        strArr[i + 1] = istring;
    }
    for (int i = 0; i < M; i++)
    {
        scanf("%s", istring);
        if (m.find(istring) != m.end())
        {
            printf("%d\n", m.find(istring)->second);
        }
        else
        {
            int idx = std::stoi(istring);
            printf("%s\n", strArr[idx].c_str());
        }
    }
    return 0;
}