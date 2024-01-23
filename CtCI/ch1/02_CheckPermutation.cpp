#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Solution 1: sort and compare
bool is_permutation_1(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    for (int i = 0; i < str1.length(); i++)
    {
        if (str1[i] != str2[i])
        {
            return false;
        }
    }

    return true;
}

// Solution 2: use counter array
bool is_permutation_2(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;

    int counter[256] = {0};
    for (int i = 0; i < str1.length(); i++)
    {
        counter[str1[i]]++;
    }
    for (int i = 0; i < str2.length(); i++)
    {
        counter[str2[i]]--;
        if (counter[str2[i]] < 0)
            return false;
    }

    return true;
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    cout << is_permutation_2(str1, str2) << endl;
}