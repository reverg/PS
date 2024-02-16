#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

std::string sortChars(std::string s)
{
    std::sort(s.begin(), s.end());
    return s;
}

void sort(std::vector<std::string> &array)
{
    std::unordered_map<std::string, std::vector<std::string>> mapList;

    // Group words by anagram
    for (const auto &s : array)
    {
        std::string key = sortChars(s);
        mapList[key].push_back(s);
    }

    // Convert hash table to array
    int index = 0;
    for (const auto &pair : mapList)
    {
        const auto &list = pair.second;
        for (const auto &t : list)
        {
            array[index] = t;
            index++;
        }
    }
}

int main()
{
    std::vector<std::string> array = {"apple", "banana", "carrot", "ele", "duck", "papel", "tarroc", "cudk", "eel", "lee"};
    sort(array);

    for (const auto &str : array)
    {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    return 0;
}
