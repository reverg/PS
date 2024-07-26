#include <iostream>
#include <string>

#define r 31
#define M 1234567891

int main()
{
    std::string input = "";
    int dummy = 0;
    std::cin >> dummy >> input;

    unsigned long H = 0;

    for (int i = 0; i < input.length(); i++)
    {
        unsigned long r_sq = 1;
        for (int j = 0; j < i; j++)
        {
            r_sq *= r;
            r_sq %= M;
        }
        H += ((int(input[i]) - 'a' + 1) * r_sq) % M;
        H %= M;
    }

    std::cout << H << std::endl;
}