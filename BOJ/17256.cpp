#include <iostream>

using namespace std;

int main()
{
    int ax, ay, az;
    int cx, cy, cz;

    cin >> ax >> ay >> az;
    cin >> cx >> cy >> cz;

    cout << cx - az << ' ' << cy / ay << ' ' << cz - ax << '\n';
}