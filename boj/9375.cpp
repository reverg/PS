#include <iostream>
#include <string>
using namespace std;

int main()
{
    string cloth, kind;
    int cases, n;

    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        int result = 1;
        int cnt = 0;
        int arr[30] = {0, };
        string clothes[30];
        for (int i = 0; i < 30; i++)
            clothes[i] = "0";
            
        cin >> n;

        for (int j = 0; j < n; j++)
        {
            cin >> cloth >> kind;

            bool clothExist = false;

            for (int k = 0; k <= cnt; k++)
            {
                if (clothes[k] == kind)
                {
                    arr[k]++;
                    if (clothExist == false)
                        clothExist = true;
                }
            }

            if (clothExist == false)
            {
                clothes[cnt] = kind;
                arr[cnt]++;
                cnt++;
            }
        }

        for (int j = 0; j < cnt; j++)
            result *= (arr[j] + 1);

        cout << result - 1 << endl;
    }
}