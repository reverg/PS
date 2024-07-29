class Solution
{
public:
    int romanToInt(string s)
    {
        int num[15] = {
            0,
        };
        int result = 0;

        for (int i = 0; i < s.length(); i++)
        {
            switch (s[i])
            {
            case 'I':
                num[i] = 1;
                break;
            case 'V':
                num[i] = 5;
                break;
            case 'X':
                num[i] = 10;
                break;
            case 'L':
                num[i] = 50;
                break;
            case 'C':
                num[i] = 100;
                break;
            case 'D':
                num[i] = 500;
                break;
            case 'M':
                num[i] = 1000;
                break;
            }
        }
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (num[i] >= num[i + 1])
                result += num[i];
            else
                result -= num[i];
        }
        result += num[s.length() - 1];
        return result;
    }
};