class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> hashMap;
        for (int k = 0; k < nums.size(); k++)
            hashMap[nums[k]] = k;

        vector<vector<int>> ans;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (nums[i] > 0) // i<j<k triple 만들 예정이라 합 0 불가능ㄴ
                break;

            for (int j = i + 1; j < nums.size() - 1; j++)
            {
                int two_sum = -(nums[i] + nums[j]);
                if (hashMap.count(two_sum) && hashMap.find(two_sum)->second > j)
                    ans.push_back({nums[i], nums[j], two_sum});
                j = hashMap.find(nums[j])->second;
            }
            i = hashMap.find(nums[i])->second;
        }

        return ans;
    }
};

/*
(Runtime, Memory) = (25.03%, 41.56%). #1 -> #454 -> #15 -> #18로 이어진다.
정렬을 안하고 (nums[i], nums[j])의 합을 hash에 넣어 -nums[k]와 비교해보려고 했는데,
중복이 다 제거되어야 해서 조건들을 모두 만족시키려면 꽤나 복잡한 처리 과정이 필요하다.
비교적 간단한 대신 sort를 중간중간 사용하는 방식을 시도했다가 nums={0,0,...,0}에서 TLE.
중간에 nC3개의 합 0짜리 triplet이 생겼고 그걸 sorting하느라 O(N^3 logN)이 되어버렸다.
코드는 아래 참고. 다만 중복되지 않게 만들기 위해 21, 23, 25행에 다소 비직관적인 코드들이
생기긴 했다. hashMap의 value로 가장 뒷 인덱스가 들어감을 인지하면 이해가 빠를 것.
constant가 안 좋은지 같은 O(N^2)인 two pointer 풀이보다 4배쯤 느리다. 메모리는 O(N).

정렬하고 nums[k]에 해당하는 값들을 hash에 넣어둔 뒤, (i,j) 합을 loop를 돌며 구해서
확인하면 좀 더 간단해진다.

[TLE 코드]
    // 1. put all sums of (nums[i], nums[j]) in map
    for (int i = 0; i < nums.size(); i++)
        for (int j = i + 1; j < nums.size(); j++)
            sum_of_two[nums[i] + nums[j]].push_back({i, j});

    // 2. check if -num[k] is in the map
    for (int k = 0; k < nums.size(); k++) {
        vector<pair<int, int>> ij_pairs = sum_of_two[-nums[k]];
        for (auto p : sum_of_two[-nums[k]]) {
            auto [i, j] = p;
            if (i == k || j == k)
                continue;
            vector<int> ijk_triplet = {nums[i], nums[j], nums[k]};
            sort(ijk_triplet.begin(), ijk_triplet.end());
            ans.push_back(ijk_triplet);
        }
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
*/