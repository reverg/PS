#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int A, B, C, D;
    cin >> A >> B >> C >> D;

    cout << stoll(to_string(A) + to_string(B)) + stoll(to_string(C) + to_string(D)) << endl;
}