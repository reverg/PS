#include <iostream>

using namespace std;

int main()
{
    long long N;
    cin >> N;

    long long euler = N;
    for (long long p = 2; p * p <= N; p++)
    {
        if (N % p == 0)
            euler = euler / p * (p - 1);
        while (N % p == 0)
            N = N / p;
    }

    cout << (N == 1 ? euler : euler / N * (N - 1)) << '\n'; // N이 소수인 경우 처리
}

/*
Euler's phi function
https://ko.wikipedia.org/wiki/%EC%98%A4%EC%9D%BC%EB%9F%AC_%ED%94%BC_%ED%95%A8%EC%88%98
*/