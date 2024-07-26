#include <iostream>
#include <vector>

using namespace std;

int A, B;

void input()
{
    cin >> A >> B;
}

int change(int start, int target)
{
    int cnt = 1;
    while (target != start)
    {
        if (target < start)
        {
            cnt = -1;
            break;
        }

        if (target % 10 == 1)
        {
            target -= 1;
            target /= 10;
        }
        else if (target % 2 == 0)
        {
            target >>= 1;
        }
        else
        {
            cnt = -1;
            break;
        }
        cnt++;
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    cout << change(A, B) << endl;
}