#include <iostream>

using namespace std;

long long LH, S, D, L, B;

long long killDay(long long hp, long long gen, long long attack)
{
    return ((hp <= attack) ? 1 : (hp - gen - 1) / (attack - gen) + 1);
}

long long killOrder(long long hp1, long long gen1, long long hp2, long long gen2)
{
    long long d1 = killDay(hp1, gen1, 2 * LH);
    long long rhp1 = hp1 - (2 * LH - gen1) * (d1 - 1);
    if (rhp1 <= LH)
        hp2 -= LH;
    hp2 += d1 * gen2;
    if (hp2 <= gen2)
    {
        return d1;
    }
    else
    {
        long long d2 = killDay(hp2, gen2, 2 * LH);
        return d1 + d2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> LH >> S >> D >> L >> B;

    long long k1 = killOrder(S, L, D, B);
    long long k2 = killOrder(D, B, S, L);

    cout << min(k1, k2);
}