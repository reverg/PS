class Solution
{
public:
    static bool comp(const pair<int, int> &p1, const pair<int, int> &p2)
    {
        return p1.second > p2.second;
    }

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> num_counter;
        for (int num : nums)
            num_counter[num]++;

        vector<pair<int, int>> freq_vec(num_counter.begin(), num_counter.end());
        sort(freq_vec.begin(), freq_vec.end(), comp);

        vector<int> ans;
        for (int i = 0; i < k; i++)
            ans.push_back(freq_vec[i].first);

        return ans;
    }
};

/*
(Runtime, Memory) = (97.90%, 23.96%)
comp를 static으로 선언해야 에러가 안 난다. 화이트보드 코딩에선 괜찮지 않을까...
시간복잡도는 hash table에서 O(N), sorting에 O(NlogN), 벡터에 넣는데 O(K).
공간은 O(N + K)를 쓴다. bucket sort를 쓰면 O(N)에도 풀 수 있는데, nums의 크기가
최대 10만이라 가능한 방법이고 일반적으로 사용하긴 어렵다. 코드는 마지막 참고.
QuickSelect라는 시간 average O(N), worst O(N^2)에 공간 O(N) 방법도 있다고 한다.

// Bucket sort
class Solution {
public:
    vector<int> topKFrequent(const vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int n : nums)
            freq[n]++;

        // Bucket sort on frequency
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto& [key, count] : freq)
            bucket[count].push_back(key);

        vector<int> ans;
        for (int i = bucket.size() - 1; i >= 0; --i) {
            for (int num : bucket[i]) {
                ans.push_back(num);
                if (ans.size() == k)
                    return ans;
            }
        }

        return ans;
    }
};
*/