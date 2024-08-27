class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> char_counter;
        int left = 0;
        int right = 0;

        int res = 0;
        while (right < s.size())
        {
            char r = s[right];
            char_counter[r]++;

            while (char_counter[r] > 1)
            {
                char l = s[left];
                char_counter[l]--;
                left++;
            }

            if (res < right - left + 1)
                res = right - left + 1;

            right++;
        }

        return res;
    }
};

/*
(Runtime, Memory) = (80.13%, 52.06%)
자주 보이는 슬라이딩 윈도우 문제. 시간 O(n), 공간 O(min(m, n))이다.
left, right가 각 원소를 최대 2번씩 거치게 되는데, 중복이 아예 있으면
안됨을 이용하면 1번씩만 거치게 바꿀 수 있다. map에 char의 개수가 아니라
직전 해당 char의 위치를 저장해뒀다가 바로 건너뛰면 된다.
*/