#include <iostream>
#include <set>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string input;
    std::set<std::string> s;
    std::cin >> input;
    std::string part = "";
    for (int i = 0; i < input.size(); i++)
    {
        for (int j = i; j < input.size(); j++)
        {
            part += input[j];
            s.insert(part);
        }
        part = "";
    }

    std::cout << s.size();
}