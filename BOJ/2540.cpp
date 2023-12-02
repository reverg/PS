#include <iostream>
#include <algorithm>

using namespace std;

int K = 0;
int basket[4];
int order[4] = {0, 1, 2, 3};

void print()
{
    cout << basket[0] << ' ' << basket[1] << ' '
         << basket[2] << ' ' << basket[3] << '\n';
}

void moveEgg(int from1, int from2, int to)
{
    basket[order[from1]]--;
    basket[order[from2]]--;
    basket[order[to]] += 2;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int N = 0;
    cin >> K;
    for (int i = 0; i < 4; i++)
        cin >> basket[i];

    while (true)
    {
        print();
        sort(order, order + 4, [](int a, int b)
             { return basket[a] < basket[b]; });
        int sum = basket[order[0]] + basket[order[1]] + basket[order[2]];
        if (sum == 0)
            break;
        if (sum % 2 == 1 || basket[order[1]] == 0)
            moveEgg(2, 3, 0);
        else if (basket[order[0]] + basket[order[1]] >= basket[order[2]])
            moveEgg(1, 2, 3);
        else
            moveEgg(1, 2, 0);
    }
}