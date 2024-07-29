#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int case_number = 1;
    while (true)
    {
        getline(cin, s);
        if (s == "0")
            break;
        else
            cout << "Case " << case_number++ << ": Sorting... done!\n";
    }
}