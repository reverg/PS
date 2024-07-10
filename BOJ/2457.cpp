#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Flower
{
    int open;
    int close;
};

bool flowerOrder(Flower f1, Flower f2)
{
    if (f1.open != f2.open)
        return f1.open < f2.open;
    else
        return f1.close < f2.close;
}

int main()
{
    int N;
    cin >> N;

    vector<Flower> flowers;
    for (int i = 0; i < N; i++)
    {
        int om, od, cm, cd;
        cin >> om >> od >> cm >> cd;
        flowers.push_back(Flower{om * 100 + od, cm * 100 + cd});
    }

    sort(flowers.begin(), flowers.end(), flowerOrder);

    int ans = 0;
    int t = 301, pos = 0;
    while (t < 1201)
    {
        int next_t = t;
        for (int i = pos; i < N; i++)
        {
            if (flowers[i].open <= t && flowers[i].close > next_t)
            {
                next_t = flowers[i].close;
                pos = i;
            }
            else if (flowers[i].open > t)
                break;
        }

        if (next_t == t)
        {
            ans = 0;
            break;
        }

        t = next_t;
        ans++;
    }

    cout << ans << '\n';
}