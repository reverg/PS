#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int K;
vector<int> coeff;
double true_val;

int A, B, N;
double dx;

double evaluate()
{
    double val = 0;
    double bpow = B, apow = A;
    for (int i = K; i >= 0; i--)
    {
        val += coeff[i] * ((bpow - apow) / (K - i + 1));
        bpow *= B;
        apow *= A;
    }

    return val;
}

double approx(double eps)
{
    double val = 0;
    for (int i = K; i >= 0; i--)
    {
        double f_part = 0;
        for (int j = 0; j <= N - 1; j++)
            f_part += pow(A + j * dx + eps, K - i);
        val += coeff[i] * dx * f_part;
    }

    return val;
}

int main()
{
    cin >> K;
    for (int i = K; i >= 0; i--)
    {
        int c;
        cin >> c;
        coeff.push_back(c);
    }

    cin >> A >> B >> N;
    true_val = evaluate();

    cout.precision(9);

    dx = ((double)B - A) / N;

    double low = 0;
    double high = dx;
    double eps = (low + high) / 2;
    while (true)
    {
        eps = (low + high) / 2;
        double approx_val = approx(eps);

        if (abs(approx_val - true_val) <= 1e-4)
            break;

        if (approx_val > true_val)
            high = eps;
        else
            low = eps;
    }

    cout << eps << '\n';
}

/*
cout.precision(9)로 출력 단위를 길게 맞춰주긴 했는데, 없어도 BOJ에서 오답처리되진 않음.
*/