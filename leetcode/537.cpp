class Solution
{
public:
    pair<int, int> stopr(string &str)
    {
        int i = 0;
        string real_str = "";
        string complex_str = "";

        while (str[i] != '+')
            real_str += str[i++];

        i++; // skip '+'

        while (str[i] != 'i')
            complex_str += str[i++];

        return {stoi(real_str), stoi(complex_str)};
    }

    string complexNumberMultiply(string num1, string num2)
    {
        auto [n1r, n1c] = stopr(num1);
        auto [n2r, n2c] = stopr(num2);
        return to_string(n1r * n2r - n1c * n2c) + '+' + to_string(n1r * n2c + n1c * n2r) + 'i';
    }
};

/*
(Runtime, Memory) = (100.00%, 23.58%).
C++은 string이 싫다... STL을 잘 써서 아래 방식으로도 가능.

pair<int, int> stopr(const string &str)
{
    size_t plus_pos = str.find('+');
    size_t i_pos = str.find('i');

    string real_str = str.substr(0, plus_pos);
    string complex_str = str.substr(plus_pos + 1, i_pos - plus_pos - 1);

    return {stoi(real_str), stoi(complex_str)};
}
*/