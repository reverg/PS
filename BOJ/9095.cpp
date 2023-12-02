#include <iostream>

int main()
{
    int expression[11] = {0};
    expression[1] = 1, expression[2] = 2, expression[3] = 4;
    for(int i=4; i<11; i++){
        expression[i] = expression[i-1] + expression[i-2] + expression[i-3];
    }

    int T, N;
    std::cin >> T;
    for (int i = 0; i < T; i++)
    {
        std::cin >> N;
        std::cout << expression[N] << std::endl;
    }
}