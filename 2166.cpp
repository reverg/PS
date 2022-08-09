#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int N;
    int x_1, y_1, x_2, y_2;

    // Shoelace formula problem
    cin >> N;
    cin >> x_1 >> y_1;
    int x_first = x_1;
    int y_first = y_1;
    double sum;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> x_2 >> y_2;
        sum += (double)x_1 * y_2 / 2;
        sum -= (double)x_2 * y_1 / 2;
        x_1 = x_2;
        y_1 = y_2;
    }
    sum += (double)x_1 * y_first / 2;
    sum -= (double)x_first * y_1 / 2;

    printf("%.1lf", abs(sum));
}