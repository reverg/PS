class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {
        unordered_map<string, int> counter;
        for (string s : arr)
            counter[s]++;

        for (string s : arr)
        {
            if (counter[s] == 1)
            {
                k--;

                if (k == 0)
                    return s;
            }
        }

        return "";
    }
};

/*
(Runtime, Memory) = (96.95%, 20.16%)
unordered_set을 사용하는 방법도 있는데 이건
중복 처리하기가 살짝 귀찮아서 그냥 map으로 count
해주는게 더 편하다. 시간, 공간복잡도 모두 O(N).
*/