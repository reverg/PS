#include <iostream>
#include <vector>

using namespace std;

int change_mbti_to_code(string input)
{
    int code = 0;
    if (input[0] == 'E')
        code++;
    code <<= 1;

    if (input[1] == 'S')
        code++;
    code <<= 1;

    if (input[2] == 'T')
        code++;
    code <<= 1;

    if (input[3] == 'J')
        code++;

    return code;
}

int get_distance(int c1, int c2)
{
    int comp = c1 ^ c2;
    int count = 0;
    while (comp)
    {
        count += comp & 1;
        comp >>= 1;
    }
    return count;
}

int get_tuple_distance(int c1, int c2, int c3)
{
    int count = 0;
    count += get_distance(c1, c2);
    count += get_distance(c2, c3);
    count += get_distance(c3, c1);
    return count;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        string input;
        int mbti[16] = {0, };
        for (int i = 0; i < n; i++)
        {
            cin >> input;
            int code = change_mbti_to_code(input);
            mbti[code]++;
        }

        if (n >= 33)
        {
            cout << "0\n";
        }
        else
        {
            int c1, c2, c3;
            int min_dist = 10;
            for (int i = 0; i < 16; i++)
            {
                if (mbti[i] > 0)
                {
                    mbti[i]--;
                    for (int j = i; j < 16; j++)
                    {
                        if (mbti[j] > 0)
                        {
                            mbti[j]--;
                            for (int k = j; k < 16; k++)
                            {
                                if (mbti[k] > 0)
                                {
                                    int dist = get_tuple_distance(i, j, k);
                                    min_dist = min(min_dist, dist);
                                }
                            }
                            mbti[j]++;
                        }
                    }
                    mbti[i]++;
                }
            }
            cout << min_dist << '\n';
        }
    }

    return 0;
}