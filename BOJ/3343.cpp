#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    long long N, minCost = LLONG_MAX;
    cin >> N;
    long long cntA, priceA, cntB, priceB;
    cin >> cntA >> priceA >> cntB >> priceB;

    // Swap if B is less cost-effective than A
    if (cntB * priceA > cntA * priceB)
    {
        swap(cntA, cntB);
        swap(priceA, priceB);
    }

    for (int b = 0; b < cntA; ++b)
    {
        long long a = ceil((double)(N - b * cntB) / cntA);

        bool isOver = false;
        if (a < 0)
        {
            a = 0;
            isOver = true;
        }

        minCost = min(minCost, a * priceA + b * priceB);
        if (isOver)
            break;
    }

    cout << minCost << endl;
    return 0;
}
