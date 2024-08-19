class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> two_sum_counter;
        for (int n1 : nums1)
            for (int n2 : nums2)
                two_sum_counter[n1 + n2]++;

        int ans = 0;
        for (int n3 : nums3)
        {
            for (int n4 : nums4)
            {
                auto it = two_sum_counter.find(-(n3 + n4));
                if (it != two_sum_counter.end())
                    ans += it->second;
            }
        }

        return ans;
    }
};

/*
(Runtime, Memory) = (97.39%, 38.81%). #1 -> #15 -> #18 -> #454로 이어진다.
늘 그렇듯이 hash를 쓰는 문제. 릿코드에 자주 보이는 기본 유형이니까 외워두자.
n1, n2, n3, n4 다르다는 조건이 없으므로 깔끔하게 모든 조합을 체크해주면 된다.
*/