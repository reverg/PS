#include <iostream>

using namespace std;

int n;
int perm[11], oper[4];
int largest = -1000000000, smallest = 1000000000;

void cal(int k, int prev)
{
    if (k == n)
    {
        if (prev > largest)
            largest = prev;
        if (prev < smallest)
            smallest = prev;
        return;
    }

    for (int op = 0; op < 4; op++)
    {
        if (oper[op] == 0)
            continue;
        oper[op]--;
        switch (op)
        {
        case 0:
            cal(k + 1, prev + perm[k]);
            break;
        case 1:
            cal(k + 1, prev - perm[k]);
            break;
        case 2:
            cal(k + 1, prev * perm[k]);
            break;
        case 3:
            cal(k + 1, prev / perm[k]);
            break;
        }
        oper[op]++;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> perm[i];
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> oper[i];
    }

    cal(1, perm[0]);
    cout << largest << '\n'
         << smallest;
}