#include <iostream>
#include <string>

int main()
{
    std::string input = "";
    while (true)
    {
        std::cin >> input;
        if (input == "0")
            break;
        bool palindrome = true;
        for (int i = 0; i < input.length() / 2; i++)
        {
            if (input[i] != input[input.length() - i - 1])
            {
                palindrome = false;
                break;
            }
        }
        if (palindrome)
            std::cout << "yes" << std::endl;
        else
            std::cout << "no" << std::endl;
    }
}