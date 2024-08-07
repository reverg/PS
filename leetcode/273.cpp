class Solution
{
public:
    string ones(int num)
    {
        switch (num)
        {
        case 1:
            return "One";
        case 2:
            return "Two";
        case 3:
            return "Three";
        case 4:
            return "Four";
        case 5:
            return "Five";
        case 6:
            return "Six";
        case 7:
            return "Seven";
        case 8:
            return "Eight";
        case 9:
            return "Nine";
        default:
            return "";
        }
    }

    string tens(int num)
    {
        switch (num)
        {
        case 2:
            return "Twenty";
        case 3:
            return "Thirty";
        case 4:
            return "Forty";
        case 5:
            return "Fifty";
        case 6:
            return "Sixty";
        case 7:
            return "Seventy";
        case 8:
            return "Eighty";
        case 9:
            return "Ninety";
        default:
            return "";
        }
    }

    string tenSomething(int num)
    {
        switch (num)
        {
        case 10:
            return "Ten";
        case 11:
            return "Eleven";
        case 12:
            return "Twelve";
        case 13:
            return "Thirteen";
        case 14:
            return "Fourteen";
        case 15:
            return "Fifteen";
        case 16:
            return "Sixteen";
        case 17:
            return "Seventeen";
        case 18:
            return "Eighteen";
        case 19:
            return "Nineteen";
        default:
            return "";
        }
    }

    string hundredsToWords(int num)
    {
        string num_str = "";

        int hundred = num / 100;
        int ten = (num / 10) % 10;
        int one = num % 10;

        string hundred_str = ones(hundred);
        if (hundred_str != "")
            num_str += (hundred_str + " " + "Hundred");

        string ten_one_str;
        if (ten == 1)
            ten_one_str = tenSomething(num % 100);
        else
        {
            string ten_str = tens(ten);
            if (ten_str != "")
                ten_one_str += ten_str;

            string one_str = ones(one);
            if (one_str != "")
            {
                if (ten_str != "")
                    ten_one_str += " ";
                ten_one_str += one_str;
            }
        }

        if (ten_one_str != "")
        {
            if (hundred_str != "")
                num_str += " ";
            num_str += ten_one_str;
        }

        return num_str;
    }

    string numberToWords(int num)
    {
        if (num == 0)
            return "Zero";

        string num_str = "";

        int billions = (num / 1000000000) % 1000;
        int millions = (num / 1000000) % 1000;
        int thousands = (num / 1000) % 1000;
        int hundreds = num % 1000;

        string billions_str = hundredsToWords(billions);
        string millions_str = hundredsToWords(millions);
        string thousands_str = hundredsToWords(thousands);
        string hundreds_str = hundredsToWords(hundreds);

        if (billions_str != "")
            billions_str += ((string) " " + "Billion");
        if (millions_str != "")
            millions_str += ((string) " " + "Million");
        if (thousands_str != "")
            thousands_str += ((string) " " + "Thousand");

        num_str += billions_str;
        if (num_str != "" && millions_str != "")
            num_str += " ";
        num_str += millions_str;
        if (num_str != "" && thousands_str != "")
            num_str += " ";
        num_str += thousands_str;
        if (num_str != "" && hundreds_str != "")
            num_str += " ";
        num_str += hundreds_str;

        return num_str;
    }
};

/*
(Runtime, Memory) = (66.96%, 74.16%)
사람을 미치게 하는 슈퍼스타 문제. 코너케이스 잘 만드나 보는 문제인 듯?
처리해야 될 코너케이스들은 아래와 같다.
1. 20 이하의 수들
2. 0
3. 여러 상황에서의 아름다운 띄어쓰기들
1번은 처리했는데 2, 3번을 당했다. tc 꼼꼼히 만드는 연습을 하자.
범위가 2^31-1 이하라 trillion이 나올 일은 없음을 잘 캐치하자.
그와 별개로 영어권 아닌 사람들한테는 영 불편하다. 꼬우면 미국에서 태어났어야...
*/