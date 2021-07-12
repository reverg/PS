#include <iostream>
using namespace std;

int main()
{
    int x1, y1, r1;
    int x2, y2, r2;
    int T;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin.get();
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        int dSquare = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        int rSumSquare = (r1 + r2) * (r1 + r2);
        int rDiffSquare = (r1 - r2) * (r1 - r2);

        if (x1 == x2 && y1 == y2 && r1 == r2)
            cout << "-1" << endl;
        else if (rSumSquare == dSquare || rDiffSquare == dSquare)
            cout << "1" << endl;
        else if (rSumSquare > dSquare && rDiffSquare < dSquare)
            cout << "2" << endl;
        else
            cout << "0" << endl;
    }

    return 0;
}