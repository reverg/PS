#include <iostream>

using namespace std;
string str = "";
int image[64][64];

void compress(int x, int y, int n)
{
    int num = image[x][y];
    bool same = true;

    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (num != image[i][j])
            {
                same = false;
                break;
            }
        }
    }

    if (same)
    {
        str += to_string(num);
    }
    else
    {
        str += '(';
        compress(x, y, n / 2);
        compress(x + n / 2, y, n / 2);
        compress(x, y + n / 2, n / 2);
        compress(x + n / 2, y + n / 2, n / 2);
        str += ')';
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    string input;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        for (int j = 0; j < n; j++)
        {
            image[j][i] = input[j] - '0';
        }
    }

    compress(0, 0, n);

    cout << str;
}