#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    while (1)
    {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
            break;
        bool right = false;

        if (a * a + b * b == c * c)
            right = true;
        else if (a * a + c * c == b * b)
            right = true;
        else if (b * b + c * c == a * a)
            right = true;
        else
            right = false;

        if (right == true)
            cout << "right" << endl;
        else
            cout << "wrong" << endl;
    }

    return 0;
}