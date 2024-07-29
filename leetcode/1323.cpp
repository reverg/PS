class Solution
{
public:
    int maximum69Number(int num)
    {
        int idx = -1;
        int n = num;
        int cnt = 0;
        while (n > 0)
        {
            if (n % 10 == 6)
                idx = cnt;
            cnt++;
            n /= 10;
        }

        if (idx >= 0)
        {
            int pow = 1;
            for (int i = 0; i < idx; i++)
                pow *= 10;

            num += 3 * pow;
        }

        return num;
    }
};