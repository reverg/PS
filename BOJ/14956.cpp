#include <iostream>

using namespace std;

pair<uint, uint> walk(uint N, uint M)
{
    if (N == 2)
    {
        switch (M)
        {
        case 0:
            return pair(1, 1);
        case 1:
            return pair(1, 2);
        case 2:
            return pair(2, 2);
        case 3:
            return pair(2, 1);
        }
    }

    uint area_size = (N / 2) * (N / 2);
    uint area_num = M / area_size;
    uint left_steps = M % area_size;

    pair<uint, uint> rel_loc = walk(N / 2, left_steps);

    switch (area_num)
    {
    case 0:
        return pair(rel_loc.second, rel_loc.first);
    case 1:
        return pair(rel_loc.first, rel_loc.second + (N / 2));
    case 2:
        return pair(rel_loc.first + (N / 2), rel_loc.second + (N / 2));
    case 3:
        return pair(N + 1 - rel_loc.second, (N / 2) + 1 - rel_loc.first);
    }

    return pair(0, 0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    uint N, M;
    cin >> N >> M;
    pair<uint, uint> loc = walk(N, M - 1);
    cout << loc.first << ' ' << loc.second << '\n';
}