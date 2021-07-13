#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int dungchi[N][2];
    for (int i = 0; i < N; i++)
    {
        cin >> dungchi[i][0] >> dungchi[i][1];
        cin.get();
    }

    for (int i = 0; i < N; i++)
    {
        int rank = 1;
        for (int j = 0; j < N; j++)
        {
            if (dungchi[j][0] > dungchi[i][0] && dungchi[j][1] > dungchi[i][1])
                rank++;
        }
        cout << rank << " ";
    }
}