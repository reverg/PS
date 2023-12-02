#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    bool exist = false;

    for (int j = 1; j < N; j++)
    {
        int sum = j;
        for (int i = j; i != 0; i /= 10)
        {
            sum += i % 10;
        }
        if (sum == N)
        {
            cout << j;
            exist = true;
            break;
        }
    }

    if (exist == false)
        cout << "0";

    return 0;
}