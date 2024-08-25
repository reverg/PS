class Solution
{
public:
    int reverse(int x)
    {
        int rev = 0;

        while (x != 0)
        {
            int n = x % 10;
            x /= 10;
                
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && n > 7))
                return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && n < -8))
                return 0;

            rev = rev * 10 + n;
        }

        return rev;
    }
};

/*
(Runtime, Memory) = (100.00%, 35.12%)
overflow가 날 상황인지 미리 체크해줘야 한다. 13~16행 참고.
근데 저렇게 처리해야 하면 INT_MAX와 INT_MIN이 얼만지 알려줘야 되는게 아닌가...
*/